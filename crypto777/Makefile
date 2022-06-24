CC=gcc
CFLAGS=-DLIQUIDITY_PROVIDER=1 -O2 -I/usr/lib/x86_64-linux-gnu/curl

all: jpeg/libjpeg.a libcrypto777.a

clean:
	$(RM) *.o
	$(RM) libcrypto777.a
	$(MAKE) -C jpeg clean


%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

libcrypto777.a: jpeg/libjpeg.a \
		bitcoind_RPC.o \
		cJSON.o \
		curve25519-donna.o \
		curve25519.o \
		hmac_sha512.o \
		iguana_OS.o \
		iguana_serdes.o \
		iguana_utils.o \
		inet.o \
		OS_nonportable.o \
		OS_portable.o \
		OS_time.o \
		ramcoder.o \
		SaM.o \
		scrypt.o \
		tweetnacl.o
	$(AR) -r $@ $^

jpeg/libjpeg.a:
	$(MAKE) -C jpeg all
