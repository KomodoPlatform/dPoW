CC=clang
LD=clang
CFLAGS=-g -Wno-deprecated -O2 -DISNOTARYNODE=1
CFLAGS_NO_OPTIMIZATION=-Wno-deprecated -c -DISNOTARYNODE=1
LDFLAGS=-g -lnanomsg -lcurl -lssl -lcrypto -lpthread -lz -lm -lsodium

all: ../agents ../agents/iguana

clean:
	$(RM) ../agents/iguana
	$(RM) *.o
	$(RM) *.a
	$(MAKE) -C secp256k1 clean
	$(MAKE) -C ../crypto777 clean

../agents:
	mkdir $@

secp256k1/secp256k1.a:
	$(MAKE) -C secp256k1 all

../crypto777/libcrypto777.a:
	$(MAKE) -C ../crypto777 all

optimized.a: \
		../gecko/gecko.o \
		../datachain/datachain.o \
		iguana_accept.o \
		iguana_bitmap.o \
		iguana_blocks.o \
		iguana_chains.o \
		iguana_exchanges.o \
		iguana_init.o \
		iguana_interpreter.o \
		iguana_json.o \
		iguana_mofn.o \
		iguana_msg.o \
		iguana_notary.o \
		iguana_passport.o \
		iguana_payments.o \
		iguana_peers.o \
		iguana_ramchain.o \
		iguana_realtime.o \
		iguana_recv.o \
		iguana_rpc.o \
		iguana_scripts.o \
		iguana_secp.o \
		iguana_sign.o \
		iguana_spendvectors.o \
		iguana_stake.o \
		iguana_tradebots.o \
		iguana_tx.o \
		iguana_txidfind.o \
		iguana_unspents.o \
		iguana_volatiles.o \
		iguana_wallet.o \
		mini-gmp.o \
		ramchain_api.o \
		SuperNET_keys.o
	$(AR) -r $@ $^

main.o: main.c
	$(CC) $(CFLAGS_NO_OPTIMIZATION) -c -o $@ $^

iguana777.o: iguana777.c
	$(CC) $(CFLAGS_NO_OPTIMIZATION) -c -o $@ $^

iguana_bundles.o: iguana_bundles.c
	$(CC) $(CFLAGS_NO_OPTIMIZATION) -c -o $@ $^

../basilisk/basilisk.o: ../basilisk/basilisk.c
	$(CC) $(CFLAGS_NO_OPTIMIZATION) -c -o $@ $^

../agents/iguana: main.o \
		iguana777.o \
		iguana_bundles.o \
		../basilisk/basilisk.o \
		optimized.a \
		secp256k1/secp256k1.a \
		../crypto777/libcrypto777.a
	$(LD) $(LDFLAGS) -o $@ $^
