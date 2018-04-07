#include "Lista.hpp"

/**
 * @brief      Construye la clase Nodo
 *
 * @param[in]  _datos      El valor que tendrá el nodo
 * @param      _siguiente  Apuntador al siguiente nodo
 */
Nodo::Nodo (int _datos, Nodo *_siguiente) : datos{_datos}, siguiente {_siguiente}
{
	//void
};

/**
 * @brief      Obtiene los datos.
 *
 * @return     El valor del dato miembro "datos"
 */
int Nodo::GetDatos ()
{
	return (this->datos);
}

/**
 * @brief      Establece el valor del dato miembro Datos
 *
 * @param[in]  _val  El valor que queremos darle a datos
 */
void Nodo::SetDatos (int _val)
{
	this->datos = _val;
}

/**
 * @brief      Obtiene el apuntador siguiente.
 *
 * @return     El apuntador siguiente
 */
Nodo* Nodo::GetSiguiente ()
{
	return (this->siguiente);
}

/**
 * @brief      { Actualiza el valor de el apuntador siguiente }
 *
 * @param      _siguiente  El nuevo nodo al cual apuntar
 */
void Nodo::Update (Nodo *_siguiente)
{
	this->siguiente = _siguiente;
}

/**
 * @brief      Construye el objeto Lista.
 */
Lista::Lista ()
{
	this->primero = nullptr;
	this->ultimo = nullptr;
	this->isEmpty = true;
}

/**
 * @brief      Destruye el objeto y la función DeleteAll se encarga 
 * 			de borrar todos los nodos previamente a la eliminacion de la Lista.
 */
Lista::~Lista()
{
	DeleteAll ();
}

/**
 * @brief      { Inserta un nodo al principio de la lista }
 *
 * @param[in]  _val  El valor del nodo que queremos insertar
 */
void Lista::Insertar_Principio (int _val)
{
	if (this->primero == nullptr )
	{
		this->primero = this->ultimo = new Nodo (_val, nullptr);
		this->isEmpty = false;
	}
	else {
		Nodo *n = new Nodo (_val, this->primero);
		this->primero = n;
	}
}

/**
 * @brief      Inserta un nodo al final de la lista
 *
 * @param[in]  _val  El valor del nodo que deseamos insertar
 */
void Lista::Insertar_Final (int _val)
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

/**
 * @brief      Elimina un nodo del principio de la lista y regresa su valor.
 *
 * @return     { El valor del dato miembro "datos" del nodo}
 */
int Lista::Sacar_Principio ()
{
	if (IsEmpty()) {/*Nada*/}
	if (this->primero->GetSiguiente() == nullptr)
	{
		Nodo *dummy = this->primero;
		this->primero = this->ultimo = nullptr;
		this->isEmpty = true;
		return (dummy->GetDatos());
	}

	Nodo *dummy;
	dummy = this->primero;
	this->primero = dummy->GetSiguiente();
	return (dummy->GetDatos());
}

/**
 * @brief      Elimina un nodo al final de la lista y regresa su valor.
 *
 * @return     { El valor del dato miembro "datos" del nodo }
 */
int Lista::Sacar_Final ()
{
	if (IsEmpty())  {/*Nada*/}
	if (this->primero->GetSiguiente() == nullptr)
	{
		Nodo *dummy = this->primero;
		this->primero = this->ultimo = nullptr;
		this->isEmpty = true;
		return (dummy->GetDatos());
	}

	Nodo *dummy, *dummy2;
	dummy = this->primero;
	while (dummy->GetSiguiente() != this->ultimo)
	{
		dummy = dummy->GetSiguiente();
	}
	dummy->Update(nullptr);
	dummy2 = this->ultimo;
	this->ultimo = dummy;
	return (dummy2->GetDatos());

}

/**
 * @brief      Determina si la lista está vacía
 *
 * @return     True si está vacía, false en caso contrario.
 */
bool Lista::IsEmpty ()
{
	return(this->isEmpty);
}

/**
 * @brief      Busca un nodo con cierto valor.
 *
 * @param[in]  _val  El valor del dato miembro del nodo a buscar.
 *
 * @return     { Regresa un apuntador al nodo que contiene dicho valor }
 */
Nodo* Lista::Search (int _val)
{
	Nodo *dummy;
	dummy = this->primero;
	while (dummy != nullptr)
	{
		if (dummy->GetDatos() == _val)
		{
			return dummy;
		}
		
		dummy= dummy->GetSiguiente();
	}

	return nullptr;
}


/**
 * @brief      { Borra el nodo de la lista }
 *
 * @param      node  El nodo que deseamos borrar
 */
void Lista::Delete (Nodo *node)
{
	if (IsEmpty()) {/*no entra */}
	else if (this->primero->GetSiguiente() == nullptr)
	{
		delete this->primero;
		this->primero = this->ultimo = nullptr;
		this->isEmpty = true;
	}
	else
	{
		Nodo *dummy = this->primero;
		while (dummy->GetSiguiente() != node)
		{
			dummy = dummy->GetSiguiente();
		}
		dummy->Update (node->GetSiguiente());
		delete node;
	}

}

/**
 * @brief      { Elimina todos los nodos de la lista. }
 */
void Lista::DeleteAll ()
{
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
