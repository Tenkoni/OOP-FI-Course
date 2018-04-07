#include <future> 
#include <thread> 
#include <chrono> 
#include <random> 
#include <iostream> 

std::vector<int> buffer;
volatile bool isReady {false};

void Leer ()
{
    isReady = false;
    for (auto i {0}; i<5; i++)
    {
        std::cout<<"\nIngresndo el número "<< i <<std::endl;
        buffer.push_back(i);
    }
    isReady = true;
    while(!isReady);
}

void Imprimir ()
{
    while (true){
        while (!isReady);
        std::cout<<"Buffer:"<<std::endl;
        for (auto x : buffer)
            std::cout<<"Eliminando "<<x<<std::endl;
        isReady=false;
    }
}

int main ()
{
	std::future<void> productor {std::async (Leer)};
	std::future<void> consumidor {std::async (Imprimir)};
	
    std::cout << "\nIniciando el llenado de buffer" << std::endl;
    productor.get();
    
    std::cout << "\nIniciando el vaciado del buffer" << std::endl;
	consumidor.get();
    

}
