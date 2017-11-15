#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

string lshift(string &msg) {
  string front{msg[0]};
  return msg.substr(1, msg.size() - 1) + front;
}

string rshift(string &msg) {
  string back{msg[msg.size() - 1]};
  return back + msg.substr(0, msg.size() - 1);
}

void add_num(string &msg, int32_t num) {
  for (uint32_t i = 0; i < msg.size(); i++) {
    if ('0' <= msg[i] && msg[i] <= '9') {
      msg[i] += num;
      if (msg[i] < '0') msg[i] = '9';
      if ('9' < msg[i]) msg[i] = '0';
    }
  }
}

string swap(string &msg) {
  string front = msg.substr(0, msg.size() / 2);
  if (msg.size() % 2 == 0) {
    string back = msg.substr(msg.size() / 2, msg.size() - msg.size() / 2);
    return back + front;
  } else {
    string center{msg[msg.size() / 2]};
    string back =
        msg.substr(msg.size() / 2 + 1, msg.size() - (msg.size() / 2 + 1));
    return back + center + front;
  }
}

int32_t main() {
  uint32_t n;
  cin >> n;
  for (uint32_t _ = 0; _ < n; _++) {
    string mem;
    cin >> mem;
    string msg;
    cin >> msg;

    for (int32_t i = mem.size() - 1; i >= 0; i--) {
      switch (mem[i]) {
        case 'A':
          reverse(msg.begin(), msg.end());
          break;
        case 'P':
          add_num(msg, -1);
          break;
        case 'M':
          add_num(msg, +1);
          break;
        case 'J':
          msg = rshift(msg);
          break;
        case 'C':
          msg = lshift(msg);
          break;
        case 'E':
          msg = swap(msg);
          break;
      }
    }

    cout << msg << endl;
  }

  return 0;
}