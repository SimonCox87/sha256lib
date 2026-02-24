#ifndef SHA256_H
#define SHA256_H

#include <stdint.h>
#include <stdio.h>

void sha256_init(void);
void sha256_update(const uint8_t *data, size_t len);
void sha256_final(uint32_t *hash);

// Add other Sha variants in here

#endif
