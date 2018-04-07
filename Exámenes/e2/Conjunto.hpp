#ifndef CONJUNTO_HPP
#define CONJUNTO_HPP

#include <iostream>
#include "Lista.hpp"

class Conjunto
{
private:
	int min;
	int max;
	Lista list;

public:
	Conjunto (int _min, int _max);
	~Conjunto ();
	void Insertar (int _val);
	void Sacar (int _val);
	bool Pertenece (int _val);
	int GetCardiMax ();
	int GetCardiMin ();

};

#endif // CONJUNTO_HPP
