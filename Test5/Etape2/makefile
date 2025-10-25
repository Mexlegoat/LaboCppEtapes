COMP = g++ -Wall -D DEBUG
src = ./src
include = ./Include
Test5: Test5.o OptionException.o Option.o Exception.o Car.o Model.o
	$(COMP) Test5.o OptionException.o Option.o Exception.o Car.o Model.o -o Test5

Test5.o: Test5.cpp OptionException.h Option.h Car.h 
	$(COMP) Test5.cpp -c

Option.o: Option.cpp Option.h OptionException.h
	$(COMP) Option.cpp -c

OptionException.o: OptionException.cpp OptionException.h Exception.h
	$(COMP) OptionException.cpp -c

Exception.o: Exception.cpp Exception.h
	$(COMP) Exception.cpp -c
Car.o: Car.cpp Car.h Model.h OptionException.h Option.h
	$(COMP) Car.cpp -c

Model.o: Model.cpp Model.h 
	$(COMP) Model.cpp -c
clean:
	rm -f *.o
clobber: clean
	rm -f Test5
