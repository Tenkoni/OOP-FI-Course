#ifndef SERIALIZABLE_HPP
#define SERIALIZABLE_HPP

#include <string>

enum class Mode {Lectura, Escritura}; //enum para la lectura y escritura

class Serializable
{
public:

	/**
	 * @brief      Método virtual puro para abrir archivos
	 *
	 * @param[in]  _arch  Nombre del archivo
	 * @param[in]  _m     modo del archivo en enumeracion
	 */
	virtual void Abrir (std::string _arch, Mode _m) = 0;

	/**
	 * @brief      Método virtual puro para escribir archivos
	 */
	virtual void Escribir () = 0;

	/**
	 * @brief     Método virtual puro para leer archivos
	 */
	virtual void Leer () = 0;

	/**
	 * @brief      Método virtual puro para cerrar archivos
	 */
	virtual void Cerrar () = 0;


};

#endif // SERIALIZABLE_HPP
