#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t u64;

uint8_t u8_array[8];

void copy_u64_to_u8_array()
{
    for (int pos = 0; pos < 8; pos++) {
        u8_array[pos] = (u64 >> (56 - (pos * 8))) & 0xFF;
    }
}

char *byte_to_binary(uint8_t u8)
{
    char *to_return = malloc(9);

    if (NULL == to_return) exit(-ENOMEM);

    uint8_t mask = 0x80;

    for (int pos = 0; pos < 8; pos++) {
        to_return[pos] = ((u8 & mask) == mask) ? '1' : '0';
        mask = mask >> 1;
    }

    to_return[8] = '\0';

    return to_return;
}

void display_array()
{
    int printf_return;

    for (int row = 0; row < 8; row++) {
        printf_return = printf("  %s\n", byte_to_binary(u8_array[row]));
    }
}

uint32_t compute_island_count()
{
    return 0; // TODO - not yet implemented
}

int main(int argc, const char * argv[])
{
    if (2 != argc) exit(-EINVAL);

    int sscanf_return = sscanf(argv[1], "%llx", &u64);

    if (1 != sscanf_return) exit(-EINVAL);

    copy_u64_to_u8_array();

    display_array();

    int printf_return = printf("Islands found == %u\n", compute_island_count());

    return 0;
}
