#ifndef LIST_H
#define LIST_H
/***********************************
 * 线性表:是指相同数据类型元素的有序排列
 * 线性表应该支持以下操作：
 *  1.将元素插入线性表
 *  2.将元素从线性表中删除
 *  3.获取目标位置元素的值
 *  4.修改目标位置元素的值
 *  5.获取线性表的长度
 *  5.清空线性表
 * 线性表在程序中表现为一种特殊的数据类型
 * 线性表在C++中表现为抽象类
 * **********************************/
namespace YJDLib
{
template <typename T>
class List : public Object
{
public:
    virtual bool insert(int i, const T& e ) = 0;
    virtual bool remove(int i) = 0;
    virtual bool set(int i, const T& e) = 0;
    virtual bool get(int i, T& e) const = 0;
    virtual int length() const = 0;
    virtual bool clear() = 0;
};



};




#endif