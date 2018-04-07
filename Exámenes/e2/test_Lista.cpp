#include <iostream>
#include "Lista.hpp"

int main ()
{
	Lista lista;
	lista.Insertar_Principio (5);
	lista.Insertar_Principio (4);
	lista.Insertar_Principio (3);
	lista.Insertar_Final (10);
	lista.Insertar_Final (11);
	lista.Insertar_Final (12);

	(lista.IsEmpty()) ? std::cout<<"La lista está vacía"<<std::endl 
					: std::cout<<"La lista contiene elementos"<<std::endl; //verificamos si la lista tiene datos.

	(lista.Search (10)==nullptr) ? std::cout<<"No se encontró el valor en la lista"<<std::endl  
								: std::cout<<"El valor se encuentra en la lista"<<std::endl ; //verifiacamos que exista el nodo con dato 10
	
	lista.Delete (lista.Search(10));// se borra el nodo con el dato 10
	
	(lista.Search (10)==nullptr) ? std::cout<<"No se encontró el valor en la lista"<<std::endl  
								: std::cout<<"El valor se encuentra en la lista"<<std::endl ; //verificamos que ya no exista
	
	std::cout<<"El primer elemento de la lista es: "<< lista.Sacar_Principio() << std::endl; //regresamos el primer elemento de la lista
	std::cout<<"El ultimo elemento de la lista es: "<< lista.Sacar_Final() << std::endl; //regresamos el segundo elemento de la lista

	lista.DeleteAll(); //borra todos los nodos
	(lista.IsEmpty()) ? std::cout<<"La lista está vacía"<<std::endl 
					: std::cout<<"La lista contiene elementos"<<std::endl;

}
