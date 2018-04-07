#include "persona.hpp"

Persona::Persona (std::string _nombre, int _edad) : nombre {_nombre}, edad {_edad}
{
	//void
}

int Persona::getEdad () const
{
	return this->edad;
}

std::string Persona::getNombre() const
{
	return this->nombre;
}
