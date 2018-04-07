#include "nodo.hpp"

Nodo::Nodo (Persona _datos, Nodo *_siguiente) : datos{_datos}, siguiente {_siguiente}
{
	//void
};

Persona Nodo::GetDatos ()
{
	return (this->datos);
}

void Nodo::SetDatos (Persona _val)
{
	this->datos = _val;
}

Nodo* Nodo::GetSiguiente ()
{
	return (this->siguiente);
}

void Nodo::Update (Nodo *_siguiente)
{
	this->siguiente = _siguiente;
}