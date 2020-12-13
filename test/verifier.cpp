#include "Emulator.h"

#include <memory>
#include <stdint.h>
#include <gtest/gtest.h>

class InstructionTest : public ::testing::Test {
protected:
    void SetUp() override {
        emu = std::unique_ptr<Emulator>(new Emulator(0x20000, 0x20000));
        emu->init();
    }
    std::unique_ptr<Emulator> emu;
};

// dstReg = ADDri srcReg, imm
TEST_F(InstructionTest, ADDriTest) {
    /* 1. Build */
    uint32_t instSize = 4;
    uint8_t  inst[instSize];

    uint32_t addri = (0x1) |                    // imm
                     (RegisterFile::R0 << 16) | // srcReg
                     (RegisterFile::R1 << 20) | // dstReg
                     (0b00010 << 24);           // opcode
    for (uint32_t i = 0; i < instSize; i++) {
        inst[i] = (addri >> (i * 8)) & 0xff;
    }
    emu->load_instructions(inst, instSize);

    /* 2. Operate */
    emu->execute();

    /* 3. Check */
    ASSERT_EQ(0x1, emu->regFile.read(RegisterFile::R1));
}    

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
