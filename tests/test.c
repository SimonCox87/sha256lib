#include "../include/sha.h"
#include <string.h>
#include <stdio.h>

#define BUFF_LIMIT 4096
// #define BUFF_LIMIT 262144

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

    /* Test 5 - SHA-256 'abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq' */
    /*int i;
    const uint8_t message[56] = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
    uint32_t hash_buffer[8] = {0};

    sha256_init();

    sha256_update(message, sizeof(message));

    sha256_final(hash_buffer);
    printf("hashed message: ");
    for (i = 0; i < 8; i++)
        printf("%08x", hash_buffer[i]);
    printf("\n"); */

    /* Test 6 - SHA-256 'a' x 1,000,000 */
    /*int i;
    uint8_t message[1000000];
    uint32_t hash_buffer[8] = {0};

    for (i = 0; i < 1000000; i++)
        message[i] = 'a';

    sha256_init();
    sha256_update(message, sizeof(message));
    sha256_final(hash_buffer);

    printf("hashed message: ");
    for (i = 0; i < 8; i++)
        printf("%08x\n", hash_buffer[i]); */

    /* Test 7 SHA-256 Hashing file: ubuntu-24.04.3-desktop-amd64.iso  */
    /*int i;
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

    fclose(fp);  */

    /* Test 8 - SHA512 'abc' */
    /* int i;
    const uint8_t message[3] = "abc";
    uint64_t hash_buffer[8] = {0};

    sha512_init();
    sha512_update(message, sizeof(message));
    sha512_final(hash_buffer);

    printf("hashed message: ");
    for (i = 0; i < 8; i++)
        printf("%016lx", hash_buffer[i]);
    printf("\n"); */

    /* Test 9 - SHA512 'abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu' */
    /* int i;
    const uint8_t message[112] = 
    "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu";
    uint64_t hash_buffer[8] = {0};

    sha512_init();
    sha512_update(message, sizeof(message));
    sha512_final(hash_buffer);

    printf("hashed message: ");
    for (i = 0; i < 8; i++)
        printf("%016lx", hash_buffer[i]);
    printf("\n"); */

    /* Test 10 -  SHA-512 'a' x 1,000,000 */
    /* int i;
    uint8_t message[1000000];
    uint64_t hash_buffer[8] = {0};

    for (i = 0; i < 1000000; i++)
        message[i] = 'a';

    sha512_init();
    sha512_update(message, sizeof(message));
    sha512_final(hash_buffer);

    printf("hashed message: ");
    for (i = 0; i < 8; i++)
        printf("%016lx", hash_buffer[i]);
    printf("\n"); */

    return 0;
}

/*
    Test 01: a9993e364706816aba3e25717850c26c9cd0d89d
    Test 02: 84983e441c3bd26ebaae4aa1f95129e5e54670f1
    Test 03: 34aa973cd4c4daa4f61eeb2bdbad27316534016f
    Test 04: ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad
    Test 05: 248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1
    Test 06: cdc76e5c9914fb9281a1c7e284d73e67f1809a48a497200e046d39ccc7112cd0
    Test 07: faabcf33ae53976d2b8207a001ff32f4e5daae013505ac7188c9ea63988f8328
    Test 08: ddaf35a193617abacc417349ae20413112e6fa4e89a97ea20a9eeee64b55d39a
             2192992a274fc1a836ba3c23a3feebbd454d4423643ce80e2a9ac94fa54ca49f
    Test 09: 8e959b75dae313da8cf4f72814fc143f8f7779c6eb9f7fa17299aeadb6889018
             501d289e4900f7e4331b99dec4b5433ac7d329eeb6dd26545e96e55b874be909
    Test 10: e718483d0ce769644e2e42c7bc15b4638e1f98b13b2044285632a803afa973eb
             de0ff244877ea60a4cb0432ce577c31beb009c5c2c49aa2e4eadb217ad8cc09b
*/
