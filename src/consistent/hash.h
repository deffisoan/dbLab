#ifndef _MURMURHASH3_H_
#define _MURMURHASH3_H_
#include <stdint.h>

uint32_t murmur3_32(const char *key, uint32_t len, uint32_t seed = 17);

#endif
