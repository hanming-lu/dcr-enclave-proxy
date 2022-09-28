# Copyright (c) Open Enclave SDK contributors.
# Licensed under the MIT License.

include ../../config.mk

CFLAGS=$(shell pkg-config oehost-$(COMPILER) --cflags)
LDFLAGS=$(shell pkg-config oehost-$(COMPILER) --libs)
INCDIR=$(shell pkg-config oehost-$(COMPILER) --variable=includedir)

build:
	@ echo "Compilers used: $(CC), $(CXX)"
	oeedger8r ../dcr_proxy.edl --untrusted \
		--search-path $(INCDIR) \
		--search-path $(INCDIR)/openenclave/edl/sgx
	$(CC) -g -c $(CFLAGS) host.c
	$(CC) -g -c $(CFLAGS) dcr_proxy_u.c
	$(CC) -o dcr_proxyhost dcr_proxy_u.o host.o $(LDFLAGS)

clean:
	rm -f dcr_proxyhost host.o dcr_proxy_u.o dcr_proxy_u.c dcr_proxy_u.h dcr_proxy_args.h
