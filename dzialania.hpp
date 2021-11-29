//
//  dzialania.hpp
//  kalkulator
//
//  Created by Kasia on 23/11/2021.
//

#ifndef dzialania_hpp
#define dzialania_hpp

#pragma once
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string>
 
class kalkulator{
public:
    
    double X;
    double M = 0.0;
    double wynik = 0;
    
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
    void pierwiastek();
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

};

#endif /* dzialania_hpp */
