// https://github.com/tidwall/th64
//
// Copyright (c) 2024 Joshua J Baker.
// This software is available as a choice of Public Domain or MIT-0.

#ifndef TH64_H
#define TH64_H

static uint64_t th64(const void *data, size_t len, uint64_t seed) {
    uint64_t*p=(uint64_t*)data,r=0x14020a57acced8b7,x,h=seed,i=0,n=len;
    while(i+8<=n)x=p[i>>3]*r+i,i+=8,x=x<<31|x>>33,h=h*r^x,h=h<<31|h>>33;
    while(i<n)h=h*r^((uint8_t*)data)[i++];
    return(h=h*r+len,h^=h>>31,h*=r,h^=h>>31,h*=r,h^=h>>31,h*=r,h);
}

#endif
