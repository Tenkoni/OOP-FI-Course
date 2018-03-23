#include "Pila.hpp"

bool Pila::isEmpty()
{
	return (core.empty());
}

void Pila::Push (char c)
{
	core.push_back(c);
}

char Pila::Pop ()
{
	if (!core.empty())
	{
	char c = core.back();
	core.pop_back();
	return c;
	}
	else return 'e';
	
}

char Pila::Peek ()
{
	if (!core.empty())
		return (core.back());
	else return 'e';
}

void Pila::Clear ()
{
	core.clear ();
}

