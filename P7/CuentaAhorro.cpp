#include "CuentaAhorro.hpp"
#include "Cuenta.hpp"

/**
 * @brief      Construye CuentaAhorro con dos argumentos
 *
 * @param[in]  _cantidad  El saldo con el que se iniciará la cuenta.
 * @param[in]  _interes   El interés en porcentaje con el que se iniciará la cuenta.
 */
CuentaAhorro::CuentaAhorro (double _cantidad, double _interes):
			Cuenta {_cantidad}, interes {_interes}{
std::cout<<"Constructor Cuenta Ahorro"<<std::endl;
}

/**
 * @brief      Destructor de la clase
 */
CuentaAhorro::~CuentaAhorro ()
{
   std::cout << "Destructor Cuenta Ahorro" << std::endl;
}

/**
 * @brief      Construye CuentaAhorro por copia
 *
 * @param[in]  rhs   El objeto que queremos copiar.
 */
CuentaAhorro::CuentaAhorro (const CuentaAhorro &rhs)
{
 SetSaldo(rhs.GetSaldo());
 this->interes = rhs.interes;
}

/**
 * @brief      Se sobrecarga el operador '=' para dos clases Cuenta Ahorro
 *
 * @param[in]  rhs   The right hand side
 */
void CuentaAhorro::operator= (const CuentaAhorro &rhs)
{
 SetSaldo(rhs.GetSaldo());
 this->interes = rhs.interes;
}

/**
 * @brief      { Calcula el interes de la cuenta de ahorros  }
 *
 * @return     { Regresa el saldo de la cuenta después de efectuarse el cálculo de interés }
 */
double CuentaAhorro::CalcularInteres ()
{
   return ((this->interes/100) * GetSaldo ());
}
