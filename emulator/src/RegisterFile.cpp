#include "stdio.h"
#include "RegisterFile.h"

void RegisterFile::dump(uint32_t index) {
    switch (index)
    {
    case R0: printf("R0: %d\n", regs[index]); break;
    case R1: printf("R1: %d\n", regs[index]); break;
    case R2: printf("R2: %d\n", regs[index]); break;
    case R3: printf("R3: %d\n", regs[index]); break;
    case ZERO: printf("ZERO: %d\n", regs[index]); break;
    case SP: printf("SP: %d\n", regs[index]); break;
    case LR: printf("LR: %d\n", regs[index]); break;
    case TMP: printf("TMP: %d\n", regs[index]); break;
    default: printf("Invalid index\n"); break;
    }
}

void RegisterFile::write(uint32_t index, uint32_t value) {                                 
    if (index >= REG_NUM)                                                                     
        printf("Invalid write\n");                                                             
    regs[index] = value;                                                                      
}                                                                                             
                                                                                              
uint32_t RegisterFile::read(uint32_t index) {                                              
    if (index >= REG_NUM)                                                                     
        printf("Invalid read\n");
    return regs[index];                                                                       
}
