CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -I./include
LDFLAGS := -L./libraries -lglfw3 -lopengl32 -lgdi32

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
LIB_DIR := lib

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

TARGET := libsmash.dll
LIB_TARGET := libsmash.a

.PHONY: all clean

all: $(BIN_DIR)/$(TARGET) $(LIB_DIR)/$(LIB_TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/$(TARGET): $(OBJS)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CXX) -shared -o $@ $^ $(LDFLAGS)

$(LIB_DIR)/$(LIB_TARGET): $(OBJS)
	@if not exist $(LIB_DIR) mkdir $(LIB_DIR)
	ar rcs $@ $^

clean:
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(BIN_DIR) rmdir /s /q $(BIN_DIR)
	@if exist $(LIB_DIR) rmdir /s /q $(LIB_DIR)