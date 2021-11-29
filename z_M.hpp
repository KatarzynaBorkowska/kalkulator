//
//  z_M.hpp
//  kalkulator
//
//  Created by Kasia on 23/11/2021.
//

#ifndef z_M_hpp
#define z_M_hpp

#pragma once
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string>
 
class kalkulator_M{
public:
    
    double X;
    double M = 0.0;
    double wynik_M = 0;
    
    void wprowadz();
    double zamiana(std::string);
    double zwraca();
    std::string ogarnij_znak(std::string);
    void wyswietl();
    void zapiszM();
    double Mzwraca();
    void podmien(double);
    void wyswietl_MR();
    void dodaj(double);
    void potega(double);
    void odejmnij(double);
    void pomnoz(double);
    void podziel(double);
    void modulo(double);
    void C();
    void MC();
    void Mplus();
    void Mminus();
    void Mpierwiastek();
    void Modejmnij();
    void Mpomnoz();
    void Mpodziel();
    void Mmodulo();
    
    virtual ~kalkulator_M() = default;

};

#endif /* z_M_hpp */
