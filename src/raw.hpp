#ifndef __ANSLABS_RAW_H__
#define __ANSLABS_RAW_H__

#include <cstddef>
#include <cstdint>

namespace ANSlabs {

template <size_t MaxCount, size_t Element>
class Raw {
public:
  static_assert(MaxCount > 0, "ANSlab::Raw cannot contain 0 elements");
  static_assert(Element > 0, "ANSlab::Raw cannot contain empty elements");
  
  Raw();
  ~Raw();
  
  void * AllocBuf();
  void FreeBuf(void *);
  
  size_t CountAllocated();
  size_t CountFree();
  
protected:
  void * buffers[MaxCount];
  size_t count;
  
  uint8_t * dataStart;
  size_t dataUsed;
};

}

#include "raw-public.hpp"

#endif
