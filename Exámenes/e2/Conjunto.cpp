#include "Conjunto.hpp"

/**
 * @brief      Construye el conjunto.
 *
 * @param[in]  _min  La cardinalidad mínima
 * @param[in]  _max  La cardinalidad máxima
 */
Conjunto::Conjunto (int _min, int _max) : min {_min}, max {_max}
{
	Lista list;
}

/**
 * @brief      Destruye el objeto
 */
Conjunto::~Conjunto ()
{
	//destructor
}


/**
 * @brief      { Inserta un elementom al conjunto }
 *
 * @param[in]  _val  El valor que queremos insertar
 */
void Conjunto::Insertar (int _val)
{
	if (GetCardiMin()<= _val && GetCardiMax()>= _val)
		this->list.Insertar_Principio (_val);
}

/**
 * @brief      { Saca un elemento del conjunto }
 *
 * @param[in]  _val  El elemento que queremos sacar.
 */
void Conjunto::Sacar (int _val)
{
	if (list.IsEmpty()) return;
	list.Delete(list.Search(_val));
}

/**
 * @brief      { function_description }
 *
 * @param[in]  _val  The value
 *
 * @return     { description_of_the_return_value }
 */
bool Conjunto::Pertenece (int _val)
{
	if(list.Search(_val) != nullptr)
		return true;
	return false;
}

/**
 * @brief      Obtiene la cardinalidad máxima.
 *
 * @return     La cardinalidad maxima.
 */
int Conjunto::GetCardiMax ()
{
	return (this->max);
}

/**
 * @brief      Obtiene la cardinalidad mínima 
 *
 * @return     La cardinalidad mínima.
 */
int Conjunto::GetCardiMin ()
{
	return (this->min);
}

