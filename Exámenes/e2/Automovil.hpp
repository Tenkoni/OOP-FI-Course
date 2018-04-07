#ifndef AUTOMOVIL_HPP
#define AUTOMOVIL_HPP

#include <iostream>
#include <string>

namespace lems 
{
	enum class Tipo { Sedan, Compacto, SUV, Hatchback };
	enum class Intermitentes { apagadas = 0, izquierda = -1, derecha = 1};
	enum class Direccion { izquierda = -1, derecha = 1, centro = 0};	
}

namespace lems {
	class Automovil
	{
	public:
		Automovil();
		Automovil (lems::Tipo type, double vmax);
		Automovil (const Automovil &rhs);
		~Automovil();
		void operator= (const Automovil &rhs);
		lems::Tipo GetTipo () const;
		bool GetEnMovimiento () const;
		lems::Intermitentes GetIntermitentes () const;
		double GetVelocidad () const;
		double GetVelMaxima () const;
		lems::Direccion GetDireccion () const;
		std::string TranslDir () const;
		std::string TranslInte () const;
		std::string TranslTipo () const;
		void Arrancar ();
		void Parar ();
		void ModoIntermitentes (lems::Intermitentes state);
		void Girar (lems::Direccion dir);
		void Acelerar ();
		void Desacelerar ();
		void InternalState ();


	private:
		lems::Tipo tipo;
		bool enMovimiento;
		double velocidad {0.0};
		double velMaxima {0.0};
		lems::Intermitentes intermitentes {lems::Intermitentes::apagadas};
		lems::Direccion direccion {lems::Direccion::centro};
		
	};

}//namespace lems

#endif // AUTOMOVIL_HPP
