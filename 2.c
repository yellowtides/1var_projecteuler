#include <stdio.h>
int main() {
    __uint128_t x = ((__uint128_t) 1 << 0x20) + 1;
    while (x % ((__uint128_t) 1 << 0x20) < 4e6) {
        if (!(x % ((__uint128_t) 1 << 0x20) & 1)) x += x % ((__uint128_t) 1 << 0x20) << 0x40;
        x += x % ((__uint128_t) 1 << 0x40) / ((__uint128_t) 1 << 0x20);
        x += x % ((__uint128_t) 1 << 0x20) - (x % ((__uint128_t) 1 << 0x40) / ((__uint128_t) 1 << 0x20) << 1) << 0x20;
    }
    printf("%llu\n", (unsigned long long) (x / ((__uint128_t) 1 << 0x40)));
    return 0;
}