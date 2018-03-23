#include <iostream>

class BankAccount
{
public:
    //constexpr double PENAL();
    BankAccount ();
    BankAccount (double fundsi, double interesti);
    double getFunds();
    double getInterest();
    void setInterest(double interes);
    void setFunds(double money);
    bool Withdraw(double money);
    void Deposit (double money);
    void Imprimir ();
    void AddInterest ();
    double GetPenalizacion();

private:
    double funds;
    double interest;
    double InterestCalc();
};

BankAccount::BankAccount() : funds (0.0), interest (0.0)
{

}

BankAccount::BankAccount (double fundsi, double interesti) : funds (fundsi), interest (interesti)
{
  setFunds(fundsi);
  setInterest(interesti);
}

//constexpr double BankAccount::PENAL () = 10.0;

double BankAccount::getFunds()
{
    return this->funds;
}

void BankAccount::setFunds(double money)
{
    this->funds = money;
}

double BankAccount::getInterest()
{
    return this->interest;
}

void BankAccount::Deposit (double money)
{
    this->funds += money;
}

bool BankAccount::Withdraw (double money)
{
    if (getFunds() < money)
    {
      Deposit(-10.0);
      return false;
    }
    else
    {
      money *= -1;
      Deposit(money);
    }
    return true;
}



void BankAccount::Imprimir ()
{
    std::cout<<"Fondos totales: "<< getFunds() << "\n" <<"Interes Actual: "<< getInterest() * 100 << "%" <<std::endl;
}

void BankAccount::AddInterest()
{
    setFunds(InterestCalc());
}

void BankAccount::setInterest(double interes)
{
  interes = interes / 100;
  if (0<=interes and interes <= 0.1)
    this->interest = interes;
  else{
    std::cout<<"Estableciendo interés a un valor seguro (5%)"<<std::endl;
    this->interest = .05;
  }
}

double BankAccount::InterestCalc()
{
    return ( getFunds() + (this->interest * getFunds()));
}

double BankAccount::GetPenalizacion ()
{
  //return PENAL;
  return 10.0;
}

int main ()
{
    BankAccount cuentita {20000.0, 8.5};
    cuentita.Imprimir ();
    double nsaldo;
    std::cout << "Ingrese la cantidad a depositar: " <<std::endl;
    std::cin >> nsaldo;
    cuentita.Deposit (nsaldo);
    std::cout << "Ingrese la cantidad a retirar: "<<std::endl;
    std::cin >> nsaldo;
    if (cuentita.Withdraw(nsaldo))
      std::cout << "Cantidad retirada exitosamente." << std::endl;
    else
      std::cout << "Fondos insuficientes, añadiendo penalización de :"<< cuentita.GetPenalizacion() << std::endl;
    std::cout << "Su saldo actual es de: " << cuentita.getFunds() <<std::endl;

    cuentita.AddInterest();
    cuentita.Imprimir();


}
