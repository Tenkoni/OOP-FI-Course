#ifndef LISTA_HPP
#define LISTA_HPP

#include <stdexcept>
#include "nodo.hpp"


class Lista
{
private:
	Nodo *primero;
	Nodo *ultimo;
	Nodo *current;
	bool isEmpty;

public:
	Lista ();

	/**
	 * @brief      Constructor con argumentos
	 *
	 * @param      _primero  El primer nodo de la lista
	 */
	Lista (Nodo *_primero);
	~Lista ();

	/**
	 * @brief      	regresa current
	 * @return     El nodo al que current está apuntando
	 */
	Nodo* getCurrent();

	/**
	 * @brief      Obtiene el ultimo nodo de la lista
	 *
	 * @return     Apuntador al ultimo nodo de la lista
	 */
	Nodo* getUltimo();

	/**
	 * @brief      Inserta al final de la lista un nodo nuevo
	 *
	 * @param[in]  _val  Los datos que contendrá esa persona
	 */
	void Insertar_Final (Persona _val);

	/**
	 * @brief      Quita un nodo del principio de la lista 
	 */
	void Sacar_Principio ();

	/**
	 * @brief      Limpia la lista sin eliminarla
	 */
	void Clear ();

	/**
	 * @brief      Obtiene el valor del nodo al que actualmente apunta current
	 *
	 * @return     { description_of_the_return_value }
	 */
	Persona Get();

	/**
	 * @brief      Determina si la lista no está vacía
	 *
	 * @return     true si no está vacia, false si está vacia
	 */
	bool IsNotEmpty ();

	/**
	 * @brief      Apunta current al primer nodo de la lista
	 */
	void CursorReset ();

	/**
	 * @brief      Muebe la posición de current al siguiente nodo de la lista
	 *
	 * @return     true si el siguiente valor NO es nullptr, false si lo es
	 */
	bool CursorNext ();

};

#endif // LISTA_HPP
