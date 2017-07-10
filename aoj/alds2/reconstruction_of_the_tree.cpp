///
// File:  reconstruction_of_the_tree.cpp
// Author: ymiyamoto
//
// Created on Mon Jul 10 23:45:03 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static uint32_t index = 0;
void reconstruction(vector<int32_t> pre, vector<int32_t> in, uint32_t l, uint32_t r, void (*postorder)(int32_t))
{
  if (l >= r) return;

  int32_t root = pre[index];
  index++;

  uint32_t root_index = 0;
  for (uint32_t i = 0; i < in.size(); i++) {
    if (in[i] == root) {
      root_index = i;
      break;
    }
  }

  reconstruction(pre, in, l, root_index, postorder);
  reconstruction(pre, in, root_index + 1, r, postorder);

  if (postorder != nullptr) {
    postorder(root);
  }
}

#if !defined(TEST)

static vector<int32_t> pre, in, post;

static void postorder(int32_t index)
{
  post.push_back(index);
}

int32_t main()
{
  uint32_t len;
  cin >> len;

  for (uint32_t i = 0; i < len; i++) {
    int32_t index;
    cin >> index;
    pre.push_back(index);
  }

  for (uint32_t i = 0; i < len; i++) {
    int32_t index;
    cin >> index;
    in.push_back(index);
  }

  reconstruction(pre, in, 0, in.size(), postorder);

  for (uint32_t i = 0; i < post.size(); i++) {
    if (i != 0) {
      cout << " ";
    }

    cout << post[i];
  }
  cout << endl;

  return 0;
}
#endif
