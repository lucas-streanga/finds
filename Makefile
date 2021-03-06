SRC = finds.cpp
EXE = finds

CFLAGS = -std=c++17 -O2

INSTALL_PATH = /usr/local/bin

all : $(EXE)

$(EXE) : $(SRC)
	g++ $(CFLAGS) $(SRC) -o $(EXE) -lstdc++fs

debug: CFLAGS = -g -Wall -Wextra -DDEBUG=1 -std=c++17
debug: all

install : $(EXE)
	@echo "Installing executable to path" $(INSTALL_PATH)
	cp $(EXE) $(INSTALL_PATH)/$(EXE)
