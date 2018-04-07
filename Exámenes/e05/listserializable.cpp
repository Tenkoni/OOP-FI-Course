#include "listserializable.hpp"

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
