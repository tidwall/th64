# th64

A tiny hash function in C.

Passes all tests in [SMhasher3](https://gitlab.com/fwojcik/smhasher3).
It's fast for small keys at 43 cycles/hash (1-32 bytes) and fast for big keys too at 2.61 bytes/cycle (8.52 GiB/sec). 

```c
uint64_t th64(const void *data, size_t len, uint64_t seed) {
    uint64_t*p=(uint64_t*)data,r=0x14020a57acced8b7,x,h=seed,i=0,n=len;
    while(i+8<=n)x=p[i>>3]*r+i,i+=8,x=x<<31|x>>33,h=h*r^x,h=h<<31|h>>33;
    while(i<n)h=h*r^((uint8_t*)data)[i++];
    return(h=h*r+len,h^=h>>31,h*=r,h^=h>>31,h*=r,h^=h>>31,h*=r,h);
}
```

Public domain or MIT-0, your choice.
