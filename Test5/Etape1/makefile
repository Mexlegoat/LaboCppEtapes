COMP = g++ -Wall -D DEBUG

Test5: Test5.o OptionException.o Option.o Exception.o
	$(COMP) Test5.o OptionException.o Option.o Exception.o -o Test5

Test5.o: Test5.cpp OptionException.h Option.h
	$(COMP) Test5.cpp -c

Option.o: Option.cpp Option.h OptionException.h
	$(COMP) Option.cpp -c

OptionException.o: OptionException.cpp OptionException.h Exception.h
	$(COMP) OptionException.cpp -c

Exception.o: Exception.cpp Exception.h
	$(COMP) Exception.cpp -c