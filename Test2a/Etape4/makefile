COMP = g++ -Wall -D DEBUG

Test2a: Test2a.cpp Car.o Model.o
	$(COMP) Test2a.cpp Car.o Model.o -o Test2a

Car.o: Car.cpp Car.h Model.h
	$(COMP) Car.cpp -c

Model.o: Model.cpp Model.h
	$(COMP) Model.cpp -c
