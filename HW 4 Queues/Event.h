#ifndef EVENT
#define EVENT

class Event
{
private:
	int time;
	int transaction_length;
	char type; //'A' is arrival, 'D' is departure
public:
	//constructor
	Event()
	{
		time = 0;
		transaction_length = 0;
		type = ' ';
	}
	Event(int eventTime, int transactionLength, char eventType)
		: time(eventTime), transaction_length(transactionLength), type(eventType) { }
	
	//overloaded operators
	bool operator <(const Event& otherEvent)
	{
		if (time == otherEvent.time)
		{
			if (type != otherEvent.type) //arbitrarily process arrivals first
			{
				return type < otherEvent.type;
			}
		}
		return time < otherEvent.time;
	}	
	
	void displayEvent()
	{
		cout << time << "   " << transaction_length << endl;
	}

	//getters
	int getTime() const
	{
		return time;
	}

	int getTransactionLength() const
	{
		return transaction_length;
	}

	char getType() const
	{
		return type;
	}
	//setters
};

#endif