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
    priorityQueue() : back(-1), front(0), count(0) { }

    bool isEmpty() const
    {
        bool empty(count <= 0);
        return empty;
    }

    bool enqueue(ItemType& newEntry)
    {
        if (!isEmpty())
        {
            for (int i = 0; i <= count; i++) //loop through entire usable queue
            {
                int current_position = front + i % ARRAY_SIZE;
                if (newEntry > priority_queue[current_position])
                {
                    count++;
                    back = (back + 1) % ARRAY_SIZE; //extend array
                    for (int i = back; i > current_position; i--) { //shift array and add new element in
                        priority_queue[i] = priority_queue[i - 1];
                    }
                    priority_queue[i] = newEntry;
                    return true;
                }
            }
            //lowest priority
            count++;
            back = (back + 1) % ARRAY_SIZE;
            priority_queue[back] = newEntry;
            return true;
        }
        else //priority queue is empty
        {
            count++;
            back++;
            priority_queue[back] = newEntry;
            return true;
        }
    }

    bool dequeue()
    {
        return true;
    }

    ItemType peekFront() const
    {
        bool canPeek = !isEmpty();
        if (canPeek)
        {
            return priority_queue[front];
        }
        else { throw "Item not found!"; }
    }

    void displayQueue()
    {
        for (int i = 0; i < count; i++)
        {
            cout << priority_queue[(front + i) % ARRAY_SIZE].getDuration() << endl;
        }
    }

    ~priorityQueue() { }
};

#endif