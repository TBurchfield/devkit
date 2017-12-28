#include "map.h"


/**
 * Compute FNV-1 hash.
 * @param   d               Data to hash.
 * @param   n               Number of bytes in data.
 * @return  Computed hash.
 */
#define FNV_OFFSET_BASIS    (0xcbf29ce484222325ULL)
#define FNV_PRIME           (0x100000001b3ULL)
uint64_t  hash(const void *d, size_t n) {
  uint64_t hash = FNV_OFFSET_BASIS;
  char * top = (char *)d;
  for (int i = 0; i < n; i++) {
    hash ^= (unsigned char)*top++;
    hash *= FNV_PRIME;
  }
  return hash;
}

