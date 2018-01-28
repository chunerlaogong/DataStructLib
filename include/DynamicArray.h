#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include "Object.h"
#include "Array.h"
#include "Exception.h"
namespace YJDLib
{
template <typename T>
class DynamicArray : public Array<T>
{
  protected:
    int mLength;
    T* copy(T* array, int length, int newLength)
    {
        T* ret = new T[newLength];
        if( ret )
        {
            int size = (length < newLength) ? length : newLength;
            for(int i = 0; i < size; i++)
            {
                ret[i] = array[i];
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to copy object...");
            ret = NULL;
        }
        return ret;
    }
    void update(T* array, int length)
    {
        if(array)
        {
            T* temp = this->mArray;
            this->mArray = array;
            this->mLength = length;
            delete[] temp;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to update object...");
        }
    }
    void init(T* array, int length)
    {
        if(array)
        {
            this->mArray = array;
            this->mLength = length;
        }
        else
        {
             THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicArray object...");
        }
    }
  public:
    DynamicArray(int length)
    {
        init(new T[length], length);
    }
    DynamicArray(const DynamicArray<T> &obj)
    {
        init(copy(obj.mArray, obj.mLength), obj.mLength);
    }
    DynamicArray<T> &operator = (const DynamicArray<T> &obj)
    {
        if (this != &obj)
        {
            update(copy(obj.mArray, obj.mLength, obj.mLength), obj.mLength);
        }
        return *this;
    }
    int length() const
    {
        return this->mLength;
    }
    void resize(int length)
    {
         if(this->mLength != length)
         {
             update(copy(this->mArray, this->mLength, length), length);
         }
    }
    ~DynamicArray()
    {
        delete[] this->mArray;
    }
};
};

#endif //DYNAMIC_ARRAY_H