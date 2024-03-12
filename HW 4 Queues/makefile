bank_sim: main.o 
	g++ main.o -o bank_sim

main.o: main.cpp arrayQueue.h priorityQueue.h Event.h
	g++ -c main.cpp

clean:
	rm *.o bank_sim