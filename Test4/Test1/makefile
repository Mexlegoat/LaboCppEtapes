COMP = g++ -Wall -D DEBUG

Test4: Test4.o Person.o
	$(COMP) Test4.o Person.o -o Test4

Test4.o: Test4.cpp Person.h
	$(COMP) Test4.cpp -c

Personne.o: Personne.cpp Person.h
	$(COMP) Person.cpp -c