#include <cstdlib>
#include <ctime>

#include "hash.h"

using namespace std;

void init_siphash(unsigned int seed) {
  srand(seed);
  for (int i = 0; i < 16; i++) {
    siphash_key[i] = (unsigned char) rand();
  }
}
