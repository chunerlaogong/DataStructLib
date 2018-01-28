#include "Object.h"
namespace YJDLib
{
void *Object::operator new(size_t size) throw()
{
    cout << "void *Object::operator new: " << size << endl;
    return malloc(size);
}
void Object::operator delete(void *p)
{
    cout << "Object::operator delete:" << p << endl;
    free(p);
}
void *Object::operator new[](size_t size) throw()
{
    cout << "*Object::operator new[]" << endl;
    return malloc(size);
}
void Object::operator delete[](void *p)
{
    cout << "Object::operator delete[]" << endl;
    free(p);
}
Object::~Object()
{
}
};

