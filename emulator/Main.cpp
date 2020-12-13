#include <fcntl.h>
#include <gelf.h>
#include <libelf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "Emulator.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: ./emulator [executable_name]\n");
        return 1;
    }

    const char *elf_file = argv[1];
    if (elf_file == NULL) {
        printf("Missing ELF file\n");
        return 1;
    }

    elf_version(EV_CURRENT);
    int fd = open(elf_file, O_RDONLY);
    if (fd == -1) {
        printf("Can't open file %s\n", elf_file);
        return 1;
    }

    Elf *elf = elf_begin(fd, ELF_C_READ, NULL);
    Elf_Scn *scn = NULL;
    GElf_Shdr shdr;

    Emulator emu(0x20000, 0x20000);
    emu.init();

    /* load .text section */
    scn = NULL;
    size_t shstrndx;
    elf_getshdrstrndx(elf, &shstrndx);
    while ((scn = elf_nextscn(elf, scn)) != NULL) {
        gelf_getshdr(scn, &shdr);
        const char *name = elf_strptr(elf, shstrndx, shdr.sh_name);

        if (shdr.sh_type == SHT_PROGBITS) {
            if (strcmp(name, ".text") == 0) {
                Elf_Data *data = elf_getdata(scn, NULL);
                emu.load_instructions((uint8_t *)data->d_buf, shdr.sh_size);
                break;
            }
        }
    }

    /* close ELF file */
    elf_end(elf);
    close(fd);

    emu.execute();
}
