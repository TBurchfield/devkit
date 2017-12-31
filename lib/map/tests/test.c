#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "../map.h"

int main(int argc, char ** argv) {
  // Defaults
  Map * map_default = map_create(0, 0);

  // non-defaults
  Map * map_non_default = map_create(10, 0.85);

  char key [BUFSIZ];
  char value [BUFSIZ];
  size_t test_to = 20000;

  // Maps each string of a number to the string of a number one larger.
  for (size_t i = 0; i < test_to; i++) {
    sprintf(key, "%zu key", i);
    sprintf(value, "%zu", i + 1);
    map_insert(map_default, key, value);
    map_insert(map_non_default, key, value);

    // Confirm load factors are not exceeded
    assert((double) (map_default->size) / map_default->capacity <= map_default->load_factor);
    assert((double) (map_non_default->size) / map_non_default->capacity <= map_non_default->load_factor);
  }

  for (size_t i = 0; i < test_to; i++) {
    sprintf(key, "%zu key", i);
    sprintf(value, "%zu", i + 1);

    // Confirm map stores as intended
    assert(strcmp((char*)map_search(map_default, key), value) == 0);
    assert(strcmp((char*)map_search(map_non_default, key), value) == 0);
  }
  for (size_t i = 0; i < test_to/2; i++) {
    sprintf(key, "%zu key", i);
    assert(map_remove(map_default, key));
    assert(!map_remove(map_default, key));
    assert(map_remove(map_non_default, key));
    assert(!map_remove(map_non_default, key));
  }
  map_delete(map_default);
  map_delete(map_non_default);
  return 0;
}
