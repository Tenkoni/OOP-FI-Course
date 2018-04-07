#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>

class Nodo 
{
private:
	int datos;
	Nodo *siguiente;

public:
	Nodo (int _datos, Nodo *_siguiente);
	int GetDatos ();
	void SetDatos (int _val);
	Nodo* GetSiguiente();
	void Update (Nodo *_siguiente);
};

class Lista
{
private:
	Nodo *primero;
	Nodo *ultimo;
	bool isEmpty;

public:
	Lista ();
	~Lista ();

	void Insertar_Principio (int _val);
	void Insertar_Final (int _val);
	int Sacar_Principio ();
	int Sacar_Final ();
	bool IsEmpty ();
	Nodo* Search (int _val);
	void Delete (Nodo* node);
	void DeleteAll ();

};


#endif // LISTA_HPP
