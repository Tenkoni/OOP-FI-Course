
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
	
	Reloj (const Reloj &rhs);

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
    if (!(this->hrs >=0 && this->hrs < 24))
    {
    this->hrs = 0;
    this->min = 0;
    this->seg = 0;
    throw std::range_error {"La hora está fuera del rango deseado, verifícala"};
    }
    
    if (!(this->hrs >=0 && this->hrs < 60))
    {
    this->hrs = 0;
    this->min = 0;
    this->seg = 0;
    throw std::range_error {"Los minutos están fuera del rango deseado, verifícalos"};
    }
    
    if (!(this->hrs >=0 && this->hrs < 60))
    {
    this->hrs = 0;
    this->min = 0;
    this->seg = 0;
    throw std::range_error {"Los segundos están fuera del rango deseado, verifícalos"};
    }
}
    
Reloj::Reloj (Reloj &rhs)
{
    if (!((rhs.GetHora() >=0 && rhs.GetHora()<24) )
    {
    this->hrs = this->min = this->seg = 0;
    rhs.SetHora(0);
    rhs.SetMin(0);
    rhs.SetSeg(0);
    throw std::range_error {"El objeto del cual se copiará se encuentra en un estado inseguro, se colocarán en modo seguro."};
    }
    
    if (!(rhs.GetMin() >=0 && rhs.GetMin()<60))
    {
    this->hrs = 0;
    this->min = 0;
    this->seg = 0;
    throw std::range_error {"Los minutos están fuera del rango deseado, verifícalos"};
    }
    
    if (!(rhs.GetSeg()>=0 && rhs.GetSeg()<60))
    {
    this->hrs = 0;
    this->min = 0;
    this->seg = 0;
    throw std::range_error {"Los segundos están fuera del rango deseado, verifícalos"};
    }
}



void Reloj::SetHora (int hora)
{
	if (hora >= 0 and hora < 24) {
		this->hrs = hora;
	}
	else {
		this->hrs = this->min = this->seg = 0;
		throw std::out_of_range {"La hora está fuera del rango deseado, verifícala"};
	}
}

void Reloj::SetMin (int minu)
{
	if (minu >= 0 and minu < 60) {
		this->min = minu;
	}
	else {
		this->hrs = this->min = this->seg = 0;
		throw std::out_of_range {"Los minutos están fuera del rango deseado, verifícalos"};
	}
}

void Reloj::SetSeg (int segu)
{
	if (segu >= 0 and segu < 60) {
		this->seg = segu;
	}
	else {
		this->hrs = this->min = this->seg = 0;
		throw std::out_of_range {"Los segundos están fuera del rango deseado, verifícalos"};
	}
}

int Reloj::GetHora ()
{
	return this->hrs;
}

int Reloj::GetMin ()
{
	return this->min;
}

int Reloj::GetSeg ()
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
    bool exit {false};
    try{
	    Reloj r1 {5, 50, 30};
		Reloj r2 {19, 0, 0};
	}
	catch (std::range_error & e ){
		std::cout<<e.what()<<std::endl;
	}

	try{
		Reloj r3 {r1};
	}
	catch (std::range_error & e ){
		std::cout<<e.what()<<std::endl;
	}

	
    while (!exit)
    {
	try{
	    int a;
	    std::cin>>a; //reemplazar con entradas reales;
	    r1.SetHora(20);
	    r1.SetMin(10);
	    r1.SetSeg(65);
	    exit = true;
	    r1.Imprimir();
	   }
	catch (std::out_of_range & e){
	    std::cout<<e.what()<<std::endl;
        r1.Imprimir();
        }
    }
/*
	if (r1 == r3) {
		std::cout << "r1 es igual a r3" << std::endl;
	}

	if (r1 != r2) {
		std::cout << "r1 es diferentes de r2" << std::endl;
	}

	if (r1 < r2) {
		std::cout << "r1 es menor a r2" << std::endl;
	}

	if (r2 >= r1) {
		std::cout << "r2 es mayor o igual a r1" << std::endl;
	}
*/

	return 0;
}
