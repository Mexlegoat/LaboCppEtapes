# SRC: .cpp | INC: .h | OBJ: .o | BIN: .exe
SRC = ./src
INC = ./Include
OBJ = ./Obj
BIN = ./bin
COMP = g++ -Wall -D DEBUG -I $(INC) -I $(SRC) -I $(OBJ)


all : $(BIN) $(OBJ) $(BIN)/Test8b
Test8a : $(BIN) $(OBJ) $(BIN)/Test8a

$(BIN):
	mkdir -p $(BIN)
	@echo "Creation fichier bin"

$(OBJ):
	mkdir -p $(OBJ)
	@echo "Creation fichier obj"

$(BIN)/Test8a: $(OBJ)/Test8a.o $(OBJ)/OptionException.o $(OBJ)/Option.o $(OBJ)/Exception.o $(OBJ)/Car.o $(OBJ)/Model.o $(OBJ)/PasswordException.o $(OBJ)/Client.o $(OBJ)/Person.o $(OBJ)/Actor.o $(OBJ)/XmlFileSerializerException.o $(OBJ)/Garage.o $(OBJ)/Employee.o
	$(COMP) $(OBJ)/Test8a.o $(OBJ)/OptionException.o $(OBJ)/Option.o $(OBJ)/Exception.o $(OBJ)/Car.o $(OBJ)/Model.o $(OBJ)/PasswordException.o $(OBJ)/Client.o $(OBJ)/Person.o $(OBJ)/Actor.o $(OBJ)/XmlFileSerializerException.o $(OBJ)/Garage.o $(OBJ)/Employee.o -o $(BIN)/Test8a

$(BIN)/Test8b: $(OBJ)/Test8b.o $(OBJ)/OptionException.o $(OBJ)/Option.o $(OBJ)/Exception.o $(OBJ)/Car.o $(OBJ)/Model.o $(OBJ)/PasswordException.o $(OBJ)/Client.o $(OBJ)/Person.o $(OBJ)/Actor.o $(OBJ)/XmlFileSerializerException.o $(OBJ)/Garage.o $(OBJ)/Employee.o
	$(COMP) $(OBJ)/Test8b.o $(OBJ)/OptionException.o $(OBJ)/Option.o $(OBJ)/Exception.o $(OBJ)/Car.o $(OBJ)/Model.o $(OBJ)/PasswordException.o $(OBJ)/Client.o $(OBJ)/Person.o $(OBJ)/Actor.o $(OBJ)/XmlFileSerializerException.o $(OBJ)/Garage.o $(OBJ)/Employee.o -o $(BIN)/Test8b

$(OBJ)/Test8b.o: $(SRC)/Test8b.cpp $(INC)/Option.h $(INC)/Car.h $(INC)/Model.h $(INC)/Client.h $(INC)/XmlFileSerializer.hpp $(INC)/Garage.h
	$(COMP) -c $(SRC)/Test8b.cpp -o $(OBJ)/Test8b.o

$(OBJ)/Test8a.o: $(SRC)/Test8a.cpp $(INC)/Option.h $(INC)/Car.h $(INC)/Model.h $(INC)/Client.h $(INC)/XmlFileSerializer.hpp $(INC)/Garage.h
	$(COMP) -c $(SRC)/Test8a.cpp -o $(OBJ)/Test8a.o

$(OBJ)/Option.o: $(SRC)/Option.cpp $(INC)/Option.h $(INC)/OptionException.h
	$(COMP) -c $(SRC)/Option.cpp -o $(OBJ)/Option.o

$(OBJ)/OptionException.o: $(SRC)/OptionException.cpp $(INC)/OptionException.h $(INC)/Exception.h
	$(COMP) -c $(SRC)/OptionException.cpp -o $(OBJ)/OptionException.o

$(OBJ)/Exception.o: $(SRC)/Exception.cpp $(INC)/Exception.h
	$(COMP) -c $(SRC)/Exception.cpp -o $(OBJ)/Exception.o

$(OBJ)/Car.o: $(SRC)/Car.cpp $(INC)/Car.h $(INC)/Model.h $(INC)/OptionException.h $(INC)/Option.h
	$(COMP) -c $(SRC)/Car.cpp -o $(OBJ)/Car.o

$(OBJ)/Model.o: $(SRC)/Model.cpp $(INC)/Model.h
	$(COMP) -c $(SRC)/Model.cpp -o $(OBJ)/Model.o

$(OBJ)/Actor.o: $(SRC)/Actor.cpp $(INC)/Actor.h $(INC)/Person.h
	$(COMP) -c $(SRC)/Actor.cpp -o $(OBJ)/Actor.o

$(OBJ)/Person.o: $(SRC)/Person.cpp $(INC)/Person.h
	$(COMP) -c $(SRC)/Person.cpp -o $(OBJ)/Person.o

$(OBJ)/Client.o: $(SRC)/Client.cpp $(INC)/Client.h $(INC)/Actor.h
	$(COMP) -c $(SRC)/Client.cpp -o $(OBJ)/Client.o

$(OBJ)/Employee.o: $(SRC)/Employee.cpp $(INC)/Employee.h $(INC)/Actor.h
	$(COMP) -c $(SRC)/Employee.cpp -o $(OBJ)/Employee.o

$(OBJ)/Garage.o: $(SRC)/Garage.cpp $(INC)/Garage.h
	$(COMP) -c $(SRC)/Garage.cpp -o $(OBJ)/Garage.o

$(OBJ)/PasswordException.o: $(SRC)/PasswordException.cpp $(INC)/Exception.h $(INC)/PasswordException.h
	$(COMP) -c $(SRC)/PasswordException.cpp -o $(OBJ)/PasswordException.o

$(OBJ)/XmlFileSerializerException.o: $(SRC)/XmlFileSerializerException.cpp $(INC)/Exception.h $(INC)/XmlFileSerializerException.h
	$(COMP) -c $(SRC)/XmlFileSerializerException.cpp -o $(OBJ)/XmlFileSerializerException.o

clean:
	rm -f $(OBJ)/*.o
clobber: clean
	rm -f $(BIN)/Test8b
