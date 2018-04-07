#include <iostream>
#include <vector>
#include <string>

class Stack
{
public:
  Stack (size_t depth);
  Stack (const Stack &r);
  void operator= (const Stack &sta);
  void Push (std::string str);
  std::string Pop ();
  std::string Peek ();
  bool IsEmpty ();
  bool IsFull ();
  void Clear ();

  size_t GetDepth ();
  size_t GetTop ();

private:
  size_t depth;
  std::vector <std::string> stack;
  size_t top {0};

};

Stack::Stack(size_t _depth) : depth {_depth}, stack {_depth}
{
}

Stack::Stack (const Stack &r)
{
  this-> depth  = r.depth;
  this-> top = r.top;
  this-> stack = r.stack;
}

size_t Stack::GetTop ()
{
  return this-> top;
}

size_t Stack::GetDepth ()
{
  return this-> depth;
}

bool Stack::IsEmpty ()
{
  return ((this-> top < 1) ? true : false ) ;
}

bool Stack::IsFull ()
{
  return ((this-> top == this-> depth) ? false : true);
}

void Stack::Push (std::string str)
{
  if (IsFull()){
    this-> stack.push_back (str);
    this-> top += 1;
  }
  else
    std::cout << "La pila está llena" << std::endl;
}

std::string Stack::Pop ()
{
  if (IsEmpty()){
    std::cout << "La pila está vacía" << std::endl;
    return "Error";
  }
  else{
    std::string temp;
    temp = this-> stack.back();
    stack.pop_back ();
    this-> top -= 1;
    return temp;
  }
}

std::string Stack::Peek ()
{
  if (IsEmpty()){
    std::cout << "La pila está vacía" << std::endl;
    return "Error";
  }
  else return (this-> stack.at(this-> top));
}

void Stack::Clear ()
{
  this-> stack.clear();
  this-> top = 0;
  this-> depth = 0;
}

int main ()
{
  Stack st {5};
  std::cout << "depth = " << st.GetDepth() << std::endl;
  std::cout << "top = " << st.GetTop() << std::endl;
  std::cout << "Comienza el llenado..." << std::endl;
  for (size_t i {0}; st.IsFull ()  ; ++i){
    std::string s;
    std::cout << "Ingrese una cadena de caracteres: " << std::endl;
    std::cin >> s;
    st.Push (s);
    std::cout << "top = " << st.GetTop() << std::endl;
  }
  std::cout << "Fin del llenado..." << std::endl;
  std::cout << "top = " << st.GetTop() << std::endl;
  std::cout << "Comienzo del vaciado..." << std::endl;
  while (st.IsEmpty() == false){
    std::cout << st.Pop() << std::endl;
    std::cout << "top = " << st.GetTop() << std::endl;
  }
}
