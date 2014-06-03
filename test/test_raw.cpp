#include <iostream>
#include <cassert>
#include <anslabs>

using namespace std;

class TestSubclass : public ANSlabs::Raw<0x20, 0x10> {
public:
  size_t GetDataUsed() { return this->dataUsed; }
  uint8_t * GetDataStart() { return this->dataStart; }
  size_t GetCount() { return this->count; }
  void ** GetBuffers() { return this->buffers; }
};

int main() {
  TestSubclass test;
  
  cout << "Testing ANSlab::Raw<0x20, 0x10> ... ";
  
  assert(0 == test.GetDataUsed());
  assert(NULL == test.GetDataStart());
  assert(0 == test.GetCount());
  assert(0 == test.CountAllocated());
  assert(0x20 == test.CountFree());
  
  for (int i = 0; i < 0x20; i++) {
    void * buf = test.AllocBuf();
    assert(buf == (void *)(test.GetDataStart() + 0x10 * i));
    
    assert((size_t)(i + 1) == test.CountAllocated());
    assert((size_t)(0x1f - i) == test.CountFree());
  }
  
  for (int i = 0; i < 0x20; i++) {
    test.FreeBuf((void *)(test.GetDataStart() + 0x10 * i));
    assert((size_t)(i + 1) == test.CountFree());
    assert((size_t)(0x1f - i) == test.CountAllocated());
  }
  
  void * buf = test.AllocBuf();
  assert(buf == (void *)(test.GetDataStart() + 0x1f0));
  assert(test.CountFree() == 0x1f);
  assert(test.CountAllocated() == 0x1);
  
  cout << "passed!" << endl;
  
  return 0;
}
