#include "stdio.h"
#include "Instruction.h"

static uint32_t get_insn(Memory &instMem, uint32_t pc) {
    return (instMem.read(pc))           |
           (instMem.read(pc + 1) << 8 ) |
           (instMem.read(pc + 2) << 16) |
           (instMem.read(pc + 3) << 24);
}

void ADDri::execute(RegisterFile &regFile,
                    Memory &instMem,
                    Memory &dataMem,
                    uint32_t &pc) {
    printf("ADDri\n");
    uint32_t insn = get_insn(instMem, pc);
    uint32_t rd = (insn >> 20) & 0xf;
    uint32_t rs1 = (insn >> 16) & 0xf;
    uint32_t imms2 = (int32_t((insn & 0xffff) << 16)) >> 16; // do sign extension 
    regFile.dump(rs1);
    printf("imms2: %d\n", imms2);
    uint32_t sum = regFile.read(rs1) + imms2;
    regFile.write(rd, sum);
    regFile.dump(rd);
    printf("==============\n");
    pc += 4;
}

void SUBri::execute(RegisterFile &regFile,
                    Memory &instMem,
                    Memory &dataMem,
                    uint32_t &pc) {
    printf("SUBri\n");
    uint32_t insn = get_insn(instMem, pc);
    uint32_t rd = (insn >> 20) & 0xf;
    uint32_t rs1 = (insn >> 16) & 0xf;
    uint32_t imms2 = (int32_t((insn & 0xffff) << 16)) >> 16; // do sign extension 
    regFile.dump(rs1);
    printf("imms2: %d\n", imms2);
    regFile.write(rd, regFile.read(rs1) - imms2);
    regFile.dump(rd);
    printf("==============\n");
    pc += 4;
}

void STORErr::execute(RegisterFile &regFile,
                     Memory &instMem,
                     Memory &dataMem,
                     uint32_t &pc) {
    printf("STORErr\n");
    uint32_t insn = get_insn(instMem, pc);
    uint32_t rs = insn & 0xf;
    uint32_t base = (insn >> 4) & 0xf;
    uint32_t offset = (insn >> 8) & 0xf;
    uint32_t addr = regFile.read(base) + regFile.read(offset);
    regFile.dump(rs);
    uint32_t value = regFile.read(rs);
    dataMem.write(addr, (uint8_t)value);
    dataMem.write(addr + 1, (uint8_t)(value >> 8));
    dataMem.write(addr + 2, (uint8_t)(value >> 16));
    dataMem.write(addr + 3, (uint8_t)(value >> 24));
    printf("addr: %d\n", addr);
    printf("==============\n");
    pc += 4;
}

void LOADrr::execute(RegisterFile &regFile,
                     Memory &instMem,
                     Memory &dataMem,
                     uint32_t &pc) {
    printf("LOADrr\n");
    uint32_t insn = get_insn(instMem, pc);
    uint32_t rd = insn & 0xf;
    uint32_t base = (insn >> 4) & 0xf;
    uint32_t offset = (insn >> 8) & 0xf;
    uint32_t addr = regFile.read(base) + regFile.read(offset);
    printf("addr: %d\n", addr);
    uint32_t value = dataMem.read(addr)             |
                     (dataMem.read(addr + 1) << 8)  |
                     (dataMem.read(addr + 2) << 16) |
                     (dataMem.read(addr + 3) << 24);
    regFile.write(rd, value);
    regFile.dump(rd);
    printf("==============\n");
    pc += 4;
}

void RET::execute(RegisterFile &regFile,
                  Memory &instMem,
                  Memory &dataMem,
                  uint32_t &pc) {
    printf("RET\n");
    pc = regFile.read(regFile.LR);
    printf("==============\n");
}

void CALL::execute(RegisterFile &regFile,
                   Memory &instMem,
                   Memory &dataMem,
                   uint32_t &pc) {
    printf("CALL\n");
    uint32_t insn = get_insn(instMem, pc);
    regFile.write(regFile.LR, pc + 4);
    pc += (insn & 0xffff);
    printf("==============\n");
}

void MOVi::execute(RegisterFile &regFile,
                   Memory &instMem,
                   Memory &dataMem,
                   uint32_t &pc) {
    printf("MOVi\n");
    uint32_t insn = get_insn(instMem, pc);
    uint32_t rd = (insn >> 20) & 0xf;
    uint32_t imms = insn & 0xffff;
    printf("imm: %d\n", imms);
    regFile.write(rd, imms);
    regFile.dump(rd);
    printf("==============\n");
    pc += 4;
}
