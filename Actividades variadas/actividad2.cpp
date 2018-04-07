
/** @file test_producto.cpp
 *  @brief Genera una página web simple
 *
 *  @author eda1.fiunam (eda1.fiunam), eda1.fiunam at yahoo dot com dot mx
 *  @date 09/11/16 -- 19:45:18 
 */

#include <iostream>
#include <fstream>
#include <string>


/*-------------------------------------------------------------------
 *  Clase Producto
 *-----------------------------------------------------------------*/
class Producto
{
public:
	Producto ();

	void SetCantidad (int _cant);
	int GetCantidad () const;
	void SetPrecio (double _precio);
	double GetPrecio () const;

	double Calcular () const;
	// devuelve cantidad * precio

private:
	int cantidad {0};
	double precio {0.0};
};

//     === ESCRIBA LA IMPLEMENTACIÓN DE LA CLASE ===
Producto::Producto () 
{
	//nada
}

void Producto::SetCantidad(int _cant)
{
	this->cantidad = _cant;
}

int Producto::GetCantidad() const
{
	return (this->cantidad);
}

void Producto::SetPrecio(double _precio)
{
	this->precio = _precio;
}

double Producto::GetPrecio() const
{
	return (this->precio);
}

double Producto::Calcular() const
{
	return (this->cantidad * this->precio);
}

/*-------------------------------------------------------------------
 *  Clase Cliente
 *-----------------------------------------------------------------*/
class Cliente
{
public:
	Cliente ();

	void SetNombre (const std::string _nombre);
	std::string GetNombre () const;

private:
	std::string nombre {"NA"};
};

//     === ESCRIBA LA IMPLEMENTACIÓN DE LA CLASE ===

Cliente::Cliente ()
{
	//nada
}

void Cliente::SetNombre (const std::string _nombre)
{
	this->nombre = _nombre;
}

std::string Cliente::GetNombre () const 
{
	return (this->nombre);
}

/*-------------------------------------------------------------------
 *  Interfaz HTMLable
 *-----------------------------------------------------------------*/
class HTMLable
{
public:
	virtual void SetTitulo (std::string _titulo) = 0;
	virtual void SetEncabezado (std::string _encabezado) = 0;
	virtual void SetCuerpo (std::string _cuerpo) = 0;

	virtual std::string Generar () = 0;
	// va a generar la página completa con los datos que y tiene
};


/*-------------------------------------------------------------------
 *  Clase ReporteWEB
 *-----------------------------------------------------------------*/
class ReporteWEB :					// ¿hereda, implementa, ninguna, ambas?
	public Cliente,						// ¿herencia o implementación? Hereda
	public Producto,					// ¿herencia o implementación? Hereda
	public HTMLable						// ¿herencia o implementación? Implemente
{
public:
	ReporteWEB () = default;

	ReporteWEB (std::string _nombre, int _cantidad, double _precio, std::string _archivo);
	// entre otras cosas, abre el archivo
	
	~ReporteWEB ();
	// cierra el archivo

	virtual void SetTitulo (std::string _titulo) override;
	virtual void SetEncabezado (std::string _encabezado) override;
	virtual void SetCuerpo (std::string _cuerpo) override;
	virtual std::string Generar () override;
	// escriba los setters para: nombre, cantidad, precio, archivo
	
	void SetArchivo(const std::string _archivo);
	
	bool Guardar ();					// ¿const o no const?
	// guarda en archivo el documento generado
		

private:
	std::string nombreArchivo {"prueba.html"};
	// es el nombre del archivo que vamos a generar

	std::ofstream salida;
	// es nuestro handler del archivo

	std::string pagina;
	// aquí guardaremos la página completa (o sea, lo que nos 
	
	std::string titulo;
	std::string encabezado;
	std::string cuerpo;
};

//     === ESCRIBA LA IMPLEMENTACIÓN DE LA CLASE ===

ReporteWEB::ReporteWEB(std::string _nombre, int _cantidad, double _precio, std::string _archivo) 
{
	SetNombre(_nombre);
	SetCantidad(_cantidad);
	SetPrecio (_precio);
	SetArchivo (_archivo);
	this-> salida.open(_archivo);
	if (!salida)
	{
		std::cout << "Error abriendo el archivo para escritura" << std::endl;
		exit (EXIT_FAILURE);
	}

}

ReporteWEB::~ReporteWEB()
{
	this-> salida.close ();
}

void ReporteWEB::SetArchivo(const std::string _archivo)
{
	this->nombreArchivo = _archivo;
}

void ReporteWEB::SetTitulo (std::string _titulo)
{
	this->titulo = _titulo;
}

void ReporteWEB::SetEncabezado (std::string _encabezado) 
{
	this->encabezado = _encabezado;
}

void ReporteWEB::SetCuerpo (std::string _cuerpo) 
{
	this->cuerpo = _cuerpo;
}

std::string ReporteWEB::Generar() 
{
	this->pagina = "<HTML>";
	this->pagina +="	<HEAD>";
	this->pagina +="		<TITLE>"+this->titulo+"</TITLE>";
	this->pagina +="	</HEAD>";
	this->pagina +="	<BODY>";
	this->pagina +="		<H1 align=\"center\">" + this->encabezado + "</H1>";
	this->pagina +="		<HR>";
	this->pagina +="		<P>Cliente: "+GetNombre()+"</P>";
	this->pagina +="		<P>PRECIO: "+std::to_string (GetPrecio())+"</P>";
	this->pagina +="		<P>CANTIDAD: "+std::to_string (GetCantidad())+ "</P>";
	this->pagina +="		<P>TOTAL: "+std::to_string (Calcular())+"</P>";
	this->pagina +="	</BODY>";
	this->pagina +="</HTML>";
	return this->pagina;
}

bool ReporteWEB::Guardar ()
{
	if (!this->salida)
	{
		return false;
	}
	else
	{
		this->salida<<this->pagina<<std::endl;
		return true;
	} 
}
/*-------------------------------------------------------------------
 *  Driver program
 *-----------------------------------------------------------------*/
int main(void)
{

	ReporteWEB reporte {"Nvidia", 6500, 1450.5, "pagina.html" };
	reporte.SetTitulo("Informe de ventas");
	reporte.SetEncabezado("Silicon Wafer");
	reporte.Generar();
	if (!reporte.Guardar())
		std::cout<<"Ocurrió un error al guardar la página"<<std::endl;
	else
		std::cout<<"Página creada exitosamente"<<std::endl;

	
	return 0;
}
