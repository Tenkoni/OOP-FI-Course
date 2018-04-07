#ifndef LISTSERIALIZABLE_HPP
#define LISTSERIALIZABLE_HPP

#include <fstream>
#include "serializable.hpp"
#include "lista.hpp"


class ListSerializable: public Lista, public Serializable
{
public:
	ListSerializable();

	virtual void Abrir (std::string _arch, Mode _m) override;

	virtual void Escribir () override;

	virtual void Leer () override;

	virtual void Cerrar () override;

private:
	std::ofstream salida; //ofstream para la salida del archivo

	std::ifstream entrada; //ifstream para la entrada del archivo
};

#endif // LISTSERIALIZABLE_HPP
