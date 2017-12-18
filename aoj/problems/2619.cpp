///
// File:  2619.cpp
// Author: ymiyamoto
//
// Created on Sat Dec  2 21:02:56 2017
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct tree_t {
  string str;
  vector<uint32_t> children;
};

void preorder(vector<tree_t> tree, uint32_t i, uint32_t depth)
{
  cout << string(depth, '.') << tree[i].str << endl;
  for (uint32_t j = 0; j < tree[i].children.size(); j++) {
    preorder(tree, tree[i].children[j], depth + 1);
  }
}

int32_t main()
{
  uint32_t N;
  cin >> N;

  vector<tree_t> tree(N + 1);

  for (uint32_t i = 1; i <= N; i++) {
    uint32_t n;
    string str;
    cin >> n >> str;
    tree[i].str = str;
    tree[n].children.push_back(i);
  }

  preorder(tree, 1, 0);

  return 0;
}
