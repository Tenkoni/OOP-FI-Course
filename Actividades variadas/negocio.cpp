#include <iostream>
#include <string>
#include <vector>

/**
 * @brief      CLASE LOCAL
 */
class Local
{
private:
	std::vector <std::string> comentarios[2];
	std::string nombre{"NA"};
	std::string direccion{"NA"};
	int puntaje{0};
public:
	Local()= default;

	/**
	 * @brief      Constructor con argumentos (Principalmente para usarse en la
	 *             de-serialización)
	 *
	 * @param[in]  _nombre     nombre
	 * @param[in]  _direccion  direccion
	 * @param[in]  _puntaje    puntaje
	 */
	Local (std::string _nombre, std::string _direccion, int _puntaje);

	/**
	 * @brief      Permite insertar un comentario y una calificación del local
	 *
	 * @param[in]  _comentario  comentario
	 * @param[in]  _calif       calificación
	 */
	virtual void ComentarYCalificar (std::string _comentario, int _calif);

	/**
	 * @brief      Imprime los datos del local
	 */
	virtual void MostrarLocal ();
};

Local::Local (std::string _nombre, std::string _direccion, int _puntaje): nombre{_nombre}, direccion{_direccion}, puntaje{_puntaje}
{
	this->nombre = _nombre;
	this->direccion = direccion;
	if (_puntaje>=0 or _puntaje<=10)
	{
		this->puntaje=puntaje;
	}
	else
	{
		std::cout<<"Calificación invalida\n";
	}
}

void Local::ComentarYCalificar (std::string _comentario, int _calif)
{
	if (_calif>=0 or _calif<=10)
	{
		this->comentarios[0].push_back(_comentario);
		this->comentarios[1].push_back(std::to_string (_calif));
		this->puntaje=this->puntaje+_calif;
	}
	else
	{
		std::cout<<"Calificación invalida\n";
	}
}

void Local::MostrarLocal ()
{
	std::cout<<"Nombre del local: " + this->nombre;
	std::cout<<"\nDirección: " + this->direccion;
	std::cout<<"\nComentarios de clientes:\n";
	for (size_t i{0}; i<this->comentarios[1].size(); i++)
	{
		std::cout<<this->comentarios[0][i]<<std::endl;
		std::cout<<this->comentarios[1][i]<<std::endl;
	}
	std::cout<<"Puntaje "<<(this->puntaje / this->comentarios[1].size()) << std::endl;
}

/**
 * @brief      CLASE PRODUCTO
 */
class Producto
{
private:
	std::string nombre{"NA"};
	double precio{0.0};
public:

	/**
	 * @brief      Constructor con argumentos
	 *
	 * @param[in]  _nombre    nombre
	 * @param[in]  _precio    precio
	 */
	Producto (std::string _nombre, double _precio);

	/**
	 * @brief      Asigna el nombre
	 *
	 * @param[in]  _nombre  nombre
	 */
	void SetNombre(std::string _nombre);

	/**
	 * @brief      Asigna el precio
	 *
	 * @param[in]  _precio  precio
	 */
	void SetPrecio(double _precio);

	/**
	 * @brief      Obtiene el nombre
	 *
	 * @return     nombre
	 */
	std::string GetNombre();

	/**
	 * @brief      Obtiene el precio
	 *
	 * @return     precio
	 */
	double GetPrecio();
};

Producto::Producto (std::string _nombre, double _precio): nombre{_nombre}, precio{_precio}
{
	SetPrecio(_precio);
}

void Producto::SetNombre(std::string _nombre)
{
	this->nombre=_nombre;
}

void Producto::SetPrecio(double _precio)
{
	if (_precio>=0)
	{
		this->precio=_precio;
	}
	else
	{
		this->precio=0;
	}
}

std::string Producto::GetNombre()
{
	return this->nombre;
}

double Producto::GetPrecio()
{
	return this->precio;
}

/**
 * @brief      INTERFAZ PARA LAS COMPRAS EN LINEA
 */
class IComprasEnLinea
{
public:
	virtual double Cobrar()=0;
	virtual void ACarrito()=0;
	virtual void Llenar(Producto rhs)=0;
	virtual void MostrarInventario()=0;
};

/**
 * @brief      CLASE LOCALES CON COMPRAS EN LINEA
 */
class LocalLinea: 
			public IComprasEnLinea, 
			public Local
{
private:
	std::vector <Producto> inventario;
	double total{0.0};
	std::vector<Producto> compras;
	std::string articulo;
	
public:
	/**
	 * @brief      Calcula el monto a pagar
	 *
	 * @return     monto por cada compra
	 */
	virtual double Cobrar() override;  

	/**
	 * @brief      Agrega elementos a la compra
	 */
	virtual void ACarrito() override;

	/**
	 * @brief      Ingresa productos al local
	 *
	 * @param      rhs   objeto tipo producto (producto que se ingresará al
	 *                   local)
	 */
	virtual void Llenar(Producto rhs) override;   

	/**
	 * @brief      Muestra lo que puede comprar cada persona
	 */
	virtual void MostrarInventario() override;  
};

void LocalLinea::Llenar(Producto rhs)
{
	this->inventario.push_back (rhs);
}

void LocalLinea::MostrarInventario()
{
	for (size_t i{0}; i<this->inventario.size(); i++)
	{
		std::cout<<i+1<< ") " <<this->inventario[i].GetNombre()<< " ";
		std::cout<<this->inventario[i].GetPrecio()<<std::endl;
	}
}

void LocalLinea::ACarrito()
{
	for (size_t i{0}; i<this->inventario.size(); i++)
	{
		std::cout<<i+1<< ") " <<this->inventario[i].GetNombre()<< " ";
		std::cout<<this->inventario[i].GetPrecio()<<std::endl;
	}
	std::cout<<"Seleccione el articulo a comprar: \n";
	int n;
    std::cin>>n;
    this->total=this->total+this->inventario[n+1].GetPrecio();
}

double LocalLinea::Cobrar ()
{
	return this->total;
}

/**
 * 						DRIVER PROGRAM
 */
int main ()
{
	LocalLinea milocal;
	milocal.Llenar(Producto {"Jabon",12.50});
	milocal.Llenar(Producto {"Cereal",13.50});
	milocal.Llenar(Producto {"Galletas",16.50});
	milocal.Llenar(Producto {"Papel",150.50});
	//milocal.MostrarInventario();
	milocal.ACarrito ();
	milocal.ACarrito ();
	milocal.ACarrito ();
	milocal.ACarrito ();
	std::cout<<"Lo que debe de sus compras es: "<<milocal.Cobrar();
}
