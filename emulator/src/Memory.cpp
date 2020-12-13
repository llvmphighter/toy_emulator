#include "stdio.h"
#include "Memory.h"

uint32_t Memory::get_size() {
    return size;
}

void Memory::write(uint32_t pos, uint8_t value) {
    if (pos >= size) {
        printf("Invalid write\n");
    }
    mems[pos] = value;
}

uint8_t Memory::read(uint32_t pos) {
    if (pos >= size) { 
        printf("Invalid read\n");
    }
    return mems[pos];
}
