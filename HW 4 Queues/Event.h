#ifndef EVENT
#define EVENT

template<class ItemType>
class Event
{
private:
	int time;
	int duration;
	char type;
public:
	//constructor
	Event(int eventTime, int eventDuration, char eventType)
		: time(eventTime), duration(eventDuration), type(eventType) { }
	
	//overloaded operators
	bool operator >(const Event& otherEvent)
	{
		if (type == 'D' && otherEvent.type == 'A')
		{
			if (duration > otherEvent.duration) { return true; }
		}
		else if (typw == 'D')
		{

		}
	}
};

#endif