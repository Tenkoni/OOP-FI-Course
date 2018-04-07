#include "lista.hpp"

Lista::Lista ()
{
	this->primero = nullptr;
	this->ultimo = nullptr;
	this->current = nullptr;
	this->isEmpty = true;
}

Lista::Lista (Nodo *_primero)
{
	if (_primero != nullptr){
		this->primero = this->ultimo = _primero;
		this->isEmpty = false;
	}
	else{
	this->primero = this->ultimo = this->current=nullptr;
	this->isEmpty = true;
	}
}

Lista::~Lista()
{
	Clear();
}

Nodo* Lista::getCurrent ()
{
	return this->current;
}

Nodo* Lista::getUltimo ()
{
	return this->ultimo;
}

void Lista::Insertar_Final (Persona _val)
{
	if (this->primero == nullptr )
	{
		this->primero = this->ultimo = new Nodo (_val, nullptr);
		this->isEmpty = false;
	}
	else 
	{
		Nodo *n = new Nodo (_val, nullptr);
		this->ultimo->Update(n);
		this->ultimo = n;
	}
}

void Lista::Sacar_Principio ()
{
	if (!IsNotEmpty()) 
	{
		throw std::range_error {"\nLa lista está vacía, asegúrate de introducir datos antes de sacarlos."};
	} 
	if (this->primero->GetSiguiente() == nullptr)
	{
		this->primero = this->ultimo = nullptr;
		this->isEmpty = true;
		return ;
	}

	Nodo *dummy;
	dummy = this->primero;
	this->primero = dummy->GetSiguiente();
	return ;
}

void Lista::Clear ()
{
	if (IsNotEmpty())
	{
	Nodo *dummy;
	dummy = this->primero;
	while (dummy != nullptr)
	{
		delete this->primero;
		this->primero = dummy->GetSiguiente();
		dummy = this->primero;
	}
		this->primero = this->ultimo = nullptr;
		this->isEmpty = true;
	}
	else{
		throw std::range_error {"\nLa lista está vacía, asegúrate de introducir datos antes de eliminarlos."};
	}
}

Persona Lista::Get() 
{
	if (!IsNotEmpty()) 
	{
		throw std::range_error {"\nLa lista está vacía, asegúrate de introducir datos antes de sacarlos."};
	}
	if (this->current == nullptr)
	{
		throw std::range_error {"\nError! current apunta a nullptr."};
	}
	return (this->current->GetDatos()); 
}

bool Lista::IsNotEmpty ()
{
	if (this->isEmpty == true)
		return false;
	else return true;
}

void Lista::CursorReset ()
{
	this->current = this->primero;
}

bool Lista::CursorNext ()
{
	if (!IsNotEmpty()) 
	{
		throw std::range_error {"\nLa lista está vacía, no se puede mover current si no hay elementos"};
	}

	if (this->current == nullptr)
	{
		throw std::range_error {"\nError! current apunta a nullptr."};
	}

	if (this->current->GetSiguiente() != nullptr)
	{
		this->current = this->current->GetSiguiente();
		return true;
	}
	else 
	{
		this->current = this->current->GetSiguiente();
		return false;
	}
}
