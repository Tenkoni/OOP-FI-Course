#include "Cuenta.hpp"

/**
 * @brief      Constuye Cuenta con un argumento.
 *
 * @param[in]  _saldo  El saldo con el que se creará al cuenta.
 */
Cuenta::Cuenta (double _saldo) :  saldo{_saldo}
{
  std::cout<<"Constructor de Cuenta"<<std::endl;
  if (_saldo < 0.0){
	_saldo = 0.0;
  }
  this->saldo = _saldo;
}

/**
 * @brief      Construye el objeto por copia
 *
 * @param[in]  rhs   La cuenta que queremos copiar.
 */
Cuenta::Cuenta (const Cuenta &rhs)
{
  this->saldo = rhs.saldo;
}

/**
 * @brief      Se sobrecarga el operador '=' para dos clases Cuenta
 *
 * @param[in]  rhs   The right hand side
 */
void Cuenta::operator= (const Cuenta &rhs)
{
  this->saldo = rhs.saldo;
}

/**
 * @brief      Establece el saldo
 *
 * @param[in]  _saldo  El saldo que se desea.
 */
void Cuenta::SetSaldo (double _saldo)
{
  this->saldo = _saldo;
}

/**
 * @brief      Añade una cantidad al saldo
 *
 * @param[in]  _cantidad  La cantidad que se desea abonar
 */
void Cuenta::Abonar (double _cantidad)
{
     this->saldo += _cantidad;
}

/**
 * @brief      Quita una cantidad del saldo
 *
 * @param[in]  _cantidad  La cantidad que se desea quitar
 *
 * @return     True si se pudo quitar o false en caso contrario
 */
bool Cuenta::Cargar (double _cantidad)
{
     if (_cantidad > this->saldo)
	return false;
     else{
	this->saldo -= _cantidad;
	return true;
     }
}

/**
 * @brief      Obtiene el saldo
 *
 * @return     Regresa el saldo como double.
 */
double Cuenta::GetSaldo () const
{
 return (this->saldo);
}

/**
 * @brief      Destructor de la cuenta.
 */
Cuenta::~Cuenta ()
{
 std::cout<<"destructor de cuenta"<<std::endl;
}