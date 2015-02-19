#include <stdio.h>
#include <stdlib.h>

struct ListNode{                /* 構造体 */
  int data;
  struct ListNode *next;
};

void iter(void fun(int), struct ListNode *node_ptr)
{
  struct ListNode *next_ptr;

  next_ptr = node_ptr;

  do{
    fun(next_ptr->data);
    next_ptr = next_ptr->next;
  }while(next_ptr);

  return;
}

void print_int(int i)
{
  printf("%d", i);
  return;
}

int main(void)
{
  struct ListNode node = {0, NULL};
  struct ListNode *old = &node;
  struct ListNode *node_ptr;
  int i;

  for(i = 1; i < 10; i++){
    node_ptr = (struct ListNode*)malloc(sizeof(struct ListNode));

    node_ptr->data = i;
    node_ptr->next = old;

    old = node_ptr;
  }

  iter(print_int, node_ptr);

  return 0;
}
