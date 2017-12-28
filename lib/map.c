#include "map.h"
#include <stdio.h>

Map * map_create(size_t capacity, double load_factor) {
  Map * map = calloc(1, sizeof(Map));
  if (!map) {
    exit(1);
  }
  Entry * buckets = calloc(capacity, sizeof(Entry));
  if (!buckets) {
    exit(1);
  }
  map->buckets = buckets;
  map->size = 0;
  map->capacity = (capacity) ? capacity : DEFAULT_CAPACITY;
  map->load_factor = (load_factor) ? load_factor : DEFAULT_LOAD_FACTOR;
  return map;
}

void map_delete(Map * map) {
  Entry * del_ptr;
  Entry * temp;
  for (size_t i = 0; i < map->capacity; i++) {
    del_ptr = map->buckets[i].next;
    while (del_ptr != NULL) {
      temp = del_ptr->next;
      free(del_ptr->key);
      free(del_ptr);
      del_ptr = temp;
    }
  }
  free(map->buckets);
  free(map);
}

void map_insert(Map * map, const char * key, void * value) {
  Entry * new_entry = calloc(1, sizeof(Entry));
  if (!new_entry) {
    exit(1);
  }
  new_entry->key = strdup(key);
  if (!new_entry->key) {
    exit(1);
  }
  new_entry->value = value;
  if ((double) (map->size + 1) / map->capacity > map->load_factor) {
    map_resize(map, 2*map->capacity);
  }
  size_t index = hash(key, strlen(key)) % map->capacity;
  new_entry->next = map->buckets[index].next;
  map->buckets[index].next = new_entry;
  map->size++;
}

// Returns NULL on not found.
void * map_search(Map *map, const char *key) {
  size_t index = hash(key, strlen(key)) % map->capacity;
  Entry * node = map->buckets[index].next;
  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
      break;
    }
    node = node->next;
  }
  if (node != NULL) {
    return node->value;
  } else {
    printf("We didn't find it\n");
    return NULL;
  }
}

void map_resize(Map * map, size_t new_capacity) {
  printf("resizing\n");
  Entry * new_buckets = calloc(new_capacity, sizeof(Entry));
  if (!new_buckets) {
    exit(0);
  }
  Entry * iter;
  Entry * next;
  size_t index;
  for (size_t i = 0; i < map->capacity; i++) {
    iter = map->buckets[i].next;
    while (iter != NULL) {
      next = iter->next;

      // Insert iter to new_buckets
      index = hash(iter->key, strlen(iter->key)) % new_capacity;
      iter->next = new_buckets[index].next;
      new_buckets[index].next = iter;

      iter = next;
    }
  }
  free(map->buckets);
  map->buckets = new_buckets;
  map->capacity = new_capacity;
}
