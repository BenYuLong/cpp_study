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
        INFO(LOG_MODULE_SECTION0, "hhhh");
        WARN(LOG_MODULE_SECTION0, "waring");
        ERROR(LOG_MODULE_SECTION0, "error");
        FATAL(LOG_MODULE_SECTION0, "fatal");
        sleep(3);
    }
}

int main()
{
    using namespace std;

    INFO(LOG_MODULE_NULL, "c++ version = %ld", __cplusplus);
    INFO(LOG_MODULE_NULL, "gcc version = %s", __VERSION__);
    INFO(LOG_MODULE_NULL, "gcc major = %d", __GNUC__);
    INFO(LOG_MODULE_NULL, "gcc minor = %d", __GNUC_MINOR__);
    INFO(LOG_MODULE_NULL, "gcc patch = %d", __GNUC_PATCHLEVEL__);
    INFO(LOG_MODULE_NULL, "libstdc++ = %d", __GLIBCXX__);

    string test;

    test += "hell";
    test += " ";
    test += "hello";
    test += "o";

    INFO(LOG_MODULE_NULL, "sendVerify : %s\n", test.c_str());

    pthread_t section0Pthread;
    if(0 != pthread_create(&section0Pthread, nullptr, section0PthreadFun, nullptr))
    {
        cout << "error Pthread create" << endl;
    }

    pthread_join(section0Pthread, nullptr);
}
