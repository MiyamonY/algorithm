///
// File:  dictionary.cpp
// Author: ymiyamoto
//
// Created on Sun Jul  2 10:29:55 2017
//

#include <cstdint>
#include <string.h>
#include <string>

using namespace std;

using dictionary_key_t = uint64_t;

#define NIL UINT64_MAX
#define DICT_SIZE 1046527

static dictionary_key_t dict[DICT_SIZE];

void dictionary_init()
{
  for (uint32_t i = 0; i < DICT_SIZE; i++) {
    dict[i] = NIL;
  }
}

static dictionary_key_t to_key(char str[], uint32_t i)
{
  dictionary_key_t key = 0;

  for (int32_t i = strlen(str); i >= 0; i--) {
    switch (str[i]) {
    case 'A':
      key |= 0b001;
      break;
    case 'C':
      key |= 0b010;
      break;
    case 'G':
      key |= 0b011;
      break;
    case 'T':
      key |= 0b100;
      break;
    }
    key <<= 3;
  }

  return ((key % DICT_SIZE) + i * (1 + (key % (DICT_SIZE - 1)))) % DICT_SIZE;
}

void dictionary_insert(char str[])
{
  uint32_t index = 0;
  while (true) {
    dictionary_key_t key = to_key(str, index);

    if (dict[key] == NIL) {
      dict[key] = key;
      return;
    } else if (dict[key] == key) {
      return;
    }

    index++;
  }
}

bool dictionary_find(char str[])
{
  uint32_t index = 0;

  while (true) {
    dictionary_key_t key = to_key(str, index);

    if (dict[key] == NIL) {
      return false;
    } else if (dict[key] == key) {
      return true;
    }

    index++;
  }
}

#if !defined(TEST)
#include <cstdio>
#include <iostream>
int32_t main()
{
  uint32_t num;
  cin >> num;

  dictionary_init();
  for (uint32_t i = 0; i < num; i++) {
    char command[10];
    char str[13];

    scanf("%s %s", command, str);
    switch (command[0]) {
    case 'i':
      dictionary_insert(str);
      break;
    case 'f':
      if (dictionary_find(str)) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
      break;
    }
  }

  return 0;
}
#endif
