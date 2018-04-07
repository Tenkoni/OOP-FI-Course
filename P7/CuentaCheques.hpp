#ifndef CUENTACHEQUES_H
#define CUENTACHEQUES_H

#include <iostream>
#include "Cuenta.hpp"

class CuentaCheques : public Cuenta
{
private:
	double cuota {0.0};
public:

	/**
	 * @brief      { Constructor por defecto de la clase CuentaCheques }
	 */
	CuentaCheques () = default;
	CuentaCheques (double _cantidad, double _cuota);
	~CuentaCheques ();
	CuentaCheques (const CuentaCheques &rhs);
	void operator= (const CuentaCheques &rhs);

	/**
	 * @brief      Obtiene el valor de cuota.
	 *
	 * @return     El valor de la cuota en double.
	 */
	double GetCuota ();

	/**
	 * @brief      { Verifica y retira una cantidad de la cuenta }
	 *
	 * @param[in]  _cantidad  La cantidad que se desea retirar
	 *
	 * @return     { Si se puede efectuar el retiro regresa true, en caso contrario false.}
	 */
	bool Cargar (double _cantidad) override;

	/**
	 * @brief      { Efectua el cobro de la cuota }
	 *
	 * @param[in]  _cantidad  El valor de la cuota
	 */
	void Abonar (double _cantidad)override;

};

#endif // CUENTACHEQUES_H
