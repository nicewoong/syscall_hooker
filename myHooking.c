#include <stdio.h>

void *memcpy(void *dest, const void *src, size_t count) {
        char* dst8 = (char*)dest;
        char* src8 = (char*)src;
 
        while (count--) {
            *dst8++ = *src8++;
        }

 printf("Hooking Test : memcpy[][%s]\r\n",(char *)src);
        return dest;



 }

