/**
 * File:  dictionary.c
 * Author: ymiyamoto
 *
 * Created on Mon May  8 01:26:02 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problems.h"

#define NIL ((uint64_t)0xFFFFFFFFFFFFFFFF)

struct dictionary_t {
  uint64_t *data;
  size_t size;
};

dictionary_t dictionary_create(size_t size)
{
  dictionary_t dict = (dictionary_t)malloc(sizeof(struct dictionary_t));
  dict->data = (uint64_t *)malloc(sizeof(int64_t) * size);
  uint32_t i;
  for (i = 0; i < size; i++) {
    dict->data[i] = NIL;
  }

  dict->size = size;

  return dict;
}

void dictionary_destroy(dictionary_t dict)
{
  free(dict->data);
  free(dict);
  return;
}

static uint32_t calc_hash(uint64_t key, size_t size, uint32_t i)
{
  uint32_t h1 = key % size;
  uint32_t h2 = 1 + key % (size - 1);

  return (h1 + (i * h2)) % size;
}

bool dictionary_insert(dictionary_t dict, uint64_t data)
{
  uint32_t hash;
  uint32_t index = 0;

  do {
    hash = calc_hash(data, dict->size, index);
    index++;
  } while ((dict->data[hash] != NIL) && (index < dict->size));

  if (index < dict->size) {
    dict->data[hash] = data;
  } else {
    return false;
  }

  return true;
}

bool dictionary_search(dictionary_t dict, uint64_t data)
{
  uint32_t index = 0;

  while (index < dict->size) {
    uint32_t hash = calc_hash(data, dict->size, index);

    if (dict->data[hash] == NIL) {
      return false;
    }

    if (dict->data[hash] == data) {
      return true;
    }

    index++;
  }

  return false;
}

#if !defined(TEST)
static uint64_t calc_key(char data[])
{
  uint64_t ret = 0;

  size_t len = strlen(data);
  int32_t i = 0;
  for (i = 0; i < len; i++) {
    switch (data[i]) {
    case 'A':
      ret |= 1;
      break;
    case 'C':
      ret |= 2;
      break;
    case 'G':
      ret |= 3;
      break;
    case 'T':
      ret |= 4;
      break;
    }
    ret <<= 3;
  }

  return ret;
}

int32_t main(void)
{
  int32_t num;
  scanf("%d", &num);

  dictionary_t d = dictionary_create(1046527);

  int32_t i;
  for (i = 0; i < num; i++) {
    char command[20];
    char data[20];
    scanf("%s %s", command, data);
    uint64_t k = calc_key(data);
    if (command[0] == 'i') {
      dictionary_insert(d, k);
    } else {
      bool ret = dictionary_search(d, k);
      if (ret) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
  }

  dictionary_destroy(d);

  return 0;
}
#endif
