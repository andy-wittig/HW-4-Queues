#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

#include "queue.h"
#include "event.h"

template<class ItemType>
class arrayQueue : public QueueInterface<ItemType>
{
private:
    //index values to track front and back of queue
    int front;
	int back;
    int count;
    static const int ARRAY_SIZE = 10;
    ItemType array_queue[ARRAY_SIZE];
public:
    arrayQueue() : back(-1), front(-1), count(0) { }

    bool isEmpty() const
    {
        bool empty (count <= 0);
        return empty;
    }

    bool enqueue(const ItemType& newEntry)
    {
        count++;
        back = back++ % ARRAY_SIZE;
        array_queue[back] = newEntry;
        return true;
    }

    bool dequeue()
    {
        bool canDequeue = !isEmpty();
        if (canDequeue)
        {
            count--;
            front = front++ % ARRAY_SIZE;
            return true;
        }
        else { return false; }
    }

    ItemType peekFront() const
    {
        bool canPeek = !isEmpty();
        if (canPeek)
        {
            return array_queue[front+1];
        }
        else { throw "Item not found!"; }
    }

    void displayQueue()
    {
        for (int i = front+1; i <= back; i++)
        {
            cout << array_queue[i] << endl;
        }
    }

    ~arrayQueue() { }

};

#endif