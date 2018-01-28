#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "SeqList.h"
namespace YJDLib
{
template <typename T, int N>
class StaticList : public SeqList<T>
{
  protected:
    T mSpace[N]; //指定存储空间大小
  public:
    StaticList()
    {
        this->mArray = mSpace;
        this->mLength = 0;
    }
    int capacity()
    {
        return N;
    }
};
};

#endif