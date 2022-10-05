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
    Logger::log(LogLevel::DEBUG, "[DC Proxy] msg hmac_sha256 digest: " + b2a_hex(digest, *dilen));

    return;
}
#endif // __CRYPTO_H