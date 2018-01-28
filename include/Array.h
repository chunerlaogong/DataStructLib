#ifndef ARRAY_H
#define ARRAY_H
/***********************************
 * Array抽象类的设计要求:
 *  1.存储空间的大小和位置由子类完成
 *  2.重载数组操作符，判断下标是否合法
 *  3.提供数组长度的抽象访问函数
 *  4.提供数组对象间的复制操作
 * 
 * 
***********************************/
#include "Object.h"
#include "Exception.h"
namespace YJDLib
{
template <typename T> 
class Array : public Object
{
    protected:
      T*  mArray;
    public:
      virtual bool set(int i, const T& e)
      {
          bool ret = (0 <= i) && ( i < length());
          if(ret)
          {
            mArray[i] = e;
          }
          return ret;
      }
      virtual bool get(int i, T& e)
      {
        bool ret = (0 <= i) && ( i < length());
          if(ret)
          {
             e = mArray[i];
          }
          return ret;
      }
      //数组访问操作符
      T& operator[] (int i)
      {
          if((0 <= i) && ( i < length()))
          {
            return mArray[i];
          }
          else
          {
              THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is not aviable...");
          }
      }
      T operator[](int i) const
      {
        return (const_cast<Array<T>&>(*this))[i];
      }
      virtual int length() const = 0;
};
};

#endif   //ARRAY_H