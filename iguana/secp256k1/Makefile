CFLAGS=-I. -I./src  -I./include -I./src -O3 -W -std=c89 -pedantic -Wall -Wextra -Wcast-align -Wnested-externs -Wshadow -Wstrict-prototypes -Wno-unused-function -Wno-long-long -Wno-overlength-strings -fvisibility=hidden -DHAVE_CONFIG_H
CC=gcc

all: secp256k1.a

src/%.o:src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

secp256k1.a: src/secp256k1.o
	$(AR) -r $@ $^

clean:
	$(RM) *.a
	$(RM) src/*.o

.PHONY: all
