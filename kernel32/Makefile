NASM = nasm
GCC = gcc -c -m32 -ffreestanding
LD = ld -melf_i386 -T ../elf-i386.x -nostdlib -e main -Ttext 0x10200
OBJCOPY = objcopy -j .text -j .data -j .rodata -j .bss -S -O binary

OBJECT_DIR = temp
SOURCE_DIR = source

all: prepare kernel32.bin

prepare:
	mkdir -p $(OBJECT_DIR)

$(OBJECT_DIR)/entry-point.bin: $(SOURCE_DIR)/entry-point.s
	$(NASM) -o $@ $<

dep:
	make -C $(OBJECT_DIR) -f ../Makefile internal-dependency

ExecuteInternalBuild: dep
	make -C $(OBJECT_DIR) -f ../Makefile kernel32.elf

$(OBJECT_DIR)/kernel32.elf.bin: ExecuteInternalBuild
	$(OBJCOPY) $(OBJECT_DIR)/kernel32.elf $@

kernel32.bin: $(OBJECT_DIR)/entry-point.bin $(OBJECT_DIR)/kernel32.elf.bin
	cat $^ > $@

clean:
	rm -f *.bin
	rm -f $(OBJECT_DIR)/*.*

# temp
CENTRYPOINTOBJECTFILE = main.o
CSOURCEFILES = $(wildcard ../$(SOURCE_DIR)/*.c)
ASSEMBLYSOURCEFILES = $(wildcard ../$(SOURCE_DIR)/*.asm)
COBJECTFILES = $(subst Main.o, , $(notdir $(patsubst %.c,%.o,$(CSOURCEFILES))))
ASSEMBLYOBJECTFILES = $(notdir $(patsubst %.asm,%.o,$(ASSEMBLYSOURCEFILES)))

%.o: ../$(SOURCE_DIR)/%.c
	$(GCC) -c $<

%.o: ../$(SOURCE_DIR)/%.asm
	$(NASM) -f elf32 -o $@ $<

internal-dependency:
	$(GCC) -MM $(CSOURCEFILES) > dependency.dep

kernel32.elf: $(CENTRYPOINTOBJECTFILE) $(COBJECTFILES) $(ASSEMBLYOBJECTFILES)
	$(LD) -o $@ $^

ifeq (dependency.dep, $(wildcard dependency.dep))
include dependency.dep
endif