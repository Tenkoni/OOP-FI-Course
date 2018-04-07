#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

class Persona
{
private:
	std::string nombre;
	int edad;

public:
	Persona() = default;
	Persona (std::string _nombre, int _edad);
	int getEdad() const;
	std::string getNombre() const;

};

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

class Nodo 
{
private:
	Persona datos;
	Nodo *siguiente;

public:
	Nodo (Persona _datos, Nodo *_siguiente);
	Persona GetDatos ();
	void SetDatos (Persona _val);
	Nodo* GetSiguiente();
	void Update (Nodo *_siguiente);
};

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

class Lista
{
private:
	Nodo *primero;
	Nodo *ultimo;
	Nodo *current;
	bool isEmpty;

public:
	Lista ();
	Lista (Nodo *_primero);
	~Lista ();

	Nodo* getCurrent();
	Nodo* getUltimo();
	void Insertar_Final (Persona _val);
	void Sacar_Principio ();
	void Clear ();
	Persona Get();
	bool IsNotEmpty ();
	void CursorReset ();
	bool CursorNext ();

};

Lista::Lista ()
{
	this->primero = nullptr;
	this->ultimo = nullptr;
	this->isEmpty = true;
}

Lista::Lista (Nodo *_primero)
{
	this->primero = this->ultimo = _primero;
	this->isEmpty = false;
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
	if (!IsNotEmpty()) 
	{
		throw std::range_error {"\nLa lista está vacía, asegúrate de introducir datos antes de eliminarlos."};
	}
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

enum class Mode {Lectura, Escritura};



class Serializable
{
public:
	virtual void Abrir (std::string _arch, Mode _m) = 0;
	virtual void Escribir () = 0;
	virtual void Leer () = 0;
	virtual void Cerrar () = 0;

};

class ListSerializable: public Lista, public Serializable
{
public:
	ListSerializable();
	virtual void Abrir (std::string _arch, Mode _m) override;
	virtual void Escribir () override;
	virtual void Leer () override;
	virtual void Cerrar ()override;

private:
	std::ofstream salida;
	std::ifstream entrada;
};

ListSerializable::ListSerializable () : Lista{nullptr}
{
	//nada
}


void ListSerializable::Abrir (std::string _arch, Mode _m)
{
	if (_m == Mode::Lectura)
	{
		this->entrada.open(_arch);
		if (!entrada.is_open())
			throw std::logic_error {"\nError abriendo el archivo"};
		return;
	}
	if (_m == Mode::Escritura)
	{
		this->salida.open(_arch);
		if (!salida.is_open())
			throw std::logic_error {"\nError abriendo el archivo"};
		return;
	}

}

void ListSerializable::Escribir ()
{
	if (!this->salida.is_open())
		throw std::logic_error{"\nSe intentó escribir un archivo que no se encuentra abierto"};
	if (!IsNotEmpty())
		throw std::logic_error{"\nSe intentó serializar una lista vacía"};
	else
	{
		CursorReset();
		while (getCurrent() != nullptr)
		{
			this->salida << Get().getNombre() << "\t" << Get().getEdad() << "\n";
			CursorNext();
		}

	}
}

void ListSerializable::Leer ()
{
	if (!this->entrada.is_open())
		throw std::logic_error{"\nSe intentó leer de un archivo que no se encuentra abierto"};
	if (entrada.peek() == std::ifstream::traits_type::eof())
		throw std::logic_error{"\nSe intentó leer de un archivo vacío"};
	else
	{
		std::string nombre;
		int edad;
		while (entrada >> nombre >> edad)
		{
			Persona temp (nombre, edad);
			Insertar_Final(temp);
			std::cout<<"Nombre: " << nombre <<" Edad: " << edad <<"\n\n"; 
		}
	}
}

void ListSerializable::Cerrar ()
{
	if (this->salida.is_open())
	{
		this->salida.close();
		return;
	}
	if (this->entrada.is_open())
	{
		this->entrada.close();	
		return;
	}
	else throw std::logic_error{"\nSe intentó cerrar un archivo que no se encuentra abierto "};
}


int main ()
{
	int op;
	ListSerializable lista;
	do{
	std::cout<<"*********************************\n"
			 <<"*    Lista Serializable v1.0    *\n"
			 <<"*        Menú Principal         *\n"
			 <<"*                               *\n"
			 <<"*     Seleccione una opción:    *\n"
			 <<"*                               *\n"
			 <<"*      1) Insertar Persona      *\n"
			 <<"*      2) Borrar la lista       *\n"
			 <<"*        3) Serializar          *\n"
			 <<"*       4) Deserializar         *\n"
			 <<"*           5) Salir            *\n"
			 <<"*********************************\n"<<std::endl;
	std::cout<< "Opción a elegir: " ;
	std::cin>>op;

	switch ( op )
	{
		case 1 :
			{
			std::string tempo;
			int tempi;
			std::cout<<"\nIngresa el nombre: ";
			std::cin>>tempo;
			std::cout<<"\nIngresa la edad: ";
			std::cin>>tempi;
			Persona temp(tempo, tempi);
			lista.Insertar_Final(temp);
			break;
			}

		case 2 :
			{
			try{
			lista.Clear();
			}
			catch (std::range_error &e){
				std::cout <<e.what()<<std::endl;
			}
			break;
			}	

		case 3 :
			{
			try{
			lista.Abrir("serial.txt", Mode::Escritura);
			lista.Escribir();
			}
			catch (std::logic_error &e){
				std::cout <<e.what()<<std::endl;
			}
			catch (std::range_error &e){
				std::cout <<e.what()<<std::endl;
			}
			break;	
			}

		case 4 :
			{
			try{
			lista.Abrir("serial.txt", Mode::Lectura);
			lista.Leer();
			}
			catch (std::logic_error &e){
				std::cout <<e.what()<<std::endl;
			}
			break;	
			}

		case 5 :
			{
			std::cout<<"\nAdiós"<<std::endl;
			break;	
			}
			
		default :
			{	
			std::cout<< "Entrada inválida, intenta otra vez" <<std::endl;
			break;	
			}

	}

	}while (op != 5);
}
