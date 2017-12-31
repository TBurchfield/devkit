#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>

typedef struct Entry Entry;
struct Entry {
  char *key;
  void *value;
  Entry *next;
};

typedef struct {
  Entry *buckets;
  size_t capacity;
  size_t size;
  double load_factor;
} Map;

#define DEFAULT_CAPACITY (1<<10)
#define DEFAULT_LOAD_FACTOR (0.900)

Map * map_create(size_t capacity, double load_factor);
void map_delete(Map * map);

void map_insert(Map * map, const char * key, void * value);
bool map_remove(Map * map, const char * key);
void * map_search(Map *map, const char *key);

void map_resize(Map * map, size_t new_capacity);

uint64_t hash(const void *d, size_t n);
