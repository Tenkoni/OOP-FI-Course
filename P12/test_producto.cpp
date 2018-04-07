
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
	void SetPrecio (double _precio);

	double Calcular () const;
	// devuelve cantidad * precio

private:
	int cantidad {0};
	double precio {0.0};
};

//     === ESCRIBA LA IMPLEMENTACIÓN DE LA CLASE ===

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
	public Cliente,						// ¿herencia o implementación?
	public Producto,					// ¿herencia o implementación?
	public HTMLable						// ¿herencia o implementación?
{
public:
	ReporteWEB () = default;

	ReporteWEB (std::string _nombre, int _cantidad, double _precio, std::string _archivo);
	// entre otras cosas, abre el archivo
	
	~ReporteWEB ();
	// cierra el archivo


	// escriba los setters para: nombre, cantidad, precio, archivo
	
	bool Guardar ();					// ¿const o no const?
	// guarda en archivo el documento generado
		

private:
	std::string nombreArchivo {"prueba.html"};
	// es el nombre del archivo que vamos a generar

	std::ofstream salida;
	// es nuestro handler del archivo

	std::string pagina;
	// aquí guardaremos la página completa (osea, lo que nos 
};

//     === ESCRIBA LA IMPLEMENTACIÓN DE LA CLASE ===


/*-------------------------------------------------------------------
 *  Driver program
 *-----------------------------------------------------------------*/
int main(void)
{

	// crea una instancia de ReporteWEB usando al constructor sin argumentos
	
	
	// genera la página web. Ábrala en su navegador

	
	return 0;
}
