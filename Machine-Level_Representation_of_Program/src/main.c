#include <stdio.h>

#include "cpu/register.h"

int main() {
    uint64_t a = 0x12340000;
    uint64_t b = 0xabcd;

    a = a + b;
    return 0;
}