all:run

SRC_DIR=src
LANG=cpp
SRC=$(wildcard $(SRC_DIR)/*.$(LANG))

BIN_DIR=bin
EXEC_NAME=Raygui
EXEC=$(BIN_DIR)/$(EXEC_NAME)

CC=g++
CFLAGS=-Wall -Wextra -pedantic -std=c++11 -g
LDFLAGS=-lraylib -lm

build:$(SRC)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC) $(LDFLAGS)

run:build
	./$(EXEC)
