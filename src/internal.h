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
    uint32_t h[8]; // current hash state (H0 .. H7)
    uint64_t total_len; // total message length in bytes
    uint8_t buffer[64]; // stores partial block
    uint32_t buffer_len; // number of bytes currently in buffer
} sha256_ctx;

// Common rotation algorithms that build message schedule
static inline uint32_t Ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ ((~x) & z);
}

static inline uint32_t Maj(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}

// Parse a message into 32 bit blocks sha1 and sha256
void parse_message_1_256(const uint8_t *message, uint32_t *block);

// Padding for SHA-1
void sha1_pad(sha1_ctx *ctx, int byte_set);

// Padding for SHA-256
void sha256_pad(sha256_ctx *ctx, int byte_set);

#endif