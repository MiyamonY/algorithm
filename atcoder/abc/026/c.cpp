///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sat Jan 13 14:47:13 2018
//
#include <bits/stdc++.h>

using namespace std;

struct tree_t {
  int32_t parent;
  vector<int32_t> children;
};

int64_t traverse(vector<tree_t> members, int32_t n)
{
  if (members[n].children.size() == 0)
    return 1;
  else {
    int64_t ma = 0;
    int64_t mi = INT64_MAX;
    for (auto child : members[n].children) {
      int64_t ret = traverse(members, child);
      ma = max(ma, ret);
      mi = min(mi, ret);
    }

    return ma + mi + 1;
  }
}

int32_t main()
{
  uint32_t N;
  cin >> N;

  vector<tree_t> members(N + 1, {0, vector<int32_t>(0)});
  members[1].parent = -1;
  for (uint32_t i = 2; i <= N; i++) {
    uint32_t B;
    cin >> B;
    members[i].parent = B;
    members[B].children.push_back(i);
  }

  cout << traverse(members, 1) << endl;

  return 0;
}
