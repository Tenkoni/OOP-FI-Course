#ifndef CUENTAAHORRO_H
#define CUENTAAHORRO_H

#include <iostream>
#include "Cuenta.hpp"

class CuentaAhorro : public Cuenta
{
public:

    /**
     * @brief      Constructor por defecto
     */
    CuentaAhorro () = default;
	CuentaAhorro (double _cantidad, double _interes);
	~CuentaAhorro ();
	CuentaAhorro (const CuentaAhorro &rhs);
	void operator= (const CuentaAhorro &rhs);

    /**
     * @brief      { Calcula el interes de la cuenta de ahorros }
     *
     * @return     { Regresa el saldo después de añadir el interés }
     */
    double CalcularInteres ();

private:
    double interes {0.0};
};

#endif // CUENTAAHORRO_H
