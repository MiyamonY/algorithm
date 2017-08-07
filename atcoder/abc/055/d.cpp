///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Mon Aug  7 19:38:26 2017
//

#include <assert.h>
#include <cstdint>
#include <iostream>

using namespace std;

#define MAX_ANIMALS 100000
char animals[MAX_ANIMALS];
char answers[MAX_ANIMALS];

void decide_animals(uint64_t N)
{
  for (uint64_t i = 1; i < N - 1; i++) {
    switch (animals[i]) {
    case 'S':
      if (answers[i] == 'o') {
        animals[i + 1] = animals[i - 1];
      } else {
        animals[i + 1] = animals[i - 1] == 'S' ? 'W' : 'S';
      }
      break;
    case 'W':
      if (answers[i] == 'x') {
        animals[i + 1] = animals[i - 1];
      } else {
        animals[i + 1] = animals[i - 1] == 'S' ? 'W' : 'S';
      }
      break;
    default:
      assert(0);
      break;
    }
  }
}

bool is_valid_at(uint64_t N, uint64_t at)
{
  uint64_t pre = at - 1;
  if (at == 0) {
    pre = N - 1;
  }

  switch (animals[at]) {
  case 'S':
    if (answers[at] == 'o') {
      return animals[pre] == animals[(at + 1) % N];
    } else {
      return animals[pre] != animals[(at + 1) % N];
    }
    break;
  case 'W':
    if (answers[at] == 'x') {
      return animals[pre] == animals[(at + 1) % N];
    } else {
      return animals[pre] != animals[(at + 1) % N];
    }
    break;
  default:
    assert(0);
    break;
  }
  assert(0);
  return false;
}

bool check_validity(uint64_t N)
{
  if (is_valid_at(N, 0) && is_valid_at(N, N - 1)) {
    return true;
  }

  return false;
}

void valid(uint64_t N)
{
  for (uint64_t i = 0; i < N; i++) {
    cout << animals[i];
  }
  cout << endl;
}

void invalid()
{
  cout << -1 << endl;
}

int32_t main()
{
  uint64_t N;
  cin >> N;

  for (uint64_t i = 0; i < N; i++) {
    char answer;
    cin >> answer;
    answers[i] = answer;
  }

  animals[0] = 'S';
  animals[1] = 'S';
  decide_animals(N);
  if (check_validity(N)) {
    valid(N);
    return 0;
  }

  animals[0] = 'S';
  animals[1] = 'W';
  decide_animals(N);
  if (check_validity(N)) {
    valid(N);
    return 0;
  }

  animals[0] = 'W';
  animals[1] = 'S';
  decide_animals(N);
  if (check_validity(N)) {
    valid(N);
    return 0;
  }

  animals[0] = 'W';
  animals[1] = 'W';
  decide_animals(N);
  if (check_validity(N)) {
    valid(N);
    return 0;
  }

  invalid();

  return 0;
}
