#include <iostream>

class Complejo
{
 private:
  double Real {0.0};
  double Imaginario {0.0};
 public:
  Complejo ();
  Complejo (const Complejo &c);
  Complejo (double ra);
  Complejo (double ra, double ba);
  void setReal (double a);
  void setImaginario (double b);
  Complejo Suma (const Complejo &co);
  Complejo Resta (const Complejo &co);
  void Imprimir ();
};

void Complejo::setReal (double a)
{
 this->Real = a;
}

void Complejo::setImaginario (double b)
{
 this->Imaginario = b;
}

Complejo::Complejo (): Real {1.0}, Imaginario {1.0}
{
 std::cout<< "Inicializador predeterminado"<< std::endl;
}

Complejo::Complejo (const Complejo &c)
{
 this->Real = c.Real;
 this->Imaginario = c.Imaginario;
}

Complejo::Complejo (double ra, double ba) : Real {ra}, Imaginario {ba}
{
 setReal (ra);
 setImaginario (ba);
}


Complejo Complejo::Suma (const Complejo &co)
{
 Complejo ans;
 ans.Real = this-> Real + co.Real;
 ans.Imaginario = this-> Imaginario + co.Imaginario;
 return ans;
}

Complejo Complejo::Resta (const Complejo &co)
{
 Complejo ans;
 ans.Real = this-> Real - co.Real;
 ans.Imaginario = this-> Imaginario - co.Imaginario;
 return ans;
}

void Complejo::Imprimir ()
{
 std::cout<< "El resultado de la operación realizada es: " << this->Real << " + " << this->Imaginario << "i" <<std::endl;
}

int main ()
{
 Complejo  c1 (2.0, 3.0);
 Complejo  c2 (4.0, 5.0);

 (c1.Suma(c2)).Imprimir ();
 (c1.Resta(c2)).Imprimir ();

}
