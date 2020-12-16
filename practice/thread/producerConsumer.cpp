#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>

class producerConsumer
{
private:

	pthread_mutex_t myLock = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t myCond = PTHREAD_COND_INITIALIZER;

public:
	typedef struct LinkNode
	{
		int data;
		struct LinkNode *next;
	} Node;
	producerConsumer(/* args */);
	~producerConsumer();
	Node *CreatNode(int data);
	void InitLink(Node **head);
	int IsEmpty(Node *head);
	void PushFront(Node *head,int data);
	void PopFront(Node *head,int *data);
	void DisplayLink(Node *head);
	void DestroyLink(Node *head);
	void product_run(Node *head);
	void consumer_run(Node *head);
	void test(void);
};

producerConsumer::producerConsumer(/* args */)
{
}

producerConsumer::~producerConsumer()
{
}

producerConsumer::Node *producerConsumer::CreatNode(int data)
{
	Node *NewNode=(Node *)malloc(sizeof(Node));
	if(NULL == NewNode)
	{
		perror("malloc");
		return NULL;
	}
	NewNode->data=data;
	NewNode->next=NULL;
	return NewNode;
}
 
void producerConsumer::InitLink(Node **head)
{
	*head=CreatNode(0);
}
 
int producerConsumer::IsEmpty(Node *head)
{
	assert(head);
	if(head->next)
		return 0;    //not empty
	else
		return 1;    //empty
}
 
void producerConsumer::PushFront(Node *head,int data)
{
	assert(head);
	Node *NewNode=CreatNode(data);
	NewNode->next=head->next;
	head->next=NewNode;
}
 
void producerConsumer::PopFront(Node *head,int *data)
{
	assert(data);
	assert(head);
	if(IsEmpty(head))
	{
		printf("empty link\n");
		return ;
	}
	Node *del=head->next;
	*data=del->data;
	head->next=del->next;
	free(del);
	del=NULL;
}
 
void producerConsumer::DisplayLink(Node *head)
{
	assert(head);
	Node *cur=head->next;
	while(cur)
	{
		printf("%d ",cur->data);
		cur=cur->next;
	}
	printf("\n");
}
 
void producerConsumer::DestroyLink(Node *head)
{
	int data=0;
	assert(head);
	while(!IsEmpty(head))
	{
		PopFront(head,&data);
	}
	free(head);
}
 
void producerConsumer::product_run(Node *head)
{
	int data=0;
	while(1)
	{
		usleep(100000);
		data=rand()%1000;
		pthread_mutex_lock(&myLock);
		PushFront(head,data);
		pthread_mutex_unlock(&myLock);
		pthread_cond_signal(&myCond);
		printf("product is done,data=%d\n",data);
	}
}
 
void producerConsumer::consumer_run(Node *head)
{
	int data=0;
	while(1)
	{
		pthread_mutex_lock(&myLock);
		while(IsEmpty(head))
		{
			pthread_cond_wait(&myCond,&myLock);
		}
		PopFront(head,&data);
		pthread_mutex_unlock(&myLock);
		printf("consumer is done,data=%d\n",data);
	}
}
producerConsumer *model = new producerConsumer();

void *productTask(void *args)
{
	producerConsumer::Node *head = (producerConsumer::Node *)args;
	model->product_run(head);
	return nullptr;
}
void *consumerTask(void *args)
{
	producerConsumer::Node *head = (producerConsumer::Node *)args;
	model->consumer_run(head);
	return nullptr;
}

int main(void)
{
	producerConsumer::Node *head = NULL;
	model->InitLink(&head);
	pthread_t tid1;
	pthread_t tid2;
	pthread_create(&tid1, NULL, productTask, head);
	pthread_create(&tid2, NULL, consumerTask, head);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	model->DestroyLink(head);
	// pthread_mutex_destroy(&model->myLock);
	// pthread_cond_destroy(&model->myCond);
	return 0;
}