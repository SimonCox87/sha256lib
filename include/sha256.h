#ifndef SHA256_H
#define SHA256_H

#include <stdint.h>
#include <stdio.h>

void sha_init(void);
void sha_update(const uint8_t *data, size_t len);
void sha_final(uint32_t *hash);

#endif
