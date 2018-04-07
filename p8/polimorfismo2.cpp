
/** @file polimorfismo2.cpp
 *  @brief Muestra el polimorfismo con un switch
 *
 *  @author eda1.fiunam (eda1.fiunam), eda1.fiunam at yahoo dot com dot mx
 *  @date 11/10/16 -- 23:32:18 
 */

#include <iostream>

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

	virtual void Print () const override;

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

	virtual void Print () const override;

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

void Imprimir (Estudiante * oPoli)
{
	oPoli->Print ();
}



int main(void)
{
	Estudiante e {"Fco. Javier"};
	Activo a {"Francoise", 10.0, 3};
	Graduado g {"Franz", 8.47, "1234"};


	Estudiante * p = nullptr;
	int opcion = 0;

	while (1)
	{
		cout << endl;
		cout << "0 -- Estudiante\n";
		cout << "1 -- Activo\n";
		cout << "2 -- Graduado\n";
		cout << "9 -- Salir\n";
		cin >> opcion;

		switch (opcion) {
			case 0:
				p = &e; 
				break;

			case 1: 
				p = &a;
				break;

			case 2:
				p = &g;
				break;

			case 9:
				cout << "Terminando.\n";
				return 0;

			default:
				cout << "Opción no válida!\n";
				break;
		} // switch

		Imprimir (p);
	} // while

	
	return 0;
}

