#ifndef INSTRUCTION_H
#define INSTRUCTION_H 

#include "Memory.h"
#include "RegisterFile.h"

class Instruction {
public:
    Instruction() = default;
    virtual void execute(RegisterFile &regFile,
                         Memory &instMem,
                         Memory &dataMem,
                         uint32_t &pc) = 0;
};

class ADDri : public Instruction {
public:
    ADDri() : Instruction() {}
    void execute(RegisterFile &regFile,
                 Memory &instMem,
                 Memory &dataMem,
                 uint32_t &pc) override;
};

class SUBri : public Instruction {
public:
    SUBri() : Instruction() {}
    void execute(RegisterFile &regFile,
                 Memory &instMem,
                 Memory &dataMem,
                 uint32_t &pc) override;
};

class STORErr : public Instruction {
public:
    STORErr() : Instruction() {}
    void execute(RegisterFile &regFile,
                 Memory &instMem,
                 Memory &dataMem,
                 uint32_t &pc) override;
};

class LOADrr : public Instruction {
public:
    LOADrr() : Instruction() {}
    void execute(RegisterFile &regFile,
                 Memory &instMem,
                 Memory &dataMem,
                 uint32_t &pc) override;
};

class RET : public Instruction {
public:
    RET() : Instruction() {}
    void execute(RegisterFile &regFile,
                 Memory &instMem,
                 Memory &dataMem,
                 uint32_t &pc) override;
};

class CALL : public Instruction {
public:
    CALL() : Instruction() {}
    void execute(RegisterFile &regFile,
                 Memory &instMem,
                 Memory &dataMem,
                 uint32_t &pc) override;
};

class MOVi : public Instruction {
public:
    MOVi() : Instruction() {}
    void execute(RegisterFile &regFile,
                 Memory &instMem,
                 Memory &dataMem,
                 uint32_t &pc) override;
};

#endif
