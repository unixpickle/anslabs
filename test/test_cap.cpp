#include <iostream>
#include <cassert>
#include <anslabs>

using namespace std;

class TestSubclass : public ANSlabs::Cap<0x20, 0x10> {
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
  
  void * allocated[0x10];
  
  for (int i = 0; i < 0x30; i++) {
    void * buf = test.AllocBuf();
    assert(buf == (void *)(test.GetDataStart() + 0x10 * i));
    
    assert((size_t)(i + 1) == test.CountAllocated());
    if (i <= 0x1f) {
      assert((size_t)(0x1f - i) == test.CountFree());
    } else {
      assert(0 == test.CountFree());
      allocated[i - 0x20] = buf;
    }
  }
  
  for (int i = 0; i < 0x20; i++) {
    test.FreeBuf((void *)(test.GetDataStart() + 0x10 * i));
    assert((size_t)(i + 1) == test.CountFree());
    assert((size_t)(0x2f - i) == test.CountAllocated());
  }
  
  void * buf = test.AllocBuf();
  assert(buf == (void *)(test.GetDataStart() + 0x1f0));
  assert(test.CountFree() == 0x1f);
  assert(test.CountAllocated() == 0x11);
  
  for (int i = 0; i < 0x10; i++) {
    test.FreeBuf(allocated[i]);
    assert(test.CountAllocated() == 0x10 - i);
  }
  
  cout << "passed!" << endl;
  
  return 0;
}
