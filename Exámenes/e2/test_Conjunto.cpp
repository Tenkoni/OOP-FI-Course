#include <iostream>
#include "Conjunto.hpp"

int main ()
{
	Conjunto conjunto (-15, 10);
	conjunto.Insertar (5);
	conjunto.Insertar (-16);
	conjunto.Insertar (9);
	conjunto.Insertar (-4);
	(conjunto.Pertenece(-16)) ? std::cout<< "El dato pertenece al conjunto"<<std::endl
							: std::cout<< "El dato no pertenece al conjunto"<<std::endl;
							 //al estar 16 fuera de la cardinalidad no entra al conjunt0
	(conjunto.Pertenece(9)) ? std::cout<< "El dato pertenece al conjunto"<<std::endl
							: std::cout<< "El dato no pertenece al conjunto"<<std::endl;
							//verificamos si 9 pertenece al conjunto
	conjunto.Sacar (9); //sacamos el 9
	(conjunto.Pertenece(9)) ? std::cout<< "El dato pertenece al conjunto"<<std::endl
							: std::cout<< "El dato no pertenece al conjunto"<<std::endl;
							//ya no pertenece al conjunto, se verifica.

	std::cout<<"La cardinalidad máxima es " << conjunto.GetCardiMax() << std::endl;
	std::cout<<"La cardinalidad mínima es " << conjunto.GetCardiMin() << std::endl;
	//muestra la cardinalidad máxima y la mínima
}
