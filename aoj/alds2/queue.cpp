///
// File:  queue.cpp
// Author: ymiyamoto
//
// Created on Fri Jun 30 07:11:28 2017
//

#include <cstdint>
#include <string>

#include "problems.hpp"

using namespace std;

#define ARRAY_SIZE 100000
process_t processes[ARRAY_SIZE];
uint32_t head, tail;

bool queue_dequeue(process_t &process)
{
  if (head == tail) return false;
  process = processes[head];
  head++;
  head %= ARRAY_SIZE;
  return true;
}

void queue_enqueue(process_t process)
{
  processes[tail] = process;
  tail++;
  tail %= ARRAY_SIZE;
}

bool queue_empty()
{
  if (head == tail)
    return true;
  else
    return false;
}

#if !defined(TEST)
#include <iostream>

int32_t main()
{
  uint32_t num, quantum;
  cin >> num >> quantum;

  for (uint32_t i = 0; i < num; i++) {
    string name;
    uint32_t time;
    cin >> name >> time;
    process_t process = {.name = name, .time = time};
    queue_enqueue(process);
  }

  uint32_t time = 0;
  while (!queue_empty()) {
    process_t process;
    queue_dequeue(process);
    uint32_t process_time = min(process.time, quantum);
    process.time -= process_time;
    time += process_time;
    if (process.time) {
      queue_enqueue(process);
    } else {
      cout << process.name << ' ' << time << endl;
    }
  }

  return 0;
}
#endif
