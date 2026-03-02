#include "../include/sha.h"
#include <string.h>
#include <stdio.h>

// #define BUFF_LIMIT 4096
#define BUFF_LIMIT 262144

int main()
{
    /* Tests */

    /* Test 1 - SHA-1 'abc' */
    /* int i;
    const uint8_t message[3] = "abc";
    uint32_t hash_buffer[8] = {0};

    sha1_init();
    sha1_update(message, sizeof(message));
    sha1_final(hash_buffer);

    printf("hashed message: ");
    for (i = 0; i < 5; i++)
        printf("%08x", hash_buffer[i]);
    printf("\n"); */

    /* Test 2 - SHA-1 'abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq' */
    /* int i;
    const uint8_t message[56] = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
    uint32_t hash_buffer[8] = {0};

    sha1_init();
    sha1_update(message, sizeof(message));
    sha1_final(hash_buffer);

    printf("hashed message: ");
    for (i = 0; i < 5; i++)
        printf("%08x", hash_buffer[i]);
    printf("\n"); */

    /* Test 3 - SHA-1 'a' x 1,000,000 */
    /* int i;
    uint8_t message[1000000];
    uint32_t hash_buffer[8] = {0};

    for (i = 0; i < 1000000; i++)
        message[i] = 'a';

    sha1_init();
    sha1_update(message, sizeof(message));
    sha1_final(hash_buffer);

    printf("hashed message: ");
    for (i = 0; i < 5; i++)
        printf("%08x", hash_buffer[i]);
    printf("\n"); */

    /* Test 4 - SHA-256 'abc' */
    /* int i;
    const uint8_t message[3] = "abc";
    uint32_t hash_buffer[8] = {0};

    sha256_init();
    sha256_update(message, sizeof(message));
    sha256_final(hash_buffer);

    printf("hashed message: ");
    for (i = 0; i < 8; i++)
        printf("%08x", hash_buffer[i]);
    printf("\n"); */

    /* Test 5 SHA-256 'abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq' */
    /* int i;
    const uint8_t message[56] = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
    uint32_t hash_buffer[8] = {0};

    sha256_init();

    sha256_update(message, sizeof(message));

    sha256_final(hash_buffer);
    printf("hashed message: ");
    for (i = 0; i < 8; i++)
        printf("%08x", hash_buffer[i]);
    printf("\n");  */

    /* Test 6 - SHA-256 'a' x 1,000,000 */
    /* int i;
    uint8_t message[1000000];
    uint32_t hash_buffer[8] = {0};

    for (i = 0; i < 1000000; i++)
        message[i] = 'a';

    sha256_init();
    sha256_update(message, sizeof(message));
    sha256_final(hash_buffer);

    printf("hashed message: ");
    for (i = 0; i < 8; i++)
        printf("%08x", hash_buffer[i]);
    printf("\n"); */

    /* Test 7 SHA-256 Hashing file: ubuntu-24.04.3-desktop-amd64.iso  */
    /* int i;
    uint32_t hash_buffer[8] = {0};
    uint8_t buffer[BUFF_LIMIT] = {0};
    FILE *fp;
    const char *file_name = "../../Downloads/ubuntu-24.04.3-desktop-amd64.iso";

    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        fprintf(stderr, "File open failed.\n");
        return -1;
    }

    sha256_init();

    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        sha256_update(buffer, n);
    }

    sha256_final(hash_buffer);

    printf("hashed message: ");
    for (i = 0; i < 8; i++)
        printf("%08x", hash_buffer[i]);
    printf("\n");

    fclose(fp); */
    return 0;
}

/* 
    Test 1: a9993e364706816aba3e25717850c26c9cd0d89d
    Test 2: 84983e441c3bd26ebaae4aa1f95129e5e54670f1
    Test 3: 34aa973cd4c4daa4f61eeb2bdbad27316534016f
    Test 4: ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad
    Test 5: 248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1
    Test 6: cdc76e5c9914fb9281a1c7e284d73e67f1809a48a497200e046d39ccc7112cd0
    Test 7: faabcf33ae53976d2b8207a001ff32f4e5daae013505ac7188c9ea63988f8328 
*/
