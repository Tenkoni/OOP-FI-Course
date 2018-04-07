/*
 * Ejemplo tomado de [JOSUTTIS12, pp. 947]
 */

#include <future> 
// para usar los "futuros" (los valores devueltos por async())

#include <thread> 
// para usar los hilos

#include <chrono> 
// para usar las funciones del tiempo

#include <random> 
// para usar los números aleatorios

#include <iostream> 
// para usar cin y cout

#include <exception> 
// para usar excepciones


char doSomething (char c)
{
	std::default_random_engine dre {c};
	// inicializa al generador de números aleatorios
	
	std::uniform_int_distribution<int> id {10, 1000};
	// generará un valor uniformemente distribuido entre 10 y 1000
	
	for (auto i {0}; i < 10; ++i) {
		std::this_thread::sleep_for (std::chrono::milliseconds (id (dre)));
		// genera un retardo aleatorio
		
		std::cout.put (c).flush ();
		// imprime el carácter
	}

	return c;
}

int func1 ()
{
	return doSomething ('.');
}

int func2 ()
{
	return doSomething ('+');
}


/*-------------------------------------------------------------------
 *  Driver program
 *-----------------------------------------------------------------*/
int main(void)
{

	std::cout << "Arrancando func1() en el fondo"
		<< " y func2 () en primer plano: " << std::endl;

	std::future<int> result1 {std::async (func1)};

	int result2 = func2 ();

	int result = result1.get () + result2;

	std::cout << "\nEl resultado de func1() + func2() es: "
		<< result << std::endl;
	
	return 0;
}
