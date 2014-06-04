#include <new>

namespace ANSlabs {

template <class Type, class Allocator>
template <typename... Args>
Type * Structor<Type, Allocator>::New(Args... args) {
  void * buf = this->AllocBuf();
  if (!buf) return NULL;
  return new(buf) Type(args...);
}

template <class Type, class Allocator>
void Structor<Type, Allocator>::Delete(Type * x) {
  x->~Type();
  this->FreeBuf((void *)x);
}

}
