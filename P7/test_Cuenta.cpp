#include <iostream>
#include "Cuenta.hpp"
#include "CuentaAhorro.hpp"
#include "CuentaCheques.hpp"

int main ()
{
	Cuenta cuenta(5000); //inicializando con 5000 de saldo
	CuentaAhorro cuentaahorro(10000.0, 10.0); ///inicializando con 10000 de saldo y 10% de interés
	CuentaCheques cuentacheques(15000, 100);//inicializando con 15000 de saldo y 100 de cuota
	
	std::cout<<"La Cuenta tiene $"<<cuenta.GetSaldo()<< " de saldo"<< std::endl;
	cuenta.SetSaldo(6000); //saldo establecido en 6000
	std::cout<<"Después del setter, la Cuenta tiene $"<<cuenta.GetSaldo()<< " de saldo"<< std::endl;
	cuenta.Abonar(2000); //se le agrega 2000 a la cuenta
	std::cout<<"Después de Abonar, la Cuenta tiene $"<<cuenta.GetSaldo()<< " de saldo"<< std::endl;
	cuenta.Cargar(5000); //se retira 5000
	std::cout<<"Después de Cargar, la Cuenta tiene $"<<cuenta.GetSaldo()<< " de saldo\n\n"<< std::endl;

	std::cout<<"La CuentaAhorro tiene $"<<cuentaahorro.GetSaldo()<< " de saldo"<< std::endl;
	std::cout<<"El interes generado es de $"<<cuentaahorro.CalcularInteres()<<"\n\n"<<std::endl;

	std::cout<<"La CuentaCheques tiene $"<<cuentacheques.GetSaldo()<< " de saldo"<< std::endl;
	cuentacheques.Abonar(cuentacheques.Cargar(20000)); //retira 20000 de la cuentacheques, se regresará 
	                                                   //un bool de acuerdo al resulado que tenga la 
	                                                   //función, en este caso será false y no entrará 
	                                                   //la función.
	std::cout<<"La CuentaCheques tiene $"<<cuentacheques.GetSaldo()<< " de saldo"<< std::endl;
	cuentacheques.Abonar(cuentacheques.Cargar(10000)); //retira 10000 de la cuentacheques, se regresará 
	                                                   //un bool de acuerdo al resulado que tenga la 
	                                                   //función, en este caso será true y entrará
	                                                   //la función abonar que cobrará la cuota.
	std::cout<<"La CuentaCheques tiene $"<<cuentacheques.GetSaldo()<< " de saldo"<< std::endl;

	//fin del driver, se iniciarán los destructores
}
