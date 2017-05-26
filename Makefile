APP_NAME=shape
BIN_DIR=bin
SRC_DIR=src

all:setup
	${CXX} -Wall -I include ${SRC_DIR}/*.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -o ${BIN_DIR}/${APP_NAME}

setup:
	mkdir -p ${BIN_DIR}

clean: distclean
	rm -rf ${BIN_DIR}
