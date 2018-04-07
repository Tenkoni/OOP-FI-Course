#include "listserializable.hpp"

int main ()
{
	int op;
	ListSerializable lista;
	do{
	std::cout<<"*********************************\n"
			 <<"*    Lista Serializable v1.0    *\n"
			 <<"*        Menú Principal         *\n"
			 <<"*                               *\n"
			 <<"*     Seleccione una opción:    *\n"
			 <<"*                               *\n"
			 <<"*      1) Insertar Persona      *\n"
			 <<"*      2) Borrar la lista       *\n"
			 <<"*        3) Serializar          *\n"
			 <<"*       4) Deserializar         *\n"
			 <<"*           5) Salir            *\n"
			 <<"*********************************\n"<<std::endl;
	std::cout<< "Opción a elegir: " ;
	std::cin>>op;

	switch ( op )
	{
		case 1 :
			{
			std::string tempo;
			int tempi;
			std::cout<<"\nIngresa el nombre: ";
			std::cin>>tempo;
			std::cout<<"\nIngresa la edad: ";
			std::cin>>tempi;
			Persona temp(tempo, tempi);
			lista.Insertar_Final(temp);
			break;
			}

		case 2 :
			{
			try{
			lista.Clear();
			}
			catch (std::range_error &e){
				std::cout <<e.what()<<std::endl;
			}
			break;
			}	

		case 3 :
			{
			try{
			lista.Abrir("serial.txt", Mode::Escritura);
			lista.Escribir();
			}
			catch (std::logic_error &e){
				std::cout <<e.what()<<std::endl;
			}
			catch (std::range_error &e){
				std::cout <<e.what()<<std::endl;
			}
			break;	
			}

		case 4 :
			{
			try{
			lista.Abrir("serial.txt", Mode::Lectura);
			lista.Leer();
			}
			catch (std::logic_error &e){
				std::cout <<e.what()<<std::endl;
			}
			break;	
			}

		case 5 :
			{
			std::cout<<"\nAdiós"<<std::endl;
			break;	
			}
			
		default :
			{	
			std::cout<< "Entrada inválida, intenta otra vez" <<std::endl;
			break;	
			}

	}

	}while (op != 5);
}
