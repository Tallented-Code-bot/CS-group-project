

#ifndef PRIORITY_QUEUE_BETTER
#define PRIORITY_QUEUE_BETTER

#include <queue>

template <class T> class PriorityQueueWrapper : public std::priority_queue<T> {
public:
  // Get an arbitrary index from the internal container, and possibly modify it.
  // This does NOT guarantee the ordering, you have to do that.
  T &operator[](int i) { return this->c[i]; }
};

#endif
