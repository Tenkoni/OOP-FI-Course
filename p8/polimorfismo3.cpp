
/** @file poli3.cpp
 *  @brief Muestra el uso de una colección polimórfica para poder almacenar e
 *  iterar sobre objetos de diferentes tipos (obviamente relacionados por la
 *  herencia)
 *
 *  @author eda1.fiunam (eda1.fiunam), eda1.fiunam at yahoo dot com dot mx
 *  @date 11/10/16 -- 23:32:18 
 */

#include <iostream>
#include <vector>

using namespace std;


/*-----------------------------------------------------------------------------
 *                            Clase Estudiante
 *-----------------------------------------------------------------------------*/
class Estudiante
{
public:
	Estudiante () = default;
	Estudiante (string _nombre);

	string GetNombre () const;

	virtual void Print () const;

private:
	string nombre{"NA"};	
};

Estudiante::Estudiante (string _nombre) : nombre {_nombre}
{
	// nada
}

string Estudiante::GetNombre () const
{
	return this->nombre;
}

void Estudiante::Print () const
{
	cout << "Nombre: " << this->nombre << endl;
}

/*-----------------------------------------------------------------------------
 *                           Clase Activo
 *-----------------------------------------------------------------------------*/
class Activo : public Estudiante
{
public:
	Activo () = default;
	Activo (string _nombre, double _promedio, int _semestre);

	virtual void Print () const;

private:
	double promedio {0.0};
	int semestre {1};
};

Activo::Activo (string _nombre, double _promedio, int _semestre)
	: Estudiante {_nombre}, promedio {_promedio}, semestre {_semestre}
{
	// nada
}

void Activo::Print () const
{
	cout << "Nombre: " << GetNombre () << endl;
	cout << "Promedio: " << this->promedio << endl;
	cout << "Semestre: " << this->semestre << endl;
}


/*-----------------------------------------------------------------------------
 *                         Clase Graduado
 *-----------------------------------------------------------------------------*/
class Graduado : public Estudiante
{
public:
	Graduado () = default;
	Graduado (string _nombre, double _promedio, string _cedula);

	virtual void Print () const;

private:
	double promedio {0.0};
	string cedula {"xxx"};
};

Graduado::Graduado (string _nombre, double _promedio, string _cedula)
	: Estudiante {_nombre}, promedio  {_promedio}, cedula {_cedula}
{
	// nada
}

void Graduado::Print () const
{
	cout << "Nombre: " << GetNombre () << endl;
	cout << "Promedio: " << this->promedio << endl;
	cout << "Cédula: " << this->cedula << endl;
}

/*-----------------------------------------------------------------------------
 *                         Driver program
 *-----------------------------------------------------------------------------*/
int main(void)
{
	Estudiante e {"Fco. Javier"};
	Activo a {"Francoise", 10.0, 3};
	Graduado g {"Franz", 8.47, "1234"};

	vector<Estudiante *>v;

	v.push_back (&e);
	v.push_back (&a);
	v.push_back (&g);

	for (auto x : v) {
		x->Print ();
		cout << "------\n"; 
	}

	
	return 0;
}

