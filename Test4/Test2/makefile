COMP = g++ -Wall -D DEBUG

Test4: Test4.o Person.o Actor.o Client.o
	$(COMP) Test4.o Person.o Actor.o Client.o -o Test4

Test4.o: Test4.cpp Person.h
	$(COMP) Test4.cpp -c

Person.o: Person.cpp Person.h
	$(COMP) Person.cpp -c

Client.o: Client.cpp Client.h Actor.h
	$(COMP) Client.cpp -c

Actor.o: Actor.cpp Actor.h Person.h
	$(COMP) Actor.cpp -c