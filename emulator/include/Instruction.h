#ifndef INSTRUCTION_H
#define INSTRUCTION_H 

#include "Memory.h"
#include "RegisterFile.h"

class Instruction {
public:
    Instruction() = default;
    virtual ~Instruction() {}
    virtual void execute(RegisterFile &regFile,
                         Memory &instMem,
                         Memory &dataMem,
                         uint32_t &pc) = 0;
};

#define REGISTER(OP, INST) \
class INST : public Instruction { \
public: \
    INST() : Instruction() {} \
    void execute(RegisterFile &regFile, \
                 Memory &instMem, \
                 Memory &dataMem, \
                 uint32_t &pc) override; \
};

#include "Instruction.def"
#undef REGISTER

#endif
