QMAKE ?= qmake6
BUILD_DIR := build
PROJECT := qt-widgets-app.pro

.PHONY: all clean run

all:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && $(QMAKE) ../$(PROJECT)
	$(MAKE) -C $(BUILD_DIR)

run: all
	open $(BUILD_DIR)/qt-widgets-app.app

clean:
	rm -rf $(BUILD_DIR)
