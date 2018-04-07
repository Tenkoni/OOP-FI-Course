#include "Automovil.hpp"

namespace lems
{

	/**
	 * @brief      Constructor por defecto de Automovil
	 */
	Automovil::Automovil () 
	{
		this->velMaxima = 110;
		this->tipo = lems::Tipo::Sedan;
	}

	/**
	 * @brief      Construye el objeto con argumentos.
	 *
	 * @param[in]  type  El tipo de vehículo
	 * @param[in]  vmax  La velocidad máxima
	 */
	Automovil::Automovil (lems::Tipo type, double vmax) : tipo {type}, velMaxima {vmax}
	{
		//void
	}

	/**
	 * @brief      Construye el objeto por copia
	 *
	 * @param[in]  rhs   Instancia de Automovil que se va a copiar
	 */
	Automovil::Automovil (const Automovil &rhs)
	{
		this->tipo = rhs.tipo;
		this->enMovimiento = rhs.enMovimiento;
		this->velocidad = rhs.velocidad;
		this->velMaxima = rhs.velMaxima;
		this->intermitentes = rhs.intermitentes;
		this->direccion = rhs.direccion;
	}

	/**
	 * @brief      Destruye el objeto .
	 */
	Automovil::~Automovil ()
	{
		//void
	}

	/**
	 * @brief      Sobrecarga el operador '=' para la clase Automovil
	 *
	 * @param[in]  rhs   Instancia de Automovil que se va a copiar
	 */
	void Automovil::operator= (const Automovil &rhs)
	{
		this->tipo = rhs.tipo;
		this->enMovimiento = rhs.enMovimiento;
		this->velocidad = rhs.velocidad;
		this->velMaxima = rhs.velMaxima;
		this->intermitentes = rhs.intermitentes;
		this->direccion = rhs.direccion;
	}

	/**
	 * @brief      Obtiene el tipo de automovil
	 *
	 * @return     El tipo de coche de la instancia.
	 */
	lems::Tipo Automovil::GetTipo () const 
	{
		return (this->tipo);
	}

	/**
	 * @brief      Determina si el coche se encuentra en movimiento	 
	 *
	 * @return     Regresa el valor de enMovimiento
	 */
	bool Automovil::GetEnMovimiento () const
	{
		return (this->enMovimiento);
	}

	/**
	 * @brief      Obntiene el estado de las intermitentes.
	 *
	 * @return     Regresa el estado de las intermitentes.
	 */
	lems::Intermitentes Automovil::GetIntermitentes () const
	{
		return (this->intermitentes);
	}

	/**
	 * @brief      Obtiene la velocidad a la que se mueve el vehículo.
	 *
	 * @return     La velocidad de movimiento
	 */
	double Automovil::GetVelocidad () const 
	{
		return (this->velocidad);
	}

	/**
	 * @brief      Obtiene la velocidad máxima del objeto Automovil
	 *
	 * @return     La velocidad máxima
	 */
	double Automovil::GetVelMaxima () const 
	{
		return (this->velMaxima);
	}

	/**
	 * @brief      Obtiene la dirección en la que el coche está moviéndose
	 *
	 * @return     La dirección
	 */
	lems::Direccion Automovil::GetDireccion () const
	{
		return (this->direccion);
	}

	/**
	 * @brief      Convierte a string los elementos de la enumeracion Direccion
	 *
	 * @return     El elemento de la enumeración en forma de string
	 */
	std::string Automovil::TranslDir () const
	{
		
		switch (static_cast<int> (GetDireccion()))
		{
			case -1: return "izquierda";
			case 1 : return "derecha";
		}
		return "NULL";
	}

	/**
	 * @brief      Convierte a string los elementos de la enumeracion Intermitentes
	 *
	 * @return     El elemento de la enumeración en forma de string
	 */
	std::string Automovil::TranslInte ()  const
	{
		
		switch (static_cast<int> (GetIntermitentes()))
		{
			case -1: return "izquierda";
			case 1 : return "derecha";
		}
		return "NULL";
	}

	/**
	 * @brief      Convierte a string los elementos de la enumeracion Tipo
	 *
	 * @return     El elemento de la enumeración en forma de string
	 */
	std::string Automovil::TranslTipo () const
	{
		switch (static_cast<int> (GetTipo()))
		{
			case 0: return "Sedan"; 
			case 1 : return "Compacto";
			case 2 : return "SUV";
			case 3 : return "Hatchback";
		}
		return "NULL";
	}

	/**
	 * @brief      { Arranca el coche, asignando a enMovimiento true }
	 */
	void Automovil::Arrancar ()
	{
		this->enMovimiento = true;
	}

	/**
	 * @brief      { Detiene el coche, asignando a enMovimiento false }
	 */
	void Automovil::Parar ()
	{
		if (GetVelocidad() == 0.0)
		this->enMovimiento = false;
	}

	/**
	 * @brief      Establece el modo en el que se encuentran las intermitentes
	 *
	 * @param[in]  state  El estado de las intermitentes que se desea.
	 */
	void Automovil::ModoIntermitentes (lems::Intermitentes state)
	{
		this->intermitentes = state;
	}

	/**
	 * @brief      Establece la dirección en la que se mueve el coche
	 *
	 * @param[in]  dir   La dirección que se desea
	 */
	void Automovil::Girar (lems::Direccion dir)
	{
		this->direccion = dir;
	}

	/**
	 * @brief      Acelera el coche 10 unidades hsta que se llegue a la velocidad máxima
	 * 				si esta se supera se establece la velocidad igual a la velocidad máxima
	 * 				es decir, si el coche tiene por velocidad máxima 120, ya se encuentra en 
	 * 				118 e intenta acelerar el coche se quedará en 120.
	 */
	void Automovil::Acelerar ()
	{
		if (this->velocidad >= 0.0 && this->velocidad < this->velMaxima && GetEnMovimiento() )
		{
			this->velocidad += 10;
			if (this->velocidad > this->velMaxima) this->velocidad = this->velMaxima;
		}
	}

	/**
	 * @brief      Desacelera el coche 10 unidades hasta que llegue a 0, no hay velocidades
	 * 			   negativas, cuando se llegue a 0 unidades de velocidad se podrá parar el coche.
	 */
	void Automovil::Desacelerar ()
	{
		if (this->velocidad > 0.0 )
		{
			this->velocidad -= 10;
			if (this->velocidad < 0.0) this->velocidad = 0.0;
		}
	
	}

	/**
	 * @brief       Se encarga de imprimir el estado del coche, sólo es una función para
	 *  			acortar la longitud del main, en vez de escribir por cada case el estado
	 *  			simplemente se manda a llamar después de cada case.
	 */
	void Automovil::InternalState()
	{
		(GetEnMovimiento()) ? 
			std::cout<< "\nEl automovil se encuentra encendido a una velocidad de "<< GetVelocidad() 			<< " km/h"<<std::endl 
			: std::cout << "El automovil no se encuentra en movimiento."<<std::endl;

		(static_cast<int> (GetDireccion()) == 0) ?
			std::cout<<"Actualmente el vehículo se encuentra sin giro."<<std::endl
			: std::cout<<"El vehículo se encuentra girando hacia la "<< TranslDir()<<std::endl;

		(static_cast<int> (GetIntermitentes()) == 0) ?
			std::cout<< "Las intermitentes se encuentran apagadas" <<std::endl
			: std::cout<< "La intermitente " << TranslInte() << " se encuentra activa."<<std::endl;
	}

}//namespace lems
