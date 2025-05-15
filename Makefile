# ---------- CONFIG -----------------------------------------------------------
CXX        ?= clang++
CXXFLAGS    = -std=c++17 -Wall -Wextra -pedantic \
              -Iinclude -I/opt/homebrew/include
LDFLAGS     = -L/opt/homebrew/lib -lunistring

BUILD_DIR   = build
TARGET      = stringui            # nom CLI et lib
BIN         = $(BUILD_DIR)/$(TARGET)

LIB_A       = $(BUILD_DIR)/libstringui.a
OBJ         = $(BUILD_DIR)/StringUI.o
SRC_LIB     = src/StringUI.cpp
SRC_CLI     = src/main.cpp

# Dossiers d’install
PREFIX        ?= /usr/local
INCLUDEDIR     = $(PREFIX)/include
LIBDIR         = $(PREFIX)/lib
PKGDIR         = $(LIBDIR)/pkgconfig
USER_BINDIR   ?= $(HOME)/.local/bin

# ---------- BUILD : library --------------------------------------------------
$(OBJ): $(SRC_LIB) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(LIB_A): $(OBJ)
	ar rcs $@ $^

# ---------- BUILD : CLI ------------------------------------------------------
$(BIN): $(SRC_CLI) $(LIB_A) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -Iinclude $< $(LIB_A) -o $@ $(LDFLAGS)

# ---------- INSTALL : library ------------------------------------------------
install-lib: $(LIB_A) stringui.pc
	sudo mkdir -p $(LIBDIR) $(INCLUDEDIR) $(PKGDIR)
	sudo cp $(LIB_A)            $(LIBDIR)/
	sudo cp include/*.hpp       $(INCLUDEDIR)/
	sudo cp stringui.pc         $(PKGDIR)/
	@echo "✓ libstringui.a + headers + .pc installed"

uninstall-lib:
	sudo rm -f $(LIBDIR)/libstringui.a
	sudo rm -f $(INCLUDEDIR)/StringUI.hpp
	sudo rm -f $(PKGDIR)/stringui.pc
	@echo "✓ Library uninstalled"

# ---------- INSTALL : CLI ----------------------------------------------------
install-cli: $(BIN)
	mkdir -p $(USER_BINDIR)
	cp $(BIN) $(USER_BINDIR)/$(TARGET)
	@echo "✓ CLI installed to $(USER_BINDIR)"

uninstall-cli:
	rm -f $(USER_BINDIR)/$(TARGET)
	@echo "✓ CLI uninstalled"

# ---------- META TARGETS -----------------------------------------------------
all: $(BIN)

install: install-lib install-cli
	@echo "✅ Everything installed"

uninstall: uninstall-lib uninstall-cli
	@echo "🗑️  Everything uninstalled"

clean:
	rm -rf $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: all clean \
        install-lib uninstall-lib \
        install-cli uninstall-cli \
        install-all uninstall-all
