#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

#include <map>
#include <vector>
#include <stdint.h>

class RegisterFile {
public:
    enum {
        R0 = 0,
        R1,
        R2,
        R3,
        ZERO,
        SP,
        LR,
        TMP,
        PRED,
        REG_NUM
    };

    RegisterFile() : regs(REG_NUM, 0) {}
    void dump(uint32_t index) const;
    void write(uint32_t index, uint32_t value);
    uint32_t read(uint32_t index) const;

private:
    std::vector<uint32_t> regs;
};

#endif

