COMP = g++ -Wall -D DEBUG

Test3: Model.o Car.o Option.o Test3.o
		$(COMP) Model.o Car.o Option.o Test3.o -o Test3

Model.o: Model.cpp Model.h
		$(COMP) Model.cpp -c

Car.o: Car.cpp Model.h Car.h
		$(COMP) Car.cpp -c

Option.o: Option.cpp Option.h
		$(COMP) Option.cpp -c

Test3.o: Test3.cpp Model.h Option.h Car.h
		$(COMP) Test3.cpp -c
