UTIL_DIR = utility
IMAGE_MAKER = utility/image-maker.out
BOOT_DIR = boot-loader
BOOT_BIN = boot-loader/boot-loader.bin
KERNEL32_DIR = kernel32
KERNEL32_BIN = kernel32/kernel32.bin
KERNEL64_DIR = kernel64
KERNEL64_BIN = kernel64/kernel64.bin
OUT = disk.img

$(OUT): $(BOOT_BIN) $(KERNEL32_BIN)
	make -C $(UTIL_DIR)
	./$(IMAGE_MAKER) $^

$(KERNEL64_BIN): dummy
	make -C $(KERNEL64_DIR)

$(KERNEL32_BIN): dummy
	make -C $(KERNEL32_DIR)

$(BOOT_BIN): dummy
	make -C $(BOOT_DIR)

dummy:
	@echo "build start.."

clean:
	make -C $(UTIL_DIR) clean
	make -C $(KERNEL64_DIR) clean
	make -C $(KERNEL32_DIR) clean
	make -C $(BOOT_DIR) clean
	rm -f $(OUT)