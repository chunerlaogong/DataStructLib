/***************************
 * 智能指针为了解决内存泄漏问题，实现智能指针需要符合下面三点要求：
 *  1.智能指针是指生命周期结束后主动释放堆空间
 *  2.一片堆空间最多只能由一个指针标识
 *  3.杜绝指针运算和指针比较
 * 智能指针的设计方案：
 *  1.通过类模板描述指针行为(能够定义不同类型的指针)
 *  2.重载指针特征操作符(*和->)(利用对象模拟原生指针的行为)
 *  注意:
 *  1.智能指针只能用来指向堆空间中的单个对象变量，而不能指向数组
 ***************************/
#ifndef SMART_POINTER_H
#define SMART_POINTER_H
#include <iostream>
#include "Object.h"
using namespace std;
namespace YJDLib
{
template <typename T>
class SmartPointer: public Object      //智能指针类模板
{
  protected:
    T *mPointer;

  public:
    SmartPointer(T* p = NULL)
    {
        mPointer = p;
    }
    SmartPointer(const SmartPointer<T>& obj)
    {
        mPointer = obj.mPointer;
        const_cast<SmartPointer<T>& >(obj).mPointer = NULL;
    }
    SmartPointer<T> &operator=(const SmartPointer<T>& obj)      //重载赋值操作符
    {
        if (this != &obj)
        {
            delete mPointer;
            mPointer = obj.mPointer;
            const_cast<SmartPointer<T>& >(obj).mPointer = NULL;
        }
        return *this;
    }
    T *operator->()
    {
        return mPointer;
    }
    T &operator*()
    {
        return *mPointer;
    }
    bool isNull()
    {
        return (mPointer == NULL);
    }
    T *getPointer()
    {
        return mPointer;
    }
    ~SmartPointer()
    {
        delete mPointer;
    }
};
};

#endif //SMART_POINTER_H
