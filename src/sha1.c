// Source code for sha1
#include "../include/sha.h"
#include "internal.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>

// Used in Process function - circular queue
#define MASK 0x0F

// H constants
static const uint32_t H[5] = {
    0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476, 0xc3d2e1f0
};

// K constants
static const uint32_t K[4] = {
    0x5a827999, 0x6ed9eba1, 0x8f1bbcdc, 0xca62c1d6
};


// Initialise hash state variable
static sha1_ctx ctx;

// Preprocessing Functions
static void process(uint8_t *data);

// Bit manipulation functions
static inline uint32_t Parity(uint32_t x, uint32_t y, uint32_t z);
static inline uint32_t Rotl(uint32_t x, int n);

// Initialise context state struct
void sha1_init(void)
{
    ctx.h[0] = H[0];
    ctx.h[1] = H[1]; 
    ctx.h[2] = H[2]; 
    ctx.h[3] = H[3]; 
    ctx.h[4] = H[4]; 
    ctx.buffer_len = 0;
    ctx.total_len = 0;
    memset(ctx.buffer, 0, 64);
}

// Process the blocks
void sha1_update(const uint8_t *data, size_t len)
{  
    ctx.total_len += len;

    if (ctx.buffer_len > 0) {
        size_t space = 64 - ctx.buffer_len;
        size_t to_copy = len < space ? len : space;

        memcpy(ctx.buffer + ctx.buffer_len, data, to_copy);

        ctx.buffer_len += to_copy;
        data += to_copy;
        len -= to_copy;

        if (ctx.buffer_len == 64) {
            process(ctx.buffer);
            ctx.buffer_len = 0;
        }
    }

    while(len >= 64) {
        process((uint8_t *) data);
        data += 64;
        len -= 64;
    }

    if (len > 0) {
        memcpy(ctx.buffer, data, len);
        ctx.buffer_len = len;
    }
}

// Build and process final block(s)
void sha1_final(uint32_t *hash)
{
    int i, b_set = 0;

    sha1_pad(&ctx, b_set);
    process(ctx.buffer);

    if (ctx.buffer_len >= 56) {
        b_set = 1;
        ctx.buffer_len = 0;
        sha1_pad(&ctx, b_set);
        process(ctx.buffer);
    }
    
    for (i = 0; i < 5; i++) 
        hash[i] = ctx.h[i];
}

// Process a block
static void process(uint8_t *data)
{
    uint32_t t;
    uint32_t a, b, c, d, e, T;

    uint32_t block[16] = {0};
    parse_message_1_256(data, block);
    uint32_t W[16]; //Message Schedule

    for (t = 0; t < 16; t++)
        W[t] = block[t];

    a = ctx.h[0];
    b = ctx.h[1];
    c = ctx.h[2];
    d = ctx.h[3];
    e = ctx.h[4];
    
    for (t = 0; t < 80; t++) {
        if (t >= 16) {
          W[t & MASK] = 
            Rotl(
                W[(t - 3)  & MASK] ^ 
                W[(t - 8)  & MASK] ^
                W[(t - 14) & MASK] ^
                W[(t - 16) & MASK],
            1);
        }

        // Create working variables
        // Generate temp (T) value
        if (t >= 0 && t <= 19)
            T = Rotl(a,5) + Ch(b,c,d) + e + K[0] + W[t & MASK];
        if (t >= 20 && t <= 39)
            T = Rotl(a,5) + Parity(b,c,d) + e + K[1] + W[t & MASK];
        if (t >= 40 && t <= 59)
            T = Rotl(a,5) + Maj(b,c,d) + e + K[2] + W[t & MASK];
        if (t >= 60 && t <= 79)
            T = Rotl(a,5) + Parity(b,c,d) + e + K[3] + W[t & MASK];
        
        // Create working variables a ... e
        e = d;
        d = c;
        c = Rotl(b, 30);
        b = a;
        a = T;
    }
    ctx.h[0] += a;
    ctx.h[1] += b;
    ctx.h[2] += c;
    ctx.h[3] += d;
    ctx.h[4] += e;
}

// Sha1 specific function to help build message schedule
static inline uint32_t Parity(uint32_t x, uint32_t y, uint32_t z)
{
    return x ^ y ^ z;
}

// Rotation functions
static inline uint32_t Rotl(uint32_t x, int n)
{
    return (x << n) | (x >> (32 - n));
}

