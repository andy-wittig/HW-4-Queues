#ifndef EVENT
#define EVENT

class Event
{
private:
	int time;
	char type; //'A' is arrival, 'D' is departure
public:
	//constructor
	Event()
	{
		time = 0;
		type = ' ';
	}
	Event(int eventTime, char eventType)
		: time(eventTime), type(eventType) { }
	
	//overloaded operators
	bool operator >(Event& otherEvent)
	{
		//someone who is departing takes priority over someone who is arriving
		if (type == 'D' && otherEvent.type == 'A') { return true; }
		else if (type == 'A' && otherEvent.type == 'D') { return false; }
		else if (type == 'A' && otherEvent.type == 'A')
		{
			if (time > otherEvent.time) { return true; }
			else { return false; }
		}
		else if (type == 'D' && otherEvent.type == 'D')
		{
			if (time > otherEvent.time) { return true; }
			else { return false; }
		}
	}

	//getters
	int getTime() const
	{
		return time;
	}

	char getType() const
	{
		return type;
	}
	//setters
};

#endif