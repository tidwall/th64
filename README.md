# th64

A tiny hash function in C.

Passes all tests in [SMhasher3](https://gitlab.com/fwojcik/smhasher3).
It's fast for small keys at 43 cycles/hash (1-32 bytes) and fast for big keys too at 2.61 bytes/cycle (8.52 GiB/sec). 

```c
static uint64_t th64(const void *data, size_t len, uint64_t seed) {
    uint8_t*p=(uint8_t*)data,*e=p+len;
    uint64_t r=0x14020a57acced8b7,x,h=seed;
    while(p+8<=e)memcpy(&x,p,8),x*=r,p+=8,x=x<<31|x>>33,h=h*r^x,h=h<<31|h>>33;
    while(p<e)h=h*r^*(p++);
    return(h=h*r+len,h^=h>>31,h*=r,h^=h>>31,h*=r,h^=h>>31,h*=r,h);
}
```

## License

Public domain or MIT-0, your choice.
