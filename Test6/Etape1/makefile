# SRC: .cpp | INC: .h | OBJ: .o | BIN: .exe
SRC = ./src
INC = ./Include
OBJ = ./Obj
BIN = ./bin
COMP = g++ -Wall -D DEBUG -I $(INC)


all : $(BIN) $(OBJ) $(BIN)/Test6

$(BIN):
	mkdir -p $(BIN)
	@echo "Creation fichier bin"

$(OBJ):
	mkdir -p $(OBJ)
	@echo "Creation fichier obj"


$(BIN)/Test6: $(OBJ)/Test6.o $(OBJ)/OptionException.o $(OBJ)/Option.o $(OBJ)/Exception.o $(OBJ)/Car.o $(OBJ)/Model.o $(OBJ)/PasswordException.o $(OBJ)/Client.o $(OBJ)/Person.o $(OBJ)/Actor.o
	$(COMP) $(OBJ)/Test6.o $(OBJ)/OptionException.o $(OBJ)/Option.o $(OBJ)/Exception.o $(OBJ)/Car.o $(OBJ)/Model.o $(OBJ)/PasswordException.o $(OBJ)/Client.o $(OBJ)/Person.o $(OBJ)/Actor.o -o $(BIN)/Test6

$(OBJ)/Test6.o: $(SRC)/Test6.cpp $(INC)/Option.h $(INC)/Car.h $(INC)/Model.h $(INC)/Client.h
	$(COMP) -c $(SRC)/Test6.cpp -o $(OBJ)/Test6.o

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

$(OBJ)/PasswordException.o: $(SRC)/PasswordException.cpp $(INC)/Exception.h $(INC)/PasswordException.h
	$(COMP) -c $(SRC)/PasswordException.cpp -o $(OBJ)/PasswordException.o

clean:
	rm -f $(OBJ)/*.o
clobber: clean
	rm -f $(BIN)/Test6
