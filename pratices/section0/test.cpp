/**
 * @file test.cpp
 * @brief 
 * @author BenYuLong 
 * @date 2020/09/29
 */
#include <pthread.h>
#include <unistd.h>

#include "common.hpp"

void *section0PthreadFun(void *ptr)
{
    using namespace std;

    while(true)
    {
        INFO(LOG_MODULE_SECTION0, "hhhh\n");
        WARN(LOG_MODULE_SECTION0, "waring\n");
        ERROR(LOG_MODULE_SECTION0, "error\n");
        FATAL(LOG_MODULE_SECTION0, "fatal\n");
        sleep(3);
    }
}

int main()
{
    using namespace std;

    INFO(LOG_MODULE_NULL, "c++ version = %ld\n", __cplusplus);
    INFO(LOG_MODULE_NULL, "gcc version = %s\n", __VERSION__);
    INFO(LOG_MODULE_NULL, "gcc major = %d\n", __GNUC__);
    INFO(LOG_MODULE_NULL, "gcc minor = %d\n", __GNUC_MINOR__);
    INFO(LOG_MODULE_NULL, "gcc patch = %d\n", __GNUC_PATCHLEVEL__);
    INFO(LOG_MODULE_NULL, "libstdc++ = %d\n", __GLIBCXX__);

    pthread_t section0Pthread;
    if(0 != pthread_create(&section0Pthread, nullptr, section0PthreadFun, nullptr))
    {
        cout << "error Pthread create" << endl;
    }

    pthread_join(section0Pthread, nullptr);
}
