#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "map.h"

int main(int argc, char ** argv) {
  // Defaults
  Map * map_default = map_create(0, 0);

  // non-defaults
  Map * map_non_default = map_create(10, 0.85);

  char key [BUFSIZ];
  char value [BUFSIZ];

  // Maps each string of a number to the string of a number one larger.
  for (int i = 0; i < 20; i++) {
    printf("Part 1: i = %d\n", i);
    sprintf(key, "%d", i);
    sprintf(value, "%d", i + 1);
    printf("Inserting into default\n");
    map_insert(map_default, key, value);
    printf("Inserting into nondefault\n");
    map_insert(map_non_default, key, value);

    // Confirm load factors are not exceeded
    assert((double) (map_default->size) / map_default->capacity < map_default->load_factor);
    // assert((double) (map_non_default->size) / map_non_default->capacity < map_non_default->load_factor);
  }

  for (int i = 0; i < 20; i++) {
    printf("Part 2: i = %d\n", i);
    sprintf(key, "%d", i);
    sprintf(value, "%d", i + 1);

    // Confirm map stores as intended
    assert(strcmp((char*)map_search(map_default, key), value) == 0);
    assert(strcmp((char*)map_search(map_non_default, key), value) == 0);
  }

  return 0;
}
