BOOT_DIR = boot-loader
BOOT_BIN = boot-loader.bin
OUT = disk.img

$(OUT): $(BOOT_DIR)
	cp $(BOOT_DIR)/$(BOOT_BIN) $(OUT)

$(BOOT_DIR): dummy
	make -C $(BOOT_DIR)

dummy:
	@echo "build start.."

clean:
	make -C $(BOOT_DIR) clean
	rm -f $(OUT)