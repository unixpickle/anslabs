# ANSlab

The purpose of this project is to provide a well tested, easy-to-use Slab allocator for OS kernels.

# Usage

## Raw Slabs

Raw slabs allocate a certain number of elements once using a `new` call. A raw slab will never allocate *more* elements, so you cannot use them exclusively unless you know the absolute maximum number of elements you will ever need.

While [test/test_raw.cpp](test/test_raw.cpp) provides the best example, here I will show you how to use the raw slab allocator. Create an instance like this:

    ANSlabs::Raw<X, Y> * allocator = new ANSlabs::Raw<X, Y>();

Here, `X` is the maximum number of elements the slab allocator may hold, and `Y` is the size of each element. It is recommended that each element is aligned the way you would like your instances aligned: probably by 16-bytes for the System V ABI.

Now, you can allocate and free buffers from the slab easily:

    void * myBuffer = allocator->AllocBuf();
    // ... do something here with myBuffer ...
    allocator.FreeBuf(myBuffer);

The `AllocBuf()` method will return `NULL` when there are no free elements left in the slab.
