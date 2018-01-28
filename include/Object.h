/**************************************
 * 
 * 这里创建一个顶层父类是为了增加代码的可移植性
 * 例如在不同的C++编译器中new失败返回的结果是完
 * 全不同的，所以导致程序在有的编译中编译出来就
 * 无法执行
 * 
 * 
 * 
 * 
 * **********************************/
#ifndef OBJECT_H
#define OBJECT_H
#include <cstdlib>
#include <iostream>
using namespace std;
namespace YJDLib
{
class Object   //Object类为纯虚父类，所有继承该类的子类都能进行动态类型识别
{
  public:
    void *operator new(size_t size) throw();    //函数末尾加上throw(),表明该函数不会抛出任何异常
    void operator delete(void *p);
    void *operator new[](size_t size) throw();
    bool operator == (const Object& obj);
    bool operator != (const Object& obj);
    void operator delete[](void *p);
    virtual ~Object() = 0;
};
};

#endif //OBJECT_H