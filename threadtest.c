#include "types.h"
#include "stat.h"
#include "user.h"
#include "linkedlist.h"
#include "thread.h"

int amount;

struct lock_t add;
struct lock_t threadfinish;

struct node* start = 0;

int threadbegin = 0;

void
add_int(int num)
{
  printf(1, "Attempting to add %d to linked list\n", num);
  lock_acquire(&add);
  ll_add(&start, num);
  lock_release(&add);
  printf(1, "Added %d to linked list\n", num);
}

void
thread_add(int begin)
{
  printf(1, "Starting child thread\n");
  int i;
  for(i=0; i<amount; i++)
    add_int(begin + i);
  printf(1, "Finishing child thread\n");
  exit();
}

int
main (int argc, char* argv[])
{
  amount = atoi(argv[1]);
  int i = 0;
  char* stack;
  lock_init(&add);
  
  if ((stack = malloc(4096)) > 0)
    thread_create((void*)&thread_add, stack, 4096, &i);
  else
    printf(1, "Failed to malloc(4096) for new thread stack\n");
  int begin = amount * 2;
  add_int(begin++);
  for(i=1; i<amount; i++)
    add_int(begin++);
  ll_print(start);
  printf(1, "Main thread waiting for child thread finish\n");
  wait();
  ll_print(start);
  exit();
}