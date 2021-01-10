#include "Memory.h"

#include "stdio.h"
#include "spdlog/spdlog.h"

uint32_t Memory::get_size() const {
    return size;
}

void Memory::write(uint32_t pos, uint8_t value) {
    if (pos >= size) {
        printf("Invalid write\n");
    }
    mems[pos] = value;
}

uint8_t Memory::read(uint32_t pos) const {
    if (pos >= size) { 
        printf("Invalid read\n");
    }
    return mems[pos];
}

void Memory::dump(const char *fileName) const {
    std::fstream file;
    file.open(fileName, std::ios_base::out | std::ios_base::binary);
    if (file.fail()) {
        spdlog::error("Fail to open the file when dumping the contents of memory");
        return;
    }

    for (uint32_t i = 0; i < size; i++) {
        file.write((const char *)&mems[i], sizeof(char));
    }

    file.close();
}
