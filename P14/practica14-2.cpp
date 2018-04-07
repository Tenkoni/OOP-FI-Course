#include <iostream>
#include <vector>

class ISubject
{
	public:
	virtual void Attach (IObserver * o) = 0;
	// inserta un observador en la lista de observadores
	virtual void Dettach (IObserver * o) = 0;
	// remueve un observador de la lista de observadores
	virtual void Notify () = 0;
	// recorre la lista de observadores efectuando la operación Update() de cada
	// uno de ellos (ver la interfaz IObserver)
	virtual int GetState () const = 0;
	// con este método los observadores podrán "ver" el estado de su sujeto
	// observado y actualizar su propio estado si así lo requieren

};


class IObserver: public Reloj
{
	public:        
        Reloj rhs;
	   virtual void Update (Reloj * r) = 0;
	// cada observador recibirá una referencia a su sujeto observado. Con esto
	// será posible transferir el estado del sujeto al observador para que este
	// último se actualice correctamente (ver el comentario del dato miembro
	// 'state' de la clase ElSujetoObservado)
	
};

void Update(Reloj *r)
{
    if(this->rhs.Comparar(r.GetState)==true)
    {
        std::cout<<"Hora de despertarse\n";
    }
}

class Reloj: public Isubject, public Iobserver 
{	
	private:

		int hora {0};
		int min {0};
		int seg {0};
		
		std::vector<Iobserver> vector;
		

	public:

		static Reloj& GetInstance();

		bool Comparar(int h, int m, int s) const;	

		void Imprimir() const;

		void SetHoras(int h, int m, int s);
		
		void operator = (Reloj& rhs);
		
		virtual void Attach(Iobserver *o)=0;
		
		virtual void Dettach(Iobserver *o)=0;
		
		virtual void Notify()=0;
		
		virtual int GetState()=0;
		
		virtual void Update(Reloj *r)=0;

};

void Reloj::SetHoras(int h, int m, int s)
{
	this->seg=s;
	this->min=m;
	this->hora=h;
	
	if(this->seg>60)
	{
		this->seg=0;
		this->min=this->min+1;
		if(this->min>60)
		{
			this->min=0;
			this->hora=this->hora+1;
			if(this->hora>24)
			{
				this->hora=0;
			}
		}
	}
	
}

void Reloj::operator =(Reloj& rhs)
{
    this->hora=rhs->hora;
    this->min=rhs->min;
    this->seg=rhs->seg;
}

Reloj& Reloj::GetInstance()
{
	static Reloj instance;
	return instance;
}


void Reloj::Imprimir() const
{
	std::cout<<this->hora<<":"<<this->min<<":"<<this->seg<<std::endl;
}

bool Reloj::Comparar(Reloj& r) const
{
	if(this->hora!=h){return false;}
	if(this->min!=m){return false;}
	if(this->seg!=s){return false;}

	return true;
}

void Reloj::Attach(Iobserver *o)
{
	Reloj temp (12, 30, 20);
    vector.push_back(temp);
}
		
void Reloj::Dettach()
{
    vector.pop_back();
}
		
void Reloj::Notify()
{
    this->seg=seg+1;
    if(seg>60 || seg<0)
    {
        this->seg=0;
		this->min=this->min+1;
		if(this->min>60)
		{
			this->min=0;
			this->hora=this->hora+1;
			if(this->hora>24)
			{
				this->hora=0;
			}
		}
	}
    }
}
		

int main(void)
{
    Reloj observer.SetHora(12,10,54);
    this.Attach(observer);
    Observer observer2.SetHora(21,12,43);
    this->Attach(observer2);

    for(i=0;i<3600;i++)
    {
        this.Notify();
        for(size_t i{0};i<vector.size_t;i++)
        {
            vector[i].Update(this);
        }
    }
}
