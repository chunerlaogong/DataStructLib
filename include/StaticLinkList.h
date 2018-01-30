#ifndef STATIC_LINK_LIST_H
#define STATIC_LINK_LIST_H
#include "LinkList.h"
namespace YJDLib
{
template <typename T, int N>
class StaticLinkList : public LinkList<T>
{
  private:
  protected:
    typedef typename LinkList<T>::Node Node;
    unsigned char m_space[sizeof(Node) * N];
    struct SNode: public Node
    {
        void* operator new(size_t size, void* location)
        {
            (void)size;
            return location;
        }
    };
    int m_used[N];

  public:
    StaticLinkList()
    {
        for(int i = 0; i < N; i++)
        {
            m_used[i] = 0;
        }
    }
    int capacity()
    {
        return N;
    }
    SNode* create()
    {
        SNode* ret = NULL;
        for(int i = 0 ; i < N; i++)
        {
            if(!m_used[i])
            {
                ret = reinterpret_cast<SNode *>(m_space) + i;
                ret = new(ret)SNode();    //调用构造函数
                m_used[i] = 1;
                break;
            }
        }
        return ret;

    }
    void destroy(Node* pn)
    {
          SNode* space = reinterpret_cast<SNode *>(m_space);
          SNode* psn = dynamic_cast<SNode *>(pn);
          for(int i = 0; i < N; i++)
          {
              if(psn == (space + i))
              {
                  m_used[i] = 0;
                  psn->~SNode();
              }
          }
    }
    ~StaticLinkList()   //析构函数和构造函数调用函数是不会发生多态的，不管是直接或者间接调用，都是调用的当前类中函数的实现
    {
        this->clear();    //clear调用当前类中的destroy()
    }
};
};

#endif //STATIC_LINK_LIST_H
