all: test_serial.out

test_serial.out: Persona.o Nodo.o Lista.o ListSerializable.o Driver.o
	g++ -Wall -std=c++11 -o test_serial.out persona.o nodo.o lista.o listserializable.o driver.o

Driver.o: driver.cpp 
	g++ -Wall -std=c++11 -c driver.cpp

ListSerializable.o: listserializable.cpp serializable.hpp listserializable.hpp 
	g++ -Wall -std=c++11 -c listserializable.cpp

Lista.o: lista.cpp lista.hpp 
	g++ -Wall -std=c++11 -c lista.cpp

Nodo.o: nodo.cpp nodo.hpp
	g++ -Wall -std=c++11 -c nodo.cpp

Persona.o: persona.cpp persona.hpp
	g++ -Wall -std=c++11 -c persona.cpp

.PHONY : clean

clean: 
	-rm *.o *.out *.*~

