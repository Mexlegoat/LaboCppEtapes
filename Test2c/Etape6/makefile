COMP = g++ -Wall -D DEBUG

Test2c: Model.o Car.o Option.o Test2c.o
		$(COMP) Model.o Car.o Option.o Test2c.o -o Test2c

Model.o: Model.cpp Model.h
		$(COMP) Model.cpp -c

Car.o: Car.cpp Model.h Car.h
		$(COMP) Car.cpp -c

Option.o: Option.cpp Option.h
		$(COMP) Option.cpp -c

Test2c.o: Test2c.cpp Model.h Option.h Car.h
		$(COMP) Test2c.cpp -c