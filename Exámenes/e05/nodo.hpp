#ifndef NODO_HPP
#define NODO_HPP

#include "persona.hpp"

class Nodo 
{
private:
	Persona datos;
	Nodo *siguiente;

public:

	/**
	 * @brief      Constructor con argumentos del nodo
	 *
	 * @param[in]  _datos      La persona del nodo
	 * @param      _siguiente  Apuntador al siguiente nodo
	 */
	Nodo (Persona _datos, Nodo *_siguiente);

	/**
	 * @brief      Obtiene los datos del nodo
	 *
	 * @return     clase persona que contiene el nodo
	 */
	Persona GetDatos ();

	/**
	 * @brief      Establece los datos del nodo
	 *
	 * @param[in]  _val  instancia de persona
	 */
	void SetDatos (Persona _val);

	/**
	 * @brief      Regresa el dato miembro siguiente
	 *
	 * @return     APuntador al siguiente nodo
	 */
	Nodo* GetSiguiente();

	/**
	 * @brief      Actualiza el nodo 
	 *
	 * @param      _siguiente  el nodo al que ahora se apuntará
	 */
	void Update (Nodo *_siguiente);
};


#endif // NODO_HPP
