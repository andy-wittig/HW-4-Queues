#include <iostream>
#include <string>
using namespace std;

#include "arrayQueue.h"
#include "priorityQueue.h"
#include "event.h"

int getMenuChoice();

//Array Queue
void enqueueToArrayQueue(arrayQueue<string>&);
void dequeueToArrayQueue(arrayQueue<string>&);
void isArrayQueueEmpty(arrayQueue<string>&);
void displayArrayQueue(arrayQueue<string>&);
void peekArrayQueue(arrayQueue<string>&);

//Priority Queue
void enqueueToPriorityQueue(priorityQueue<Event>&);

int main()
{
	int menuChoice;
    arrayQueue<string> array_queue;
    priorityQueue<Event> priority_queue;

	do
	{
		menuChoice = getMenuChoice();

        switch (menuChoice) {
        case 1://Array Queue
            enqueueToArrayQueue(array_queue);
            break;
        case 2:
            dequeueToArrayQueue(array_queue);
            break;
        case 3:
            isArrayQueueEmpty(array_queue);
            break;
        case 4:
            displayArrayQueue(array_queue);
            break;
        case 5:
            peekArrayQueue(array_queue);
            break;
        case 6://Priority Queue
            enqueueToPriorityQueue(priority_queue);
            break;
        case 0:
            break;
        default:
            cout << endl << "Invalid option!" << endl;
            break;
        }
    } while (menuChoice != 0);

    return 0;
}

int getMenuChoice() {
    int userChoice;

    cout << endl << "~Array Queue Testing~" << endl;
    cout << "0. Exit." << endl;
    cout << "1. Enqueue item to array queue." << endl;
	cout << "2. Dequeue item from array queue." << endl;
	cout << "3. Check if array queue is empty." << endl;
    cout << "4. Display array queue." << endl;
    cout << "5. Peek top of array queue." << endl;
    cout << "~Priority Queue Testing~" << endl;
    cout << "6. Enqueue item to priority queue." << endl;

    cin >> userChoice;
    return userChoice;
}

//Array Queue Functions
void displayArrayQueue(arrayQueue<string>& queue)
{
    cout << "Array queue:" << endl;
    queue.displayQueue();
}

void enqueueToArrayQueue(arrayQueue<string>& queue)
{
    string newItem;

    cout << "What is the new item to add to the queue?" << endl;
    getline(cin, newItem);
    getline(cin, newItem);

    queue.enqueue(newItem);
}

void dequeueToArrayQueue(arrayQueue<string>& queue)
{
    cout << "Deleting the front item from the queue." << endl;
    queue.dequeue();
    cout << "Array queue:" << endl;
    queue.displayQueue();
}

void isArrayQueueEmpty(arrayQueue<string>& queue)
{
    bool arrayQueueEmpty = queue.isEmpty();
    if (arrayQueueEmpty) { cout << "The array queue is empty." << endl; }
    else { cout << "The array queue is holding items." << endl; }
}

void peekArrayQueue(arrayQueue<string>& queue)
{
    bool canPeek = !queue.isEmpty();
    if (canPeek) {
        cout << "The front item is: " << queue.peekFront() << endl;
    }
    else { cout << "The array queue is empty, and cannot peak!" << endl; }
}

//Priority Queue Functions
void enqueueToPriorityQueue(priorityQueue<Event>& queue)
{
    cout << "Enqueing four test items." << endl;

    Event event1(3, 1, 'D');
    Event event2(12, 200, 'A');
    Event event3(13, 400, 'A');
    
    queue.enqueue(event1);
    queue.enqueue(event2);
    queue.enqueue(event3);
    //should be 1, 400, 200

    queue.displayQueue();
}