#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "Object.h"
using namespace std;
namespace YJDLib
{
#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))
class Exception : public Object
{
  protected:
    char *mMessage;
    char *mLocation;
    void init(const char *message, const char *file, int line);

  public:
    Exception(const char *message);
    Exception(const char *file, int line);
    Exception(const char *message, const char *file, int line);
    Exception(const Exception &e);
    Exception & operator=(const Exception &e);
    virtual const char *message() const;
    virtual const char *location() const;
    virtual ~Exception(); //定义纯函数的类为抽象类，抽象类不能定义为对象
};
class ArithmeticException : public Exception     //计算异常
{
  public:
    ArithmeticException():Exception(NULL){}
    ArithmeticException(const char *message): Exception(message){}      
    ArithmeticException(const char *message, int line):Exception(message, line){}
    ArithmeticException(const char *message, const char *file, int line): Exception(message, file, line){}
    ArithmeticException(const ArithmeticException& e): Exception(e){} 

    ArithmeticException& operator = (ArithmeticException& e)
    {
        Exception::operator=(e);
        return *this;
    }

};
class NullPointerException : public Exception   //空指针异常
{
  public:
    NullPointerException():Exception(NULL){}
    NullPointerException(const char *message): Exception(message){}      
    NullPointerException(const char *message, int line):Exception(message, line){}
    NullPointerException(const char *message, const char *file, int line): Exception(message, file, line){}
    NullPointerException(const NullPointerException& e): Exception(e){} 

    NullPointerException& operator = (NullPointerException& e)
    {
        Exception::operator=(e);
        return *this;
    }

};
class IndexOutOfBoundsException : public Exception   //越界异常
{
  public:
    IndexOutOfBoundsException():Exception(NULL){}
    IndexOutOfBoundsException(const char *message): Exception(message){}      
    IndexOutOfBoundsException(const char *message, int line):Exception(message, line){}
    IndexOutOfBoundsException(const char *message, const char *file, int line): Exception(message, file, line){}
    IndexOutOfBoundsException(const IndexOutOfBoundsException& e): Exception(e){} 

    IndexOutOfBoundsException& operator = (IndexOutOfBoundsException& e)
    {
        Exception::operator=(e);
        return *this;
    }

};
class NoEnoughMemoryException : public Exception   //内存不足异常
{
  public:
    NoEnoughMemoryException():Exception(NULL){}
    NoEnoughMemoryException(const char *message): Exception(message){}      
    NoEnoughMemoryException(const char *message, int line):Exception(message, line){}
    NoEnoughMemoryException(const char *message, const char *file, int line): Exception(message, file, line){}
    NoEnoughMemoryException(const NoEnoughMemoryException& e): Exception(e){} 

    NoEnoughMemoryException& operator = (NoEnoughMemoryException& e)
    {
        Exception::operator=(e);
        return *this;
    }

};
class InvalidParameterException : public Exception   //参数错误异常
{
  public:
    InvalidParameterException():Exception(NULL){}
    InvalidParameterException(const char *message): Exception(message){}      
    InvalidParameterException(const char *message, int line):Exception(message, line){}
    InvalidParameterException(const char *message, const char *file, int line): Exception(message, file, line){}
    InvalidParameterException(const InvalidParameterException& e): Exception(e){} 

    InvalidParameterException& operator = (InvalidParameterException& e)
    {
        Exception::operator=(e);
        return *this;
    }

};
class InvalidOperationException : public Exception   //操作错误异常
{
  public:
    InvalidOperationException():Exception(NULL){
        cout << "InvalidOperationException" <<endl;
    }
    InvalidOperationException(const char *message): Exception(message){}      
    InvalidOperationException(const char *message, int line):Exception(message, line){}
    InvalidOperationException(const char *message, const char *file, int line): Exception(message, file, line){}
    InvalidOperationException(const InvalidOperationException& e): Exception(e){} 

    InvalidOperationException& operator = (InvalidOperationException& e)
    {
        Exception::operator=(e);
        return *this;
    }

};
};

#endif //EXCEPTION_H