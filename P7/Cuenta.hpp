#ifndef CUENTA_H
#define CUENTA_H

#include <iostream>

class Cuenta
{
private:

	double saldo {0.0};

public:

	Cuenta () = default;
	explicit Cuenta (double _saldo);
	Cuenta (const Cuenta &rhs);
	void operator= (const Cuenta &rhs);

	/**
	 * @brief      Establece el saldo de la cuenta.
	 */
	void SetSaldo (double _saldo);

	/**
	 * @brief      Añade saldo a la cuenta
	 *
	 * @param[in]  _cantidad  El saldo que se le añadirá a la cuenta.
	 */
	virtual void Abonar (double _cantidad);

	/**
	 * @brief      Quita saldo a la cuenta
	 *
	 * @param[in]  _cantidad  El saldo que se le quitará a la cuenta.
	 *
	 * @return     True si se pudo depositar y false en caso contrario
	 */
	virtual bool Cargar (double _cantidad);

	/**
	 * @brief      Obtiene el saldo de la cuenta.
	 *
	 * @return     The saldo.
	 */
	double GetSaldo () const;

	/**
	 * @brief      Destruye cuenta.
	 */
	~Cuenta ();

};


#endif
