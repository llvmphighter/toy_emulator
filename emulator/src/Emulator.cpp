#include "stdio.h"

#include "Emulator.h"
#include "Instruction.h"

Emulator::Emulator(uint32_t instMemSize, uint32_t dataMemSize, const char *memoryDumpFile)
    : instMemory(instMemSize), dataMemory(dataMemSize), memoryDumpFile(memoryDumpFile) {}

void Emulator::init() {

#define REGISTER(OP, INST) \
    op2InstMap.insert( \
        std::make_pair( \
            OP, std::unique_ptr<INST>(new INST()) \
        ) \
    );
#include "Instruction.def"
#undef REGISTER

    regFile.write(RegisterFile::SP, STACK_START);
}

absl::Status Emulator::load_instructions(const uint8_t *insn, size_t size) {
    if (insn == nullptr) {
        printf("Invalid size\n");
        return absl::UnknownError("Invalid size");
    }
    if (size > instMemory.get_size()) {
        printf("Invalid size\n");
        return absl::UnknownError("Invalid size");
    }
    for (size_t i = 0; i < size; i++) {
        instMemory.write(i, insn[i]);
    }
    regFile.write(RegisterFile::LR, size);
    set_pc(0);

    return absl::OkStatus();
}

void Emulator::set_pc(uint32_t pc) {
    this->pc = pc;
}

void Emulator::execute() {
    uint32_t inst_end = regFile.read(RegisterFile::LR);
    while (pc < inst_end) {
        uint32_t insn = (instMemory.read(pc))           |
                        (instMemory.read(pc + 1) << 8 ) |
                        (instMemory.read(pc + 2) << 16) |
                        (instMemory.read(pc + 3) << 24);
        execute((insn >> 24) & 0x1f); 
    }
    dataMemory.dump(memoryDumpFile);
}

void Emulator::execute(unsigned int opcode) {
    if (op2InstMap.find(opcode) == op2InstMap.end()) {
        printf("Invalid opcode\n");
        return;
    }
    op2InstMap[opcode]->execute(regFile, instMemory, dataMemory, pc);
}
