#ifndef PILA_HPP
#define PILA_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cctype> 

class Pila 
{
private:
	std::vector<char> core;
public:
	Pila() = default;
	bool isEmpty();
	void Push (char c);
	char Pop();
	char Peek ();
	void Clear ();
};
	

#endif // PILA_HPP
