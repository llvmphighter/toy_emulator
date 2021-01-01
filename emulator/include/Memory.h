#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>
#include <vector>

class Memory {
public:
    Memory(uint32_t size) : size(size), mems(size, 0) {}
    uint32_t get_size() const;
    void write(uint32_t pos, uint8_t value);
    uint8_t read(uint32_t pos) const;
private:
    std::vector<uint8_t> mems;
    uint32_t size;
};

#endif
