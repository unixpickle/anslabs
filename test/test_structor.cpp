#include <cassert>
#include <anslabs>

static int globalCount = 0;

class MyClass {
public:
  char * buf;
  int field1;
  
  MyClass() : field1(0x10) {
    buf = new char[0x10];
    globalCount++;
  }
  
  MyClass(int field) : field1(field) {
    buf = new char[field];
    globalCount++;
  }
  
  ~MyClass() {
    globalCount--;
    delete buf;
  }
};

typedef ANSlabs::Cap<0x10, sizeof(MyClass)> CapType;
class TestSubclass : public ANSlabs::Structor<MyClass, CapType> {
};

int main(int, const char **) {
  TestSubclass test;
  MyClass * obj = test.New(0x11);
  assert(globalCount == 1);
  assert(obj->field1 == 0x11);
  test.Delete(obj);
  assert(globalCount == 0);
  return 0;
}
