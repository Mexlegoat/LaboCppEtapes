COMP = g++ -Wall -D DEBUG

Test2b: Option.o Test2b.o
		$(COMP) Option.o Test2b.o -o Test2b

Option.o: Option.cpp Option.h
		$(COMP) Option.cpp -c

Test2b.o: Test2b.cpp Option.h
		$(COMP) Test2b.cpp -c