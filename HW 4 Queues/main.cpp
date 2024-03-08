#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#include "arrayQueue.h"
#include "priorityQueue.h"
#include "event.h"

//Array queue function declatrations
void enqueueToArrayQueue(arrayQueue<Event>&);
void dequeueToArrayQueue(arrayQueue<Event>&);
void isArrayQueueEmpty(arrayQueue<Event>&);
void displayArrayQueue(arrayQueue<Event>&);
void peekArrayQueue(arrayQueue<Event>&);

//Priority queue function declatrations
void enqueueToPriorityQueue(priorityQueue<Event>&);
void dequeuePriorityQueue(priorityQueue<Event>&);

//Bank Simulation function declatration
void bankSimulation(vector<int> arrivalTime, vector<int> transactionLength);

int getMenuChoice();

int main()
{
    //Read input.txt file
    ifstream input_file;
    input_file.open("input.txt");
    vector<int> arrival_vect;
    vector<int> transaction_vect;
    string get_line;

    while (getline(input_file, get_line))
    {
        stringstream stream_line(get_line);
        int elem_1, elem_2;
        stream_line >> elem_1 >> elem_2;
        arrival_vect.push_back(elem_1);
        transaction_vect.push_back(elem_2);
    }

    //Initiate class instances
    arrayQueue<Event> array_queue;
    priorityQueue<Event> priority_queue;

    //Menu logic
    int menuChoice;
	do
	{
		menuChoice = getMenuChoice();

        switch (menuChoice) {
        case 1://Array queue
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
        case 6://Priority queue
            enqueueToPriorityQueue(priority_queue);
            break;
        case 7:
            dequeuePriorityQueue(priority_queue);
            break;
        case 8: //Bank simulation
            bankSimulation(arrival_vect, transaction_vect);
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

    cout << "\n0. Exit." << endl;
    cout << "1. Enqueue item to array queue." << endl;
	cout << "2. Dequeue item from array queue." << endl;
	cout << "3. Check if array queue is empty." << endl;
    cout << "4. Display array queue." << endl;
    cout << "5. Peek top of array queue." << endl;
    cout << "~Priority Queue Testing~" << endl;
    cout << "6. Enqueue items to the priority queue." << endl;
    cout << "7. Dequeue items from the priority queue." << endl;
    cout << "~Bank Simulation~" << endl;
    cout << "8. Run bank simulation." << endl;

    cin >> userChoice;
    return userChoice;
}

//Array queue functions
void displayArrayQueue(arrayQueue<Event>& queue)
{
    cout << "Array queue:" << endl;
    queue.displayQueue();
}

void enqueueToArrayQueue(arrayQueue<Event>& queue)
{
    cout << "What value would you like to enqueue?" << endl;
    int time;
    cin >> time;
    Event event(time, 0, 'A');
    queue.enqueue(event);
    queue.displayQueue();
}

void dequeueToArrayQueue(arrayQueue<Event>& queue)
{
    cout << "Deleting the front item from the queue." << endl;
    queue.dequeue();
    cout << "Array queue:" << endl;
    queue.displayQueue();
}

void isArrayQueueEmpty(arrayQueue<Event>& queue)
{
    bool arrayQueueEmpty = queue.isEmpty();
    if (arrayQueueEmpty) { cout << "The array queue is empty." << endl; }
    else { cout << "The array queue is holding items." << endl; }
}

void peekArrayQueue(arrayQueue<Event>& queue)
{
    bool canPeek = !queue.isEmpty();
    if (canPeek) {
        cout << "The front item is: " << queue.peekFront().getTime() << endl;
    }
    else { cout << "The array queue is empty, and cannot peak!" << endl; }
}

//Priority queue functions
void enqueueToPriorityQueue(priorityQueue<Event>& queue)
{
    cout << "What value would you like to enqueue?" << endl;
    int time;
    cin >> time;
    Event event(time, 0, 'A');
    queue.enqueue(event);
    queue.displayQueue();
}

void dequeuePriorityQueue(priorityQueue<Event>& queue)
{
    cout << "Deleting the front item from the queue." << endl;
    queue.dequeue();
    queue.displayQueue();
}

//Bank simulation functions
void bankSimulation(vector<int> arrivalTime, vector<int> transactionLength)
{
    priorityQueue<Event> bankPQueue;
    arrayQueue<Event> bankLine;

    //Init bank priority queue with arrival events
    for (int i = 0; i < arrivalTime.size(); i++) 
    {
        Event arrival_event(arrivalTime[i], transactionLength[i], 'A');
        arrival_event.displayEvent();
        bankPQueue.enqueue(arrival_event);
    }

    bool tellerAvailable = true;

    while (!bankPQueue.isEmpty()) //events remain to be processed
    {
        Event newEvent = bankPQueue.peekFront();
        int currentTime = newEvent.getTime();
        int currentTransactionLength = newEvent.getTransactionLength();
        
        if (newEvent.getType() == 'A') //process arrival event
        {
            bankPQueue.dequeue(); //remove arrival event
            //update bank line
            if (bankLine.isEmpty() && tellerAvailable)
            {
                int departure_time = currentTime + currentTransactionLength;
                Event departure_event(departure_time, 0, 'D');
                bankPQueue.enqueue(departure_event);
                tellerAvailable = false;
            }
            else { bankLine.enqueue(newEvent); }
            //bankPQueue.displayQueue();
            //bankLine.displayQueue();
        }
        else //process departure event
        {
            bankPQueue.dequeue(); //remove departure event
            if (!bankLine.isEmpty())
            {
                Event customer = bankLine.peekFront();
                bankLine.dequeue();
                int departure_time = currentTime + customer.getTransactionLength();
                Event departure_event(departure_time, 0, 'D');
                bankPQueue.enqueue(departure_event);
            }
            else { tellerAvailable = true; }
            //bankPQueue.displayQueue();
            //bankLine.displayQueue();
        }
    }
}