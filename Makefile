BOOT_DIR = boot-loader
BOOT_BIN = boot-loader.bin
KERNEL_DIR = kernel-32
KERNEL_BIN = temp-os.bin
OUT = disk.img

$(OUT): $(BOOT_DIR) $(KERNEL_DIR)
	cat $(BOOT_DIR)/$(BOOT_BIN) $(KERNEL_DIR)/$(KERNEL_BIN) > $(OUT)

$(KERNEL_DIR): dummy
	make -C $(KERNEL_DIR)

$(BOOT_DIR): dummy
	make -C $(BOOT_DIR)

dummy:
	@echo "build start.."

clean:
	make -C $(KERNEL_DIR) clean
	make -C $(BOOT_DIR) clean
	rm -f $(OUT)