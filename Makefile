# Compiler configuration
CC = gcc
CXX = g++

# Compiler flags
CFLAGS = -Wall -fPIC -Iinclude -IC:/smash/include
CXXFLAGS := $(CFLAGS)
DYNAMICFLAGS = -lopengl32 -lgdi32

# Input directories
SRC_DIR = src
LIBDEP_DIR = libdeps

# Output directories
OBJ_DIR = obj
LIB_DIR = lib
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
LIBDEPS := $(wildcard $(LIBDEP_DIR)/*.a)

# Determine static library
STATIC := $(LIB_DIR)/$(STATIC_LIB)
DYNAMIC := $(LIB_DIR)/$(DYNAMIC_LIB)
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
$(STATIC): $(OBJS) $(LIBDEPS)
	@if not exist $(LIB_DIR) mkdir $(LIB_DIR)
	ar rcs $(STATIC) $(OBJS) $(LIBDEPS)

# Make dynamic library
$(DYNAMIC): $(DLL)
$(DLL): $(OBJS) $(LIBDEPS)
	@if not exist $(LIB_DIR) mkdir $(LIB_DIR)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CXX) -shared -o $(DLL) $(OBJS) $(LIBDEPS) $(DYNAMICFLAGS) -Wl,--out-implib,$(DYNAMIC)

# Make resolved names
static: $(STATIC)
dynamic: $(DYNAMIC)

# Make all
all: static dynamic

# Make clean
clean:
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(LIB_DIR) rmdir /s /q $(LIB_DIR)
	@if exist $(BIN_DIR) rmdir /s /q $(BIN_DIR)