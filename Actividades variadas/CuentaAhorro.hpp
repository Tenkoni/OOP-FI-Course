#ifndef CUENTAAHORRO_HPP
#define CUENTAAHORRO_HPP
#include<iostream>
#include "Cuenta.hpp"
class CuentaAhorro:public Cuenta
{
   public:
       CuentaAhorro()=default;
       CuentaAhorro(const CuentaAhorro & rhs);	
       CuentaAhorro(double _cantidad, double _interes);
       ~CuentaAhorro();
       double CalcularInteres(double saldoActual);
   private:
       double interes{0.0};
};
#endif 
