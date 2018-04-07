#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <iostream>
#include <string>

class Persona
{
private:
	std::string nombre;
	int edad;

public:

	/**
	 * @brief      Constructor por defecto de persona
	 */
	Persona() = default;

	/**
	 * @brief      Constructor con argumentos de persona
	 *
	 * @param[in]  _nombre  El nombre de la persona
	 * @param[in]  _edad    La edad de la persona
	 */
	Persona (std::string _nombre, int _edad);

	/**
	 * @brief      Obtiene la edad.
	 *
	 * @return     La edad de la persona.
	 */
	int getEdad() const;

	/**
	 * @brief      Obtiene el nombre.
	 *
	 * @return     EL nombre de la persona
	 */
	std::string getNombre() const;

};


#endif // PERSONA_HPP
