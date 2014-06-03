namespace ANSlabs {

#define _CAP_TEMPLATE_ template <size_t MaxCount, size_t Element>
#define _CAP_NAME_ Cap<MaxCount, Element>

_CAP_TEMPLATE_
_CAP_NAME_::Cap() : super(), externalCount(0) {
}

_CAP_TEMPLATE_
_CAP_NAME_::~Cap() {
  assert(externalCount == 0);
}

_CAP_TEMPLATE_
void * _CAP_NAME_::AllocBuf() {
  void * buf = super::AllocBuf();
  if (buf) return buf;
  
  
  buf = (void *)(new uint8_t[Element]);
  if (buf) externalCount++;
  return buf;
}

_CAP_TEMPLATE_
void _CAP_NAME_::FreeBuf(void * buf) {
  uint8_t * buf8 = (uint8_t *)buf;
  if (buf8 < this->dataStart || buf8 >= this->dataStart + this->dataUsed) {
    delete buf8;
    externalCount--;
  } else {
    super::FreeBuf(buf);
  }
}

_CAP_TEMPLATE_
size_t _CAP_NAME_::CountAllocated() {
  return super::CountAllocated() + externalCount;
}

#undef _CAP_TEMPLATE_
#undef _CAP_NAME_

}