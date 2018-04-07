#include <iostream>
#include <string>
#include <vector>

class Datos
{
private:
	std::string name {"NA"};
	std::string address {"NA"};
	std::string city {"NA"};
	std::string state {"NA"};
	std::string zipcode {"NA"};

public:
	Datos () = default;

	/**
	 * @brief      { Constructor con argumentos de la clase Datos }
	 *
	 * @param[in]  _name     El nombre
	 * @param[in]  _address  La dirección
	 * @param[in]  _city     La ciudad
	 * @param[in]  _state    El estado
	 * @param[in]  _zipcode  El código postal
	 */
	Datos (std::string _name, std::string _address, std::string _city, std::string _state, std::string _zipcode);
	
	~Datos ();

	/**
	 * @brief      Obtiene el dato name del objeto.
	 *
	 * @return     El name.
	 */
	std::string GetName() const;

	/**
	 * @brief      Obtiene el dato address del objeto.
	 *
	 * @return     La address.
	 */
	std::string GetAddress() const;

	/**
	 * @brief      Obtiene el dato city del objeto.
	 *
	 * @return     La city.
	 */
	std::string GetCity() const;

	/**
	 * @brief      Obtiene el dato state del objeto.
	 *
	 * @return     El state.
	 */
	std::string GetState() const;

	/**
	 * @brief      Obtiene el dato zipcode del objeto.
	 *
	 * @return     El zipcode.
	 */
	std::string GetZipcode() const;

};

Datos::Datos (std::string _name, std::string _address, std::string _city, std::string _state, std::string _zipcode) :
			name {_name}, address {_address}, city {_city}, state {_state}, zipcode{_zipcode}
{
	//nada
}


Datos::~Datos ()
{
	//nada
}

std::string Datos::GetName() const
{
	return (this->name);
}

std::string Datos::GetAddress() const
{
	return (this->address);
}

std::string Datos::GetCity() const
{
	return (this->city);
}

std::string Datos::GetState() const
{
	return (this->state);
}

std::string Datos::GetZipcode() const
{
	return (this->zipcode);
}

class Paquete 
{
private:
	Datos emisor;
	Datos receptor;
	double peso;
	double costo_por_kilo;

public:
	Paquete() = default;

	/**
	 * @brief      { Constructor con argumentos de paquete }
	 *
	 * @param[in]  _name1     El nombre del emisor
	 * @param[in]  _address1  La dirección del emisor
	 * @param[in]  _city1     La ciudad del emisor
	 * @param[in]  _state1    El estado del emisor
	 * @param[in]  _zipcode1  El código postal del emisor
	 * @param[in]  _name2     El nombre del receptor
	 * @param[in]  _address2  La dirección del receptor
	 * @param[in]  _city2     La ciudad del receptor
	 * @param[in]  _state2    El estado del receptor
	 * @param[in]  _zipcode2  El código postal del receptor
	 * @param[in]  _peso      El peso del paquete
	 * @param[in]  _costo     El costo de envío del paquete
	 */
	Paquete (std::string _name1, std::string _address1, std::string _city1, std::string _state1, std::string _zipcode1, 
			std::string _name2, std::string _address2, std::string _city2, std::string _state2, std::string _zipcode2, 
			double _peso, double _costo);

	/**
	 * @brief      Destruye el objeto paquete
	 */
	~Paquete();

	/**
	 * @brief      Regresa un aputandor a el dato emisor, que es un objeto tipo Datos.
	 *
	 * @return     Apuntador a emisor.
	 */
	Datos GetEmisor() const;

	/**
	 * @brief      Regresa un aputandor a el dato receptor, que es un objeto tipo Datos
	 *
	 * @return     Aputandor a receptor.
	 */
	Datos GetReceptor() const;

	/**
	 * @brief      Obtiene el peso del paquete.
	 *
	 * @return     el dato peso
	 */
	double GetPeso();

	/**
	 * @brief      Obtiene el costo por kilo que tendrá el paquete
	 *
	 * @return     El dato costo_por_kilo
	 */
	double GetCostoKilo();

	/**
	 * @brief      { Calcula el costo de envío que tendrá el paquete, multiplicando costo_por_kilo y peso,
	 *  				el método será sobreescrito, así que es virtual}
	 *
	 * @return     {  el resultado de multiplicar costo_por_kilo con peso }
	 */
	virtual double CalcularCosto();

};

Paquete::Paquete(std::string _name1, std::string _address1, std::string _city1, std::string _state1, std::string _zipcode1, 
			std::string _name2, std::string _address2, std::string _city2, std::string _state2, std::string _zipcode2, 
			double _peso, double _costo) :
			emisor {_name1, _address1, _city1, _state1, _zipcode1},
			receptor { _name2, _address2, _city2, _state2, _zipcode2},
			peso {_peso}, costo_por_kilo {_costo}
{
	//nada
}

Paquete::~Paquete()
{
	//nada
}

Datos Paquete::GetEmisor () const
{
	return (this->emisor);
}

Datos Paquete::GetReceptor() const
{
	return (this->receptor);
}

double Paquete::GetPeso()
{
	return (this->peso);
}

double Paquete::GetCostoKilo()
{
	return (this->costo_por_kilo);
}

double Paquete::CalcularCosto()
{
	return (this->peso)*(this->costo_por_kilo);
}

class PaqueteDosDias : public Paquete
{
private:
	double cuota;

public:
	PaqueteDosDias() = default;

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  _name1     El nombre del emisor
	 * @param[in]  _address1  La dirección del emisor
	 * @param[in]  _city1     La ciudad del emisor
	 * @param[in]  _state1    El estado del emisor
	 * @param[in]  _zipcode1  El código postal del emisor
	 * @param[in]  _name2     El nombre del receptor
	 * @param[in]  _address2  La dirección del receptor
	 * @param[in]  _city2     La ciudad del receptor
	 * @param[in]  _state2    El estado del receptor
	 * @param[in]  _zipcode2  El código postal del receptor
	 * @param[in]  _peso      El peso del paquete
	 * @param[in]  _costo     El costo de envío del paquete
	 * @param[in]  _cuota     La cuota extra que se cobra al ser envío de dos días
	 */
	PaqueteDosDias(std::string _name1, std::string _address1, std::string _city1, std::string _state1, std::string _zipcode1, 
			std::string _name2, std::string _address2, std::string _city2, std::string _state2, std::string _zipcode2, 
			double _peso, double _costo, double _cuota);

	/**
	 * @brief      Destruye el objeto 
	 */
	~PaqueteDosDias();

	/**
	 * @brief      { Sobreescribe CalcularCosto y lo modifica para agregar el valor de la cuota }
	 *
	 * @return     { El resultado de efectuar la operación (peso * cost_por_kilo)+cuota }
	 */
	double CalcularCosto() override;

};

PaqueteDosDias::PaqueteDosDias(std::string _name1, std::string _address1, std::string _city1, std::string _state1, std::string _zipcode1, 
			std::string _name2, std::string _address2, std::string _city2, std::string _state2, std::string _zipcode2, 
			double _peso, double _costo, double _cuota) :
			Paquete {_name1, _address1, _city1, _state1, _zipcode1, 
			_name2, _address2, _city2, _state2, _zipcode2, 
			_peso,  _costo}, cuota {_cuota}
{
	//nada
}

PaqueteDosDias::~PaqueteDosDias()
{
	//nada
}
		
double PaqueteDosDias::CalcularCosto() 
{
	return (((GetPeso())*(GetCostoKilo()))+this->cuota);
}	


class PaqueteNocturno : public Paquete
{
private:
	double cuotaex;

public:
	PaqueteNocturno() = default;

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  _name1     El nombre del emisor
	 * @param[in]  _address1  La dirección del emisor
	 * @param[in]  _city1     La ciudad del emisor
	 * @param[in]  _state1    El estado del emisor
	 * @param[in]  _zipcode1  El código postal del emisor
	 * @param[in]  _name2     El nombre del receptor
	 * @param[in]  _address2  La dirección del receptor
	 * @param[in]  _city2     La ciudad del receptor
	 * @param[in]  _state2    El estado del receptor
	 * @param[in]  _zipcode2  El código postal del receptor
	 * @param[in]  _peso      El peso del paquete
	 * @param[in]  _costo     El costo de envío del paquete
	 * @param[in]  _cuotaex   La cuota extra que se cobrará por ser envío nocturno
	 */
	PaqueteNocturno(std::string _name1, std::string _address1, std::string _city1, std::string _state1, std::string _zipcode1, 
			std::string _name2, std::string _address2, std::string _city2, std::string _state2, std::string _zipcode2, 
			double _peso, double _costo, double _cuotaex);

	/**
	 * @brief      Destruye el objeto
	 */
	~PaqueteNocturno();

	/**
	 * @brief      { Sobreescribe el método CalcularCosto para agregar la cuota extra }
	 *
	 * @return     { El resultado de efectuar la operación (costo_por_kilo + cuotaex) * peso }
	 */
	double CalcularCosto() override;
};

PaqueteNocturno::PaqueteNocturno(std::string _name1, std::string _address1, std::string _city1, std::string _state1, std::string _zipcode1, 
			std::string _name2, std::string _address2, std::string _city2, std::string _state2, std::string _zipcode2, 
			double _peso, double _costo, double _cuotaex) :
			Paquete { _name1, _address1, _city1, _state1,  _zipcode1, 
			 _name2, _address2,  _city2, _state2, _zipcode2, 
			 _peso, _costo}, cuotaex {_cuotaex}
{
	//nada
}

PaqueteNocturno::~PaqueteNocturno()
{
	//nada
}

double PaqueteNocturno::CalcularCosto()
{
	return ((this->cuotaex + GetCostoKilo())*GetPeso());
}

/**
 * @brief      { Crea las etiquetas que tendrá el paquete, se usa el polimorfismo }
 *
 * @param[in]  p     { apuntador de tipo paquete }
 */
void Etiqueta (const Paquete * p)
{
	std::cout<<"REMITENTE\n "<<(p->GetEmisor()).GetName()<<std::endl;
	std::cout<<"    "<<(p->GetEmisor()).GetAddress()<<std::endl;
	std::cout<<"	"<<(p->GetEmisor()).GetCity()<<std::endl;
	std::cout<<"	"<<(p->GetEmisor()).GetState()<<std::endl;
	std::cout<<"	"<<(p->GetEmisor()).GetZipcode()<<std::endl;

	std::cout<<"DESTINATARIO\n "<<(p->GetReceptor()).GetName()<<std::endl;
	std::cout<<"    "<<(p->GetReceptor()).GetAddress()<<std::endl;
	std::cout<<"	"<<(p->GetReceptor()).GetCity()<<std::endl;
	std::cout<<"	"<<(p->GetReceptor()).GetState()<<std::endl;
	std::cout<<"	"<<(p->GetReceptor()).GetZipcode()<<std::endl;



}

int main ()
{
	double total;
	Paquete paquete("Alf", "Prof. Miguel Serrano 20", "Benito Juárez", "CDMX", "03100", "Eluviera Aniv", "Bustamante 20 Ejido del centro", "Tocumbo", "Michoacán", "81021", 2.3, 15.0);
	PaqueteDosDias paquetedosdias ("Minami Nitta", "Toranomon Shiroyoma 222", "Tokyo", "Honshu", "105-6024", "Claude Van-Damme", "Leduc Street 473", "Vankleek Hill", "Ontario", "K0B 1R0", 4.7, 20.0, 14.0);
	PaqueteNocturno paquetenocturno ("Anthony Brower", "Newport Road 89", "Carmacoup", "Lanark", "ML11 7NL","Candy White", "Maidstore Road 12", "Wentworth Castle", "Barnsley" ,"S75 8JA", 3.1, 25.0, 7.0);

	std::vector <Paquete *> vk;
	vk.push_back(&paquetedosdias);
	vk.push_back(&paquetenocturno);
	for (auto x: vk)
	{
		Etiqueta(x);
		total += x->CalcularCosto();
	}
	std::cout<<"El costo total de los envios es de: $"<<total<<std::endl;
}

