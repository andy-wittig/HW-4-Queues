//like a tsa line, highest priority goes straight to the front.
//someone who is departing takes priority over someone who is arriving
//through a forloop continue to move down queue until the priority is met.

#ifndef PRIORITY_ARRAY_QUEUE
#define PRIORITY_ARRAY_QUEUE

#include "arrayQueue.h"
#include "event.h"

template<class ItemType>
class priorityQueue : public arrayQueue<ItemType>
{
private:
    int front;
    int back;
    int count;
    static const int ARRAY_SIZE = 10;
    ItemType priority_queue[ARRAY_SIZE];
public:
    priorityQueue() : back(-1), front(-1), count(0) { }

    bool isEmpty() const
    {
        bool empty(count <= 0);
        return empty;
    }
};

#endif