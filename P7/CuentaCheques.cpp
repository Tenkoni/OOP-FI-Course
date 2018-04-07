#include "CuentaCheques.hpp"

/**
 * @brief      Construye la clase CuentaCheques con dos argumentos
 *
 * @param[in]  _cantidad  El saldo con el que se creará la cuenta
 * @param[in]  _cuota     La cuota que se le cobrará por transacción
 */
CuentaCheques::CuentaCheques (double _cantidad, double _cuota) : 
					Cuenta{_cantidad}, cuota{_cuota}
{
		std::cout<<"Constructor cuenta cheques"<<std::endl;
}

/**
 * @brief      Destructor de la clase CuentaCheques.
 */
CuentaCheques::~CuentaCheques()
{
	std::cout<<"Destructor de cuenta cheques"<<std::endl;
}

/**
 * @brief      Construye la clase por copia.
 *
 * @param[in]  rhs   El objeto que queremos copiar
 */
CuentaCheques::CuentaCheques (const CuentaCheques &rhs)
{
	SetSaldo(rhs.GetSaldo());
	this->cuota = rhs.cuota;
}

/**
 * @brief      Se sobrecarga el operador '=' para dos clases CuentaCheques
 *
 * @param[in]  rhs   The right hand side
 */
void CuentaCheques::operator= (const CuentaCheques &rhs)
{
	SetSaldo(rhs.GetSaldo());
	this->cuota = rhs.cuota;
}

/**
 * @brief      Obtiene el valor de la cuota.
 *
 * @return     El valor double de la cuota 
 */
double CuentaCheques::GetCuota ()
{
	return (this->cuota);
}

/**
 * @brief      Se retira una cantidad del saldo de la cuenta
 *
 * @param[in]  _cantidad  La cantidad que se desea retirar
 *
 * @return     Regresa True si se pudo efectuar el retiro, en caso contrario false.
 */
bool CuentaCheques::Cargar (double _cantidad)
{
	if (_cantidad + this->cuota > GetSaldo())
		return false;
    else{
		SetSaldo(GetSaldo() - _cantidad);
		return true;
     }
}

/**
 * @brief      Efectuo el cobro de cuota
 * @param[in]  _cantidad  el valor de la cuota.
 */
void CuentaCheques::Abonar (double _cantidad)
{
	SetSaldo(GetSaldo() - _cantidad);

}
