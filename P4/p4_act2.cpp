#include <iostream>

class Rectangulo
{
 private:
  double anchura {1.0};
  double longitud {1.0};
 public:
  void setAnchura(double ancho);
  double getAnchura ();
  void setLongitud (double longi);
  double getLongitud ();
  Rectangulo (); //constructor por defecto
  Rectangulo (double ancho, double longi); //constructor rectangulo
  Rectangulo (double dat); //constructor para cuadrado
  Rectangulo (const Rectangulo &r); //constructor copia
  ~Rectangulo  ();
  double Perimetro ();
  double Area ();
  void operator = (const Rectangulo &rect);

};

void Rectangulo::setLongitud(double longi)
{
 if (longi > 0.0 and longi <20.0) this->longitud = longi;
 else this-> longitud = 1.0 ;
}

void Rectangulo::setAnchura(double ancho)
{
 if (ancho > 0.0 and ancho <20.0) this->anchura = ancho;
 else this-> anchura = 1.0 ;
}

double Rectangulo::getLongitud ()
{
 return this->longitud;
}

double Rectangulo::getAnchura()
{
 return this->anchura;
}

Rectangulo::Rectangulo ():  anchura {1.0}, longitud {1.0}
{
 std::cout<< "Inicializador predeterminado"<< std::endl;
}

Rectangulo::Rectangulo (double dat) :  anchura {dat}, longitud {dat}
{
 setAnchura (dat);
 setLongitud (dat);
}

Rectangulo::Rectangulo (double ancho, double longi) : anchura {ancho}, longitud {longi}
{
 setAnchura (ancho);
 setLongitud (longi);
}

Rectangulo::Rectangulo (const Rectangulo &r)
{
 this->longitud = r.longitud;
 this->anchura = r.anchura;
}

Rectangulo::~Rectangulo  ()
{
 std::cout << "Destructor" << std::endl;
}

double Rectangulo::Perimetro ()
{
 return (2*(this->longitud + this->longitud));
}

double Rectangulo::Area ()
{
 return (this->longitud * this->longitud);
}

void Rectangulo::operator = (const Rectangulo &rect)
{
 setAnchura(rect.anchura);
 setLongitud(rect.longitud);
}

int main ()
{
   Rectangulo r1;
   Rectangulo r2 (5.0);
   Rectangulo r3 (9.0, 4.0);

   std::cout << "El área del r1 es: " << r1.Area() << std::endl;
   std::cout << "El área del r2 es: " << r2.Area() << std::endl;
   std::cout << "El área del r3 es: " << r3.Area() << std::endl;

   std::cout << "El perímetro del r1 es: " << r1.Perimetro() << std::endl;
   std::cout << "El perímetro del r2 es: " << r2.Perimetro() << std::endl;
   std::cout << "El perímetro del r3 es: " << r3.Perimetro() << std::endl;

   std::cout << "El área del r1 es: " << r1.Area() << std::endl;
   std::cout << "El área del r2 es: " << r2.Area() << std::endl;
   std::cout << "El área del r3 es: " << r3.Area() << std::endl;

   std::cout << "La anchura de r1 es: " << r1.getAnchura() << " La longitud de r1 es: " << r1.getLongitud() << std::endl;
   std::cout << "La anchura de r2 es: " << r2.getAnchura() << " La longitud de r2 es: " << r2.getLongitud() << std::endl;
   r1 = r2;
   std::cout << "La anchura de r1 es: " << r1.getAnchura() << " La longitud de r1 es: " << r1.getLongitud() << std::endl;
   std::cout << "La anchura de r2 es: " << r2.getAnchura() << " La longitud de r2 es: " << r2.getLongitud() << std::endl;

}
