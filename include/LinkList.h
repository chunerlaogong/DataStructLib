#ifndef LINK_LIST_H
#define LINK_LIST_H

/****************************************************
 * 顺序存储结构线性表的最大问题是:
 *  1.插入和删除需要移动大量的元素
 * 基于链式存储的结构的线性表中，每个结点都包含数据域和指针域:
 *  1.数据域:存储数据本身
 *  2.指针域:存储相邻节点的地址
 * 基于链式存储的结构的线性表中简称链表,主要包含以下几种类型:
 *  1.单链表:每个节点只包换后继节点的地址信息
 *  2.循环链表:单链表中的最后一个节点的直接后继为第一个节点
 *  3.双向链表:单链表中的节点包含直接前驱和直接后继的地址信息
 * 链表中的基本概念:
 *  1. 头节点:链表中的辅助结点，包含指向第一个数据元素的指针
 *  2. 数据节点:链表中代表数据元素的节点，表现形式为:(数据元素, 地址)
 *  3. 尾节点:链表中的最后一个数据节点，包含的地址信息为空
 * 单链表的遍历：
 *  1.改进之前时间复杂度为O(n2)
 *  2.改进之后时间复杂度为线性的O(n)
 *  3.在单链表中定义游标变量，通过游标变量mCurrent提高效率,游标变量相关
 *    成员函数相互依赖相互配合的关系(move()/next()/end()/current())
 * 封装节点的创建和删除操作：
 *  1.提供了create()和destroy()两个成员函数，有利于增强扩展性
 * ******************************************************/

#include "Object.h"
#include "List.h"
namespace YJDLib
{
template <typename T>
class LinkList : public List<T>
{
  protected:
    //定义Node节点(C++中的struct和C中的struct完全不一样，可以用来定义一个类，C++中的struct和class的区别在于struct中默认的成员是公有的，class的默认成员是私有的)
    struct Node : public Object
    {
        T value;
        Node *next;
    };
    //Node  mHeader;
    //这样定义为了防止定义头结点的时候调用构造函数出错,public Object必须要, 不然内存布局不一样,会报段错误
    mutable struct: public Object
    { 
        char reserved[sizeof(T)];
        Node *next;
    } mHeader;
    int mLength;
    int mStep;
    Node* mCurrent;

    Node* position(int i) const
    {
        Node* ret = reinterpret_cast<Node *>(&mHeader);
        for(int j = 0; j < i; j++)
        {
            ret = ret->next;
        }
        return ret;
    }
    virtual Node* create()
    {
        return new Node();
    }
    virtual void destroy(Node* pn)
    {
        delete pn;
    }
  public:
    LinkList()
    {
        mHeader.next = NULL;
        mLength = 0;
        mStep = 1;
        mCurrent = NULL;
    }
    bool insert(const T &e)
    {
        bool ret = insert(this->mLength, e);
        return ret;
    }
    bool insert(int i, const T &e)
    {
        bool ret = (0 <= i) && (i <= mLength);
        if (ret)
        {
            Node *node = create();
            if (node)
            {
                Node *current = position(i);
                node->value = e;
                node->next = current->next;
                current->next = node;
                this->mLength++;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to insert new element... ");
            }
        }
        return ret;
    }
    bool remove(int i)
    {
        bool ret = (0 <= i) && (i < mLength);
        if (ret)
        {
            Node *current = position(i);
            Node *toDel = current->next;
            if(mCurrent == toDel)
            {
                mCurrent = toDel->next;
            }
            current->next = toDel->next;
            mLength--;
           // delete toDel;
            destroy(toDel);
        }
        return ret;
    }
    int find(const T& e)const
    {
        int ret = -1;
        for(int i = 0; i < mLength; i ++)
        {
            Node* node = mHeader.next;
            int n = 0;
            while(node)
            {
                if(node->value == e)
                {
                    ret = n;
                    break;
                }
                else
                {
                    node = node->next;
                    n++;
                }
            }
        }
        return ret;
    }
    bool set(int i, const T &e)
    {
        bool ret = (0 <= i) && (i < mLength);
        if (ret)
        {
            position(i)->next->value = e;
        }
        return ret;
    }

    T get(int i) const
    {
        T ret;
        if (get(i, ret))
        {
            return ret;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Invalid parameter i to get element ... ");
        }
    }
    bool get(int i, T &e) const //此处加const表示该函数内不能修改任何成员变量的值
    {
        bool ret = (0 <= i) && (i < mLength);
        if (ret)
        {
            e = position(i)->next->value;
        }
        return ret;
    }
    int length() const
    {
        return this->mLength;
    }
    void clear()
    {
        while (this->mHeader.next)
        {
            Node *toDel = this->mHeader.next;
            this->mHeader.next = toDel->next;   
            this->mLength--;
           // delete toDel;
           destroy(toDel);
        }
    }
    /*i:移动的目标位置，
      step:每次移动的节点数，默认每次移动一个节点
    */
    bool move(int i, int step = 1)
    {
        bool ret = (0 <= i) && (i < mLength) && (step > 0);
        if(ret)
        {
            mCurrent = position(i)->next;
            mStep = step;
        }
        return ret;
    }
    bool end()
    {
        return (mCurrent == NULL);
    }
    T current()
    {
        if(!end())
        {
            return mCurrent->value;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "No value at current position ... ");
        }
    }
    bool next()
    {
        int i = 0;
        while( (i < mStep) && (!end()))
        {
            mCurrent = mCurrent->next;
            i++;
        }
        return (i == mStep);
    }

    ~LinkList()
    {
        clear();
    }
};
};

#endif //LINK_LIST_H