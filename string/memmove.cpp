#include <iostream>


void* memmove(void* dest, const char* src, size_t n){
    char* p1 = static_cast<char*>(dest);
    const char* p2 = src;

    if(p1 <= p2){
        while(n-- != 0){
            *p1++ = *p2++;
        }
    }else{
        p1 += n;
        p2 += n;
        while(n-- != 0){
            *--p1 = *--p2;
        }
    }
    return p1;
}