#include "Exception.h"

namespace YJDLib
{

void Exception::init(const char *message, const char *file, int line)
{

    if (message)
        mMessage = (message ? strdup(message) : NULL); //strdup函数 复制一份message的信息到堆空间，mMessage指向这片堆空间
    if (file)
    {
        char mline[16] = {0};
        sprintf(mline, "%d", line);
        mLocation = static_cast<char *>(calloc(1, strlen(file) + strlen(mline) + 2));
        if (mLocation)
        {
            strcpy(mLocation, file);
            strcat(mLocation, ":");
            strcat(mLocation, mline);
        }
    }
    else
    {
        mLocation = NULL;
    }
}
Exception::Exception(const char *message)
{
    init(message, NULL, 0);
}
Exception::Exception(const char *file, int line)
{
    init(NULL, file, line);
}
Exception::Exception(const char *message, const char *file, int line)
{
    init(message, file, line);
}
Exception::Exception(const Exception &e)
{
    mMessage = strdup(e.mMessage);
    mLocation = strdup(e.mLocation);
}
Exception &Exception::operator=(const Exception &e)
{
    if (this != NULL)
    {
        free(mMessage);
        mMessage = strdup(e.mMessage);
        mLocation = strdup(e.mLocation);
    }
    return *this;
}
/************************************************
 * 函数末尾加const关键字有两个作用：
 *  1.void func()和void func() const 是可以形成重载的，
 * 当obj调用func函数obj.func(),如果obj是const对象,则
 * 调用void func() const函数
 *  2.把隐藏着的默认的this指针参数，改成const类型,例如
 * void func()会变编译器编译成void func(T* this),如果
 * 加了const则会被编译成void func(const T* this),
 * 
 * 
 * 
 * 
 * **********************************************/
const char *Exception::message() const
{
    return mMessage;
}
const char *Exception::location() const
{
    return mLocation;
}
Exception::~Exception()
{
    free(mMessage);
    free(mLocation);
}
};
