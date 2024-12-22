#include <stdio.h>

#include "cpu/register.h"

int main() {
    reg_t reg1;
    reg1.rax = 0x1234abcd5678ffef;
    printf("eax: %08x\n", reg1.eax);
    printf("ax: %04x\n", reg1.ax);
    printf("ah: %02x\n", reg1.ah);
    printf("al: %02x\n", reg1.al);

    return 0;
}