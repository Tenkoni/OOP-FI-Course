#include <iostream>
#include "Automovil.hpp"

int main ()
{
	int op;
	lems::Automovil coche;
	do{
	std::cout<<"*********************************\n"
			 <<"*        Automovil v1.0         *\n"
			 <<"*        Menú Principal         *\n"
			 <<"*                               *\n"
			 <<"*     Seleccione una opción:    *\n"
			 <<"*                               *\n"
			 <<"*         1) Arrancar           *\n"
			 <<"*         2) Parar              *\n"
			 <<"*         3) Acelerar           *\n"
			 <<"*         4) Desacelerar        *\n"
			 <<"*   5) Intermitente izquierda   *\n"
			 <<"*   6) Intermitente derecha     *\n"
			 <<"*   7) Apagar intermitente      *\n"
			 <<"*    8) Girar a la izquierda    *\n"
			 <<"*     9) Girar a la derecha     *\n"
			 <<"*         10) Ir recto          *\n"
			 <<"*     11) Tipo de automóvil     *\n"
			 <<"*     12) Velocidad máxima      *\n"
			 <<"*       13) Estado actual       *\n"
			 <<"*          14) Salir            *\n"
			 <<"*********************************\n"<<std::endl;
	std::cout<< "Opción a elegir: " ;
	std::cin>>op;

	switch ( op )
	{
		case 1 :
			coche.Arrancar();
			coche.InternalState();
			break;	

		case 2 :
			coche.Parar();
			coche.InternalState();
			break;	

		case 3 :
			coche.Acelerar();
			coche.InternalState();
			break;	

		case 4 :
			coche.Desacelerar();
			coche.InternalState();
			break;	

		case 5 :
			coche.ModoIntermitentes(lems::Intermitentes::izquierda);
			coche.InternalState();
			break;	

		case 6 :
			coche.ModoIntermitentes(lems::Intermitentes::derecha);
			coche.InternalState();
			break;	

		case 7 :
			coche.ModoIntermitentes(lems::Intermitentes::apagadas);
			coche.InternalState();
			break;	

		case 8 :
			coche.Girar(lems::Direccion::izquierda);
			coche.InternalState();
			break;	

		case 9 :
			coche.Girar(lems::Direccion::derecha);
			coche.InternalState();
			break;	

		case 10 : 
			coche.Girar(lems::Direccion::centro);
			coche.InternalState();
			break;	
		
		case 11 :
			std::cout<< "El vehículo es de tipo "<< coche.TranslTipo() <<std::endl;
			break;	
			
		case 12 :
			std::cout<< "La velocidad máxima es de "<<coche.GetVelMaxima()<<std::endl;
			break;
				
		case 13 :
			coche.InternalState();
			break;	

		case 14 :
			std::cout<< "Saliendo" <<std::endl;
			break;
			
		default :
			std::cout<< "Entrada inválida, intenta otra vez" <<std::endl;
			break;	

	}

	}while (op != 14);

}
