CC = gcc
CFLAGS = -std=c23 -Wall -Wextra -Werror -lm
SRCS = $(wildcard *.c)
BINS = $(SRCS:.c=)

.PHONY: all clean

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(BINS)
