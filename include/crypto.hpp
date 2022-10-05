#ifndef __CRYPTO_H
#define __CRYPTO_H

#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <string>

void print_b2a_hex(const std::uint8_t* p, std::size_t n) {
    for (unsigned int i = 0; i < n; i++){
        printf("%02hhx", p[i]); // or just "%02X" if you are not using C11 or later
    }
    printf("\n");

    return;
}

void hmac_sha256(const char* data, unsigned int dlen, unsigned char *digest, unsigned int *dilen) {
    const char* m_hmac_key = "1234567890";
    unsigned int m_klen = 11;

    ::HMAC(
        ::EVP_sha256()
        , m_hmac_key
        , m_klen
        , (unsigned char *)data
        , dlen
        , digest
        , dilen
    );
    print_b2a_hex(digest, *dilen);

    return;
}
#endif // __CRYPTO_H