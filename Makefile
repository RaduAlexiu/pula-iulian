# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra

# Source file
SRC := lanparty.c

# Object file
OBJ := $(SRC:.c=.o)

# Executable name
EXECUTABLE := lanParty

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
