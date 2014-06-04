#include <cassert>

namespace ANSlabs {

#define _RAW_TEMPLATE_ template <size_t MaxCount, size_t Element>
#define _RAW_NAME_ Raw<MaxCount, Element>

_RAW_TEMPLATE_
_RAW_NAME_::Raw() : count(0), dataStart(NULL), dataUsed(0) {
}

_RAW_TEMPLATE_
_RAW_NAME_::~Raw() {
  if (dataStart) delete dataStart;
}

_RAW_TEMPLATE_
void * _RAW_NAME_::AllocBuf() {
  if (!dataStart) dataStart = new uint8_t[Element * MaxCount];
  
  if (count) {
    return buffers[--count];
  }
  
  if (dataUsed < MaxCount * Element) {
    void * buf = (void *)(dataStart + dataUsed);
    dataUsed += Element;
    return buf;
  }
  
  return NULL;
}

_RAW_TEMPLATE_
void _RAW_NAME_::FreeBuf(void * buf) {
  assert(count < MaxCount);
  buffers[count++] = buf;
}

_RAW_TEMPLATE_
size_t _RAW_NAME_::CountAllocated() {
  return (dataUsed / Element) - count;
}

_RAW_TEMPLATE_
size_t _RAW_NAME_::CountFree() {
  return (MaxCount - dataUsed / Element) + count;
}

#undef _RAW_TEMPLATE_
#undef _RAW_NAME_

}
