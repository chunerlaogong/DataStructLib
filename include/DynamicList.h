#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H
#include "Exception.h"
#include "SeqList.h"
namespace YJDLib
{
template <typename T>
class DynamicList : public SeqList<T>
{
  protected:
    int mCapacity; //顺序存储空间
  public:
    DynamicList(int capacity)
    {
        this->mArray = new T[capacity];
        if (this->mArray)
        {
            this->mLength = 0;
            this->mCapacity = capacity;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to create dynamiclist object...");
        }
    }
    int capacity() 
    {
        return mCapacity;
    }
    //重置顺序存储空间的大小
    void resize(int capacity)
    {
        if (mCapacity != capacity)
        {
            T *array = new T[capacity];
            if (array)
            {
                int length = (this->mLength < capacity ? this->mLength : capacity);
                for (int i = 0; i < length; i++)
                {
                    array[i] = this->mArray[i];
                }
                T *temp = this->mArray;
                this->mArray = array;
                this->mLength = length;
                this->mCapacity = capacity;
                delete[] temp;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to create dynamiclist object...");
            }
        }
    }
    ~DynamicList()
    {
        delete[] this->mArray;
    }
};
};

#endif  //DYNAMIC_LIST_H