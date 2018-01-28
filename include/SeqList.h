#ifndef SEQLIST_H
#define SEQLIST_H

#include "List.h"
#include "Exception.h"
namespace YJDLib
{
template <typename T>
class SeqList : public List<T>
{
  protected:
    T *mArray;   //顺序存储空间
    int mLength; //当前线性表的长度
  public:
    bool insert(int i, const T &e)
    {
        bool ret = ((0 <= i) && (i <= mLength));
        ret = ret && (mLength < capacity());
        if (ret)
        {
            for( int p = mLength -1; p >= i; p--)
            {
                mArray[p + 1] = mArray[p];
            }
            mArray[i] = e;
            mLength++;
        }
        return ret;
    }
    bool remove(int i)
    {
        bool ret = ((0 <= i) && (i <= mLength));
        if (ret)
        {
            for( int p = i; p <= mLength -1; p++)
            {
                mArray[p] = mArray[p+1];
            }
            mLength--;
        }
        return ret;
    }
    bool set(int i, const T &e)
    {
        bool ret = ((0 <= i) && (i <= mLength));
        if(ret)
        {
            mArray[i] = e;
        }
        return ret;
    }
    bool get(int i, T &e) const
    {
        bool ret = ((0 <= i) && (i <= mLength));
        if(ret)
        {
            e = mArray[i];
        }
        return ret;
    }
    /*查找操作，成功返回元素的下标，失败返回-1*/
    int find(const T& e) const
    {
        int ret = -1;
        for(int i = 0; i < mLength; i++)
        {
            if(mArray[i] == e)
            {
                ret = i;
                break;
            }
        }
        return ret;
    }
    int length() const
    {
        return mLength;
    }
    void clear()
    {
        mLength = 0;
    }
    //顺序存储线性表的数组访问方式
    T& operator [](const int i)
    {
        bool ret = ((0 <= i) && (i < mLength));
        if(ret)
        {
            return mArray[i];
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is not invalid...");
        }
    }
    T operator [](const int i)const
    {
        cout << "const" << endl;
        return (const_cast<SeqList<T>& >(*this))[i];
    }
    //顺序存储空间的容量
    virtual int capacity() = 0;
};
};

#endif