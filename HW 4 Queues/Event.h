#ifndef EVENT
#define EVENT

class Event
{
private:
	int time;
	int duration;
	char type; //'A' is arrival, 'D' is departure
public:
	//constructor
	Event() 
	{
		time = 0;
		duration = 0;
		type = ' ';
	}
	Event(int eventTime, int eventDuration, char eventType)
		: time(eventTime), duration(eventDuration), type(eventType) { }
	
	//overloaded operators
	bool operator >(Event& otherEvent)
	{
		//someone who is departing takes priority over someone who is arriving
		if (type == 'D' && otherEvent.type == 'A') { return true; }
		else if (type == 'A' && otherEvent.type == 'D') { return false; }
		else if (type == 'A' && otherEvent.type == 'A')
		{
			if (duration > otherEvent.duration) { return true; }
			else { return false; }
		}
		else if (type == 'D' && otherEvent.type == 'D')
		{
			if (duration > otherEvent.duration) { return true; }
			else { return false; }
		}
	}

	//getters and setters
	int getDuration() const
	{
		return duration;
	}
};

#endif