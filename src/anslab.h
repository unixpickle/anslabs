#ifndef __ANSLAB_H__
#define __ANSLAB_H__

#include <cstddef>
#include <cassert>

class ANSlab {
protected:
  void * buffer;
  size_t bufferSize;
  size_t bufferUsed;
  
  size_t slabAlignment;
  size_t slabSize;
  
  void ** firstTable;
  int itemsPerTable;

public:  
  ANSlab(void * buff, size_t buffSize, size_t slabSize, size_t slabAlign);
  
  /**
   * Allocate a new slab, or return NULL if none are available.
   */
  void * Alloc();
  
  /**
   * Free a slab that was previously allocated.
   */
  void Free(void * slab);
  
};

#endif
