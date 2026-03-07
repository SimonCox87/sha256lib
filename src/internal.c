#include "internal.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>

// Parsing a message
void parse_message_1_256(const uint8_t *message, uint32_t *block)
{
    int b, w;
    uint32_t word;

    for (b = 0, w = 0; b < 64; b += 4, w++) {
        word = ((uint32_t)message[b]    << 24) | 
               ((uint32_t)message[b+1]  << 16) |
               ((uint32_t)message[b+2]  <<  8) |
                (uint32_t)message[b+3];
        block[w] = word;
    }
}

void parse_message_384_512(const uint8_t *message, uint64_t *block)
{
    int b, w;
    uint64_t word;

    for (b = 0, w = 0; b < 128; b += 8, w++) {
        word = ((uint64_t)message[b]    << 56) |
               ((uint64_t)message[b+1]  << 48) |
               ((uint64_t)message[b+2]  << 40) |
               ((uint64_t)message[b+3]  << 32) |
               ((uint64_t)message[b+4]  << 24) |
               ((uint64_t)message[b+5]  << 16) |
               ((uint64_t)message[b+6]  <<  8) |
                (uint64_t)message[b+7];
        block[w] = word;
    }
}

// Padding functions - for final block
void sha1_pad(sha1_ctx *ctx, int byte_set)
{
    uint32_t len = ctx->total_len;

    if (len >= 56) {
        ctx->buffer[len] = 0x80;
    } else {
        memset(ctx->buffer + len, 0, 64 - len);
        if (!byte_set) ctx->buffer[len] = 0x80;
        uint64_t bit_len = ctx->total_len * 8;
        ctx->buffer[56] = (bit_len >> 56) & 0xFF;    
        ctx->buffer[57] = (bit_len >> 48) & 0xFF;
        ctx->buffer[58] = (bit_len >> 40) & 0xFF;
        ctx->buffer[59] = (bit_len >> 32) & 0xFF;
        ctx->buffer[60] = (bit_len >> 24) & 0xFF;
        ctx->buffer[61] = (bit_len >> 16) & 0xFF;
        ctx->buffer[62] = (bit_len >> 8)  & 0xFF;
        ctx->buffer[63] =  bit_len        & 0xFF;
    }
}

void sha256_pad(sha256_ctx *ctx, int byte_set)
{
    uint32_t len = ctx->buffer_len;

    if (len >= 56) {
        ctx->buffer[len] = 0x80;
    } else {
        memset(ctx->buffer + len, 0, 64 - len);
        if (!byte_set) ctx->buffer[len] = 0x80;
        uint64_t bit_len = ctx->total_len * 8;
        ctx->buffer[56] = (bit_len >> 56) & 0xFF;    
        ctx->buffer[57] = (bit_len >> 48) & 0xFF;
        ctx->buffer[58] = (bit_len >> 40) & 0xFF;
        ctx->buffer[59] = (bit_len >> 32) & 0xFF;
        ctx->buffer[60] = (bit_len >> 24) & 0xFF;
        ctx->buffer[61] = (bit_len >> 16) & 0xFF;
        ctx->buffer[62] = (bit_len >> 8)  & 0xFF;
        ctx->buffer[63] =  bit_len        & 0xFF;
    }
}

// void sha_384_512_pad(uint32_t buff_len, uint64_t len_high, uint64_t len_low, uint8_t *buffer, int byte_set)
// {
//     uint32_t len = buff_len;

//     if (len >= 128) {
//         buffer[len] = 0x80;
//     } else {
//         memset(buffer + len, 0, 128 - len);
//         if (!byte_set) buffer[len] = 0x80;
//         uint64_t bit_len = len_low * 8;
//         buffer[112];


//     }
// }