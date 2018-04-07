
//reloj_act2.cpp

#include <iostream>
#include <array>
#include <stdexcept>

/*-----------------------------------------------------------------------------
 *								class Reloj
 *-----------------------------------------------------------------------------*/
class Reloj 
{
public:
	Reloj ();
	// Constructor por defecto (sin argumentos)
	
	Reloj (int horas);
	// constructor con un argumento
	
	Reloj (int horas, int min, int seg);
	// constructor con tres argumentos
	
	Reloj (Reloj &rhs);

	~Reloj();

	void Imprimir ();
	void Poner (int h, int m, int s);
	void Avanzar ();
	bool Comparar (const Reloj &otro) const;
	bool operator== (const Reloj & otro);
	bool operator!= (const Reloj & otro);
	bool operator< (const Reloj & otro);
	bool operator>= (const Reloj & otro);


	void SetHora (int hora);
	void SetMin (int minu);
	void SetSeg (int segu);
	int GetHora () const;
	int GetMin () const;
	int GetSeg () const;

private:
	int hrs {0};
	int min {0};
	int seg {0};
};


bool Reloj::Comparar (const Reloj &otro) const
{
	if (this->hrs == otro.hrs and this->min == otro.min and this->seg == otro.seg) {
		return true;
	}
	else { return false; }
}

bool Reloj::operator== (const Reloj &otro) 
{
	if (this->hrs == otro.hrs and this->min == otro.min and this->seg == otro.seg) {
		return true;
	}
	else { return false; }
}

bool Reloj::operator!= (const Reloj & otro) 
{
	return !operator==(otro);
}

bool Reloj::operator< (const Reloj & otro) 
{
	if (this->hrs < otro.hrs) { return true; }

	if (this->hrs == otro.hrs and this->min < otro.min) { return true; }

	if (this->hrs == otro.hrs and this->min == otro.min and this->seg < otro.seg) {
		return true;
	}

	return false;
}

bool Reloj::operator>= (const Reloj & otro) 
{
	return !operator< (otro);
}

Reloj::~Reloj()
{
	// nada
}


Reloj::Reloj () : hrs (0), min (0), seg (0)
{
	std::cout << "Constructor por defecto" << std::endl;
	// nada
}

Reloj::Reloj (int lasHoras) : hrs (lasHoras), min (0), seg (0)
{
	// nada
}

Reloj::Reloj (int lasHoras, int losMin, int losSeg) 
				: hrs (lasHoras), 
				  min (losMin), 
				  seg (losSeg)
{
  //nada
}

Reloj::Reloj (Reloj &rhs)
{    
  if (!(rhs.GetHora() >=0 && rhs.GetHora()<24))
    {
    this->hrs = this->min = this->seg = 0;
    rhs.SetHora(0);
    rhs.SetMin(0);
    rhs.SetSeg(0);
    throw std::range_error {"El objeto del cual se copiará se encuentra en un estado inseguro, se colocarán en modo seguro."};
    }
   
    if (!(rhs.GetMin() >=0 && rhs.GetMin()<60))
    {
    this->hrs = this->min = this->seg = 0;
    rhs.SetHora(0);
    rhs.SetMin(0);
    rhs.SetSeg(0);
    throw std::range_error {"El objeto del cual se copiará se encuentra en un estado inseguro, se colocarán en modo seguro."};
    }
   
    if (!(rhs.GetSeg()>=0 && rhs.GetSeg()<60))
    {
    this->hrs = this->min = this->seg = 0;
    rhs.SetHora(0);
    rhs.SetMin(0);
    rhs.SetSeg(0);
    throw std::range_error {"El objeto del cual se copiará se encuentra en un estado inseguro, se colocarán en modo seguro."};
    }

	this->hrs = rhs.GetHora();
	this->min = rhs.GetMin();
	this->seg = rhs.GetSeg();
}

void Reloj::SetHora (int hora)
{
	if (hora >= 0 and hora < 24) {
		this->hrs = hora;
	}
	else {
		this->hrs = this->min = this->seg = 0;
		throw std::out_of_range {"Las horas están fuera del rango deseado, la hora se establecerá en modo seguro"};
	}
}

void Reloj::SetMin (int minu)
{
	if (minu >= 0 and minu < 60) {
		this->min = minu;
	}
	else {
		this->hrs = this->min = this->seg = 0;
		throw std::out_of_range {"Los minutos están fuera del rango deseado, la hora se establecerá en modo seguro"};
	}
}

void Reloj::SetSeg (int segu)
{
	if (segu >= 0 and segu < 60) {
		this->seg = segu;
	}
	else {
		this->hrs = this->min = this->seg = 0;
		throw std::out_of_range {"Los segundos están fuera del rango deseado, la hora se establecerá en modo seguro"};
	}
}

int Reloj::GetHora () const
{
	return this->hrs;
}

int Reloj::GetMin () const
{
	return this->min;
}

int Reloj::GetSeg () const
{
	return this->seg;
}

void Reloj::Poner (int h, int m, int s)
{
	this->hrs = h;
	this->min = m;
	this->seg = s;
}

void Reloj::Imprimir ()
{
	std::cout << this->hrs << ":" << this->min << ":" << this->seg << std::endl;
}

void Reloj::Avanzar ()
{
	++this->seg;
	if (this->seg > 59) {
		this->seg = 0;

		++this->min;
		if (this->min > 59) {
			this->min = 0;

			++this->hrs;
			if (this->hrs > 23) {
				this->hrs = 0;
			}
		}
	}
}

int main()
{
  	Reloj r1 {22, 50, 30};
	Reloj r2 {19, 0, 0};
    try{
		Reloj r3 {r1};
	    int a;
	    std::cout<<"Ingresa la hora"<<std::endl;
	    std::cin>>a; 
	    r1.SetHora(a);
	    std::cout<<"Ingresa los minutos"<<std::endl;
	    std::cin>>a;
	    r1.SetMin(a);
	    std::cout<<"Ingresa los segundos"<<std::endl;
	    std::cin>>a; 
	    r1.SetSeg(a);
	    r1.Imprimir();
    }
    catch (std::range_error & e ){
		std::cout<<e.what()<<std::endl;
		
		
	}
	catch (std::out_of_range & e){
	    std::cout<<e.what()<<std::endl;
	    r1.Imprimir();
	}
	
	return 0;
}
