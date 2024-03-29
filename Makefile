CC := clang
SRC := simple/buffer-overrun.c

# Output file
OUT := buffer-overrun

# Compiler flags
CFLAGS := -Wall -Wextra -std=c11

# Rules
all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OUT)

.PHONY: all clean
