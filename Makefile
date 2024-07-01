# Compiler configuration
CC = gcc
CXX = g++

# Compiler flags
CFLAGS = -Wall -fPIC -Iinclude
CXXFLAGS := $(CFLAGS) -std=c++17
LDFLAGS = -lopengl32 -lgdi32

# Input directories
SRC_DIR = src
DEP_DIR = depends
DEP_STATIC_DIR := $(DEP_DIR)/static
DEP_DYNAMIC_DIR := $(DEP_DIR)/dynamic

# Output directories
OBJ_DIR = obj
LIB_DIR = lib
LIB_STATIC_DIR := $(LIB_DIR)/static
LIB_DYNAMIC_DIR := $(LIB_DIR)/dynamic
BIN_DIR = bin

# Output names
STATIC_LIB = libsmash.a
DYNAMIC_LIB = libsmashdll.a
DYNAMIC_BIN = smash.dll

# Collect source files
CC_SRCS := $(wildcard $(SRC_DIR)/*.c)
CXX_SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Collect object files
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(CC_SRCS)) \
        $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CXX_SRCS))

# Collect library dependencies
DEPS_STATIC := $(wildcard $(DEP_STATIC_DIR)/*.a)
DEPS_DYNAMIC := $(wildcard $(DEP_DYNAMIC_DIR)/*.a)

# Determine static library
STATIC := $(LIB_STATIC_DIR)/$(STATIC_LIB)
DYNAMIC := $(LIB_DYNAMIC_DIR)/$(DYNAMIC_LIB)
DLL := $(BIN_DIR)/$(DYNAMIC_BIN)

# Compile c files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile cpp files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Make static library
$(STATIC): $(OBJS) $(DEPS_STATIC)
	@if not exist "$(LIB_STATIC_DIR)" mkdir "$(LIB_STATIC_DIR)"
	ar rcs $(STATIC) $(OBJS) $(DEPS_STATIC)
	@echo Static library created.

# Make dynamic library
$(DYNAMIC): $(DLL)
$(DLL): $(OBJS) $(DEPS_DYNAMIC)
	@if not exist "$(LIB_DYNAMIC_DIR)" mkdir "$(LIB_DYNAMIC_DIR)"
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CXX) -shared -o $(DLL) $(OBJS) $(DEPS_STATIC) $(LDFLAGS) -Wl,--out-implib,$(DYNAMIC)
	@echo Dynamic library created.

# Make default
.DEFAULT_GOAL := all

# Make all
all: $(STATIC) $(DYNAMIC)

# Make resolved names
static: $(STATIC)
dynamic: $(DYNAMIC)

# Make clean
clean:
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(LIB_DIR) rmdir /s /q $(LIB_DIR)
	@if exist $(BIN_DIR) rmdir /s /q $(BIN_DIR)
	@echo Cleaned up.