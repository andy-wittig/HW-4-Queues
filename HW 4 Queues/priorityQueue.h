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
    static const int ARRAY_SIZE = 100;
    ItemType priority_queue[ARRAY_SIZE];
public:
    priorityQueue() : back(-1), front(0), count(0) { }

    bool isEmpty() const
    {
        return count <= 0;
    }

    bool enqueue(ItemType& newEntry)
    {
        if (count >= ARRAY_SIZE) { return false; } //array at capacity
        
        for (int i = 0; i < count; i++)
        {
            int current_position = (front + i) % ARRAY_SIZE;
            if (newEntry < priority_queue[current_position])
            {
                count++;
                back = (back + 1) % ARRAY_SIZE; //extend array
                int temp = back;
                while (temp != current_position)
                {
                    priority_queue[temp] = priority_queue[(temp - 1 + ARRAY_SIZE) % ARRAY_SIZE];
                    temp = (temp - 1 + ARRAY_SIZE) % ARRAY_SIZE;
                }
                priority_queue[current_position] = newEntry;
                return true;
            }
        }
        count++;
        back = (back + 1) % ARRAY_SIZE;
        priority_queue[back] = newEntry;
        return true;
    }

    bool dequeue()
    {
        bool canDequeue = !isEmpty();
        if (canDequeue)
        {
            count--;
            front = (front + 1) % ARRAY_SIZE;
            return true;
        }
        else { return false; }
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
        cout << "Priority Queue:" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << priority_queue[(front + i) % ARRAY_SIZE].getTime() 
                << ", type:" << priority_queue[(front + i) % ARRAY_SIZE].getType() << endl;
        }
    }

    ~priorityQueue() { }
};

#endif