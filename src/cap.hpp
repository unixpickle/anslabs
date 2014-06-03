#ifndef __ANSLABS_CAP_HPP__
#define __ANSLABS_CAP_HPP__

#include "raw.hpp"

namespace ANSlabs {

template <size_t MaxCount, size_t Element>
class Cap : public Raw<MaxCount, Element> {
public:
  typedef Raw<MaxCount, Element> super;
  
  Cap();
  ~Cap();
  
  void * AllocBuf();
  void FreeBuf(void *);
  
  size_t CountAllocated();

protected:
  size_t externalCount;
};

}

#include "cap-public.hpp"

#endif
