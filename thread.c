#include "types.h"
#include "defs.h"
#include "param.h"
#include "x86.h"
#include "mmu.h"
#include "proc.h"
#include "thread.h"
#include "stat.h"

void
lock_init(struct lock_t *lock)
{
  lock->locked = 0;
}

void
lock_acquire(struct lock_t *lock)
{
  while(xchg(&lock->locked, 1) != 0)
  {}
}

void
lock_release(struct lock_t *lock)
{
  xchg(&lock->locked, 0);
}

int
lock_holding(struct lock_t *lock)
{
  return lock->locked;
}

int
thread_create(void *(*start_routine)(void*), char* stack, int size, void *arg)
{
  int pid = clone(stack, size);
  if (pid == 0)
  {
    (*start_routine)(arg);
    exit();
  }
  return pid;
}
