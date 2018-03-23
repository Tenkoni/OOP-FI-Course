/* bankaccount.cpp
 *
 * Ejemplo de una clase de cuenta bancaria simple.
 *
 * para compilar escriba en una consola en el mismo directorio donde 
 * está este archivo: 
 *
 * g++ -Wall -std=c++11 -o bankaccount.out bankaccount.cpp
 */

#include <iostream>
// para usar cin y cout


/*---------------------------------------------------------------------
 *								class BankAccount
 *-------------------------------------------------------------------*/
class BankAccount 
{
public:
	static constexpr double PENALIZACION {10.0};

	BankAccount ();
	BankAccount (double nuevoSaldo, double nuevoInteres);

	void Depositar (double cantidad);
	void Imprimir ();
	bool Debitar (double cantidad);
	void AgregarInteres ();

	void SetSaldo (double nuevoSaldo);
	double GetSaldo ();

	void SetInteres (double nuevoInteres);
	double GetInteres ();

	double GetPenalizacion ();

private:
	double saldo {0.0};
	double interes {0.0};
};

BankAccount::BankAccount () : saldo (0.0), interes (0.0)
{
	// nada
}

BankAccount::BankAccount (double nuevoSaldo, double nuevoInteres) :
	saldo (nuevoSaldo), interes (nuevoInteres)
{
	// hacer saldo >= 0.0
	
	// hacer 0.0 <= interes <= 0.1
}

void BankAccount::Depositar (double cantidad)
{
	// sumar al saldo actual la nueva cantidad, si y únicamente si la nueva
	// cantidad es positiva
}

void BankAccount::Imprimir ()
{
	// imprime en la pantalla el saldo y el interés de esta cuenta
}

bool BankAccount::Debitar (double cantidad)
{
	// SI la cantidad a debitar es menor que el saldo actual, ENTONCES
	//		debita la cantidad del saldo actual
	//		devuelve true para avisar que la operación se realizó con éxito
	// SINO
	//		quita la cantidad PENALIZACION del saldo actual
	//		SI el saldo actual fuera menor que cero, ENTONCES
	//			hacer saldo = 0.0
	//		FIN SI
	//		devuelve false para avisar que la operación no se llevó a cabo
	// FIN SI
}

void BankAccount::AgregarInteres ()
{
	// saldo = saldo + saldo * interes
}

void BankAccount::SetSaldo (double nuevoSaldo)
{
	// antes de asignar nuevoSaldo a la variable miembro saldo, verificar que se
	// cumpla nuevoSaldo >= 0.0 (igual que en el constructor)
}

double BankAccount::GetSaldo ()
{
	// devuelve el saldo asociado esta cuenta
}

void BankAccount::SetInteres (double nuevoInteres)
{
	// antes de asignar nuevoInteres a la variable miembro interes, verificar que se
	// cumpla 0.0 <= interes <= 0.1 (igual que en el constructor)
}

double BankAccount::GetInteres ()
{
	// devuelve el interés asociado a esta cuenta
}

double BankAccount::GetPenalizacion ()
{
	// devuelve la penalización asociada a esta clase
}


/*-----------------------------------------------------------------------------
 *							Driver program
 *-----------------------------------------------------------------------------*/
int main()
{
	BankAccount miCuenta {5000.0, 7.0};
	// nueva cuenta bancaria, con $5000.00 de saldo a 7% de interés

	miCuenta.Imprimir ();

	double cantidadADepositar {0.0};
	std::cout << "Por favor indique la cantidad a depositar: ";
	std::cin >> cantidadADepositar;

	miCuenta.Depositar (cantidadADepositar);

	double cantidadADebitar {0.0};
	std::cout << "Por favor indique la cantidad a debitar: ";
	std::cin >> cantidadADebitar;

	if (miCuenta.Debitar (cantidadADebitar) == true) {
		std::cout << "La operación se realizó con éxito!\n";
		std::cout << "Su saldo actual es: $" << miCuenta.GetSaldo () << std::endl;
	}
	else {
		std::cout << "Ups, saldo insuficiente\n";
		std::cout << "A su cuenta se le han quitado $" << miCuenta.GetPenalizacion ();
		std::cout << " por penalización de saldo insuficiente\n";
		std::cout << "Su saldo actual es: $" << miCuenta.GetSaldo () << std::endl;
	}

	miCuenta.AgregarInteres ();
	// llegó el fin de mes y hay que sumarle los intereses generados al saldo
	// actual de esta cuenta
	
	miCuenta.Imprimir ();

	return 0;
}
