#ifndef __ANSLABS_OBJECT_HPP__
#define __ANSLABS_OBJECT_HPP__

#include "cap.hpp"

namespace ANSlabs {

template <class Type, class Allocator>
class Structor : protected Allocator {
public:
  template <typename... Args>
  Type * New(Args... args);
  
  void Delete(Type * x);
};

}

#include "structor-public.hpp"

#endif
