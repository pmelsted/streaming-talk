#ifndef STREAM_HASH_H
#define STREAM_HASH_H
#include <limits>
#include <stdint.h>

static unsigned char siphash_key[16];
void init_siphash(unsigned int seed);

int crypto_auth( unsigned char *out, const unsigned char *in, unsigned long long inlen, const unsigned char *k );

template <typename T>
double hash(T x) {
  uint64_t d;
  crypto_auth((unsigned char*) &d, (const unsigned char*) &x, sizeof(x),siphash_key);
  return ((double) d) / std::numeric_limits<uint64_t>::max();
}


#endif
