#include "Pila.hpp"

/**
 * @brief      Función para establecer la jerarquía de operadores
 *
 * @param[in]  a     El operador a analizar
 *
 * @return     Regresa 0,1,2 y 3 dependiendo del operador ingresado, siendo 0 el de menor
 * 				jerarquía y 3 el de mayor, correspondiente a - y * respéctivamente.
 * 				En caso de error regresará -1
 */
int jerarquia (char a)
{
	if (a == '-') return 0;
	if (a == '+') return 1;
	if (a == '/') return 2;
	if (a == '*') return 3;
	return -1;
}

int main ()
{
	Pila stack;
	std::string input, output;
	input = "4+18/(9-3)";
	std::cout<<"La expresión infija es: "<<input<<std::endl;
	while (!input.empty())
	{
		if (isdigit(input.front()))
			{
				output.push_back(input.front());
				input.erase(input.begin());

			}

		else if (input.front()=='(')
		{
			stack.Push(input.front());
			input.erase(input.begin());
		}

		else if (input.front()==')')
		{
			while (stack.Peek() != '(')
			{
				output.push_back (stack.Pop());
			}
			stack.Pop();
		input.erase(input.begin());
		}

		else 
			{
				while (jerarquia(stack.Peek())>jerarquia(input.front()) && !stack.isEmpty())
				{
					input.push_back(stack.Pop());

				}
				stack.Push(input.front());
				input.erase(input.begin());
			}
	}

	while (!stack.isEmpty())
	{
		
		output.push_back(stack.Pop());
	}

	std::cout<<"\nLa expresión postfija es: "<<output<<std::endl;
	
	return 1;
}
