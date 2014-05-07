struct lock_t
{
  uint locked;
};

void lock_acquire(struct lock_t *lock);
void lock_release(struct lock_t *lock);
void lock_init(struct lock_t *lock);
int  lock_holding(struct lock_t *lock);
int  thread_create(void *(*start_routine)(void*), char* stack, int size, void *arg);
