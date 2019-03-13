ASM = nasm
OUT = kernel64.bin
SOURCE = source/entry-point.asm

$(OUT):
	$(ASM) -o $(OUT) $(SOURCE)

clean:
	rm -f $(OUT)