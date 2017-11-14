#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct team_t {
  array<uint32_t, 11> wrongs;
  uint64_t penalty;
  uint32_t corrects;
  uint32_t id;
  team_t() : wrongs({}), penalty(0), corrects(0), id(0) {}

  void correct(uint32_t pid, uint32_t time) {
    corrects++;
    penalty += 1200 * wrongs[pid] + time;
  }

  void wrong(uint32_t pid) { wrongs[pid]++; }

  void println() { cout << id << " " << corrects << " " << penalty << endl; }

  bool operator<(const team_t &team) const {
    return corrects == team.corrects ? penalty < team.penalty
                                     : corrects > team.corrects;
  }
};

int32_t main() {
  while (true) {
    uint32_t T, P, R;
    cin >> T >> P >> R;
    if (T == 0) break;

    vector<team_t> teams(T + 1);
    for (uint32_t i = 1; i <= T; i++) {
      teams[i].id = i;
    }

    for (uint32_t i = 0; i < R; i++) {
      uint32_t tid, pid, t;
      string msg;
      cin >> tid >> pid >> t >> msg;
      if (msg == "WRONG") {
        teams[tid].wrong(pid);
      } else if (msg == "CORRECT") {
        teams[tid].correct(pid, t);
      }
    }

    stable_sort(teams.begin() + 1, teams.begin() + 1 + T);

    for (uint32_t i = 1; i <= T; i++) {
      teams[i].println();
    }
  }

  return 0;
}