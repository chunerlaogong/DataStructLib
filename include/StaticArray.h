#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H
/**************************************
 * StaticArray设计要求:
 *  1.封装原生数组
 *  2.使用模板参数决定数组大小
 *  3.实现函数length()返回数组长度
 *  4.拷贝构造和赋值操作
 * 
***************************************/
#include "Array.h"
namespace YJDLib
{
template <typename T, int N>
class StaticArray : public Array<T>
{
  protected:    
    T mSpace[N];

  public:
    StaticArray()
    {
        this->mArray = mSpace;
    }
    StaticArray(const StaticArray<T, N> &obj)
    {
        this->mArray = mSpace;
        for (int i = 0; i < N; i++)
        {
            mSpace[i] = obj.mSpace[i];
        }
    }
    StaticArray<T, N>& operator=(const StaticArray<T, N>& obj)
    {
        if (this != &obj)
        {
            for (int i = 0; i < N; i++)
            {
                this->mSpace[i] = obj.mSpace[i];
            }
        }
        return *this;
    }
    int length() const
    {
        return N;
    }
};
};

#endif //STATIC_ARRAY_H