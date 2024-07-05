// https://github.com/tidwall/th64
//
// Copyright (c) 2024 Joshua J Baker.
// This software is available as a choice of Public Domain or MIT-0.

#ifndef TH64_H
#define TH64_H

#include <stdint.h>
#include <string.h>

static uint64_t th64(const void *data, size_t len, uint64_t seed) {
    uint64_t r=0x14020a57acced8b7,x,h=seed;
    uint8_t *p=(uint8_t*)data,*e=p+len;
    while(p+8<=e)memcpy(&x,p,8),x*=r,p+=8,x=x<<31|x>>33,h=h*r^x,h=h<<31|h>>33;
    while(p<e)h=h*r^*(p++);
    return(h=h*r+len,h^=h>>31,h*=r,h^=h>>31,h*=r,h^=h>>31,h*=r,h);
}

#endif
