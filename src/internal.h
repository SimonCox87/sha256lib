#include <stdint.h>
#ifndef SHA_COMMON_H
#define SHA_COMMON_H

// sha1 hash state struct
typedef struct {
    uint32_t h[5]; // current hash state (H0 .. H4)
    uint64_t total_len; // total message length in bytes
    uint8_t buffer[64]; // stores partial block
    uint32_t buffer_len; // number of bytes currently in buffer
} sha1_ctx;

// sha256 hash state struct
typedef struct {
    uint32_t h[8];
    uint64_t total_len;
    uint8_t buffer[64];
    uint32_t buffer_len;
} sha256_ctx;

// sha512 hash state struct
typedef struct {
    uint64_t h[8];
    uint64_t high_len; // high and low required to store full 128 bit length
    uint64_t low_len;
    uint8_t buffer[128];
    uint32_t buffer_len;
} sha512_ctx ;

// Common rotation algorithms that build message schedule SHA1 and SHA256
static inline uint32_t Ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ ((~x) & z);
}

static inline uint32_t Maj(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}

// Common rotation algorithms that build message schedule SHA384 and SHA512
static inline uint64_t Ch_512(uint64_t x, uint64_t y, uint64_t z) {
    return (x & y) ^ ((~x) & z);
}

static inline uint64_t Maj_512(uint64_t x, uint64_t y, uint64_t z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}

// Bit rotation functions SHA384 and SHA512
static inline uint64_t Rotr_512(uint64_t x, int n)
{
    return ((x >> n)) | (x << (64 - n));
}

static inline uint64_t big_sigma0_512(uint64_t x)
{
    return Rotr_512(x,28) ^ Rotr_512(x,34) ^ Rotr_512(x,39);
}

static inline uint64_t big_sigma1_512(uint64_t x)
{
    return Rotr_512(x,14) ^ Rotr_512(x,18) ^ Rotr_512(x,41);
}

static inline uint64_t small_sigma0_512(uint64_t x)
{
    return Rotr_512(x,1) ^ Rotr_512(x,8) ^ (x >> 7);
}

static inline uint64_t small_sigma1_512(uint64_t x)
{
    return Rotr_512(x,19) ^ Rotr_512(x,61) ^ (x >> 6);
}

// Parse a message into 32 bit blocks sha1 and sha256
void parse_message_1_256(const uint8_t *message, uint32_t *block);

// Parse a message into 64 bit blocks sha384 and sha512
void parse_message_384_512(const uint8_t *message, uint64_t *block);

// Padding for SHA-1
void sha1_pad(sha1_ctx *ctx, int byte_set);

// Padding for SHA-256
void sha256_pad(sha256_ctx *ctx, int byte_set);

// Padding for SHA-512
void sha512_pad(sha512_ctx *ctx, int byte_set);


#endif