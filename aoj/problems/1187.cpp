#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct team_t {
  array<uint32_t, 11> times;
  array<bool, 11> corrects;
  uint32_t id;
  team_t() : times({}), corrects({}), id(0) {}

  uint32_t get_corrects() {
    uint32_t count = 0;
    for (uint32_t i = 0; i < corrects.size(); i++) {
      if (corrects[i]) {
        count++;
      }
    }
    return count++;
  }

  uint32_t get_penalty() {
    uint32_t penalty = 0;
    for (uint32_t i = 0; i < corrects.size(); i++) {
      if (corrects[i]) {
        penalty += times[i];
      }
    }
    return penalty;
  }

  bool operator==(team_t &team) {
    if (this->get_corrects() == team.get_corrects()) {
      return this->get_penalty() == team.get_penalty();
    }
    return false;
  }

  bool operator<(team_t &team) {
    if (this->get_corrects() == team.get_corrects()) {
      if (this->get_penalty() == team.get_penalty()) {
        return id > team.id;
      } else {
        return this->get_penalty() < team.get_penalty();
      }
    } else {
      return team.get_corrects() < this->get_corrects();
    }
  }

  void correct(uint32_t pid, uint32_t time) {
    corrects[pid] = true;
    times[pid] += time;
  }

  void println() {
    cout << id << " " << get_corrects() << " " << get_penalty() << endl;
  }

  void wrong(uint32_t pid) { times[pid] += 20; }
};

int32_t main() {
  while (true) {
    uint32_t M, T, P, R;
    cin >> M >> T >> P >> R;
    if (M == 0) break;

    vector<team_t> teams(T + 1);
    for (uint32_t i = 0; i < teams.size(); i++) {
      teams[i].id = i;
    }

    for (uint32_t i = 0; i < R; i++) {
      uint32_t m, t, p, j;
      cin >> m >> t >> p >> j;
      if (j == 0) {
        teams[t].correct(p, m);
      } else {
        teams[t].wrong(p);
      }
    }

    sort(teams.begin() + 1, teams.begin() + T + 1);

    for (uint32_t i = 1; i < T; i++) {
      cout << teams[i].id;
      if (teams[i] == teams[i + 1]) {
        cout << "=";
      } else {
        cout << ",";
      }
    }
    cout << teams[T].id;
    cout << endl;
  }

  return 0;
}
