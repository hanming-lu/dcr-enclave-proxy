#ifndef __CRYPTO_H
#define __CRYPTO_H

#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <string>

#include "logging.hpp"

std::string b2a_hex(const std::uint8_t* p, std::size_t n) {
    static const char hex[] = "0123456789abcdef";
    std::string res;
    res.reserve(n * 2);

    for (auto end = p + n; p != end; ++p) {
        const std::uint8_t v = (*p);
        res += hex[(v >> 4) & 0x0F];
        res += hex[v & 0x0F];
    }

    return res;
}

std::string hmac_sha256(
    const char* key, unsigned int klen,
    const char* data, unsigned int dlen) 
{
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int dilen;
    ::HMAC(
        ::EVP_sha256()
        , key
        , klen
        , (unsigned char *)data
        , dlen
        , digest
        , &dilen
    );

    return b2a_hex(digest, dilen);
}
#endif // __CRYPTO_H