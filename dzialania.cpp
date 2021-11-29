//
//  dzialania.cpp
//  kalkulator
//
//  Created by Kasia on 23/11/2021.
//

#include "dzialania.hpp"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void kalkulator::podmien(double a){
    X = a;
    wynik = X;
}

void kalkulator::wyswietl(){
    cout << "\t-> " << wynik << endl;
}

void kalkulator::dodaj(double a){
    X = a;
    wynik += X;
}

void kalkulator::pierwiastek(){
    wynik = sqrt(wynik);
}

void kalkulator::odejmnij(double a){
    X = a;
    wynik -=  X;
}
void kalkulator::pomnoz(double a){
    X = a;
    wynik *= X;
}
void kalkulator::podziel(double a){
    X = a;
    wynik /= X;
}
void kalkulator::modulo(double a){
    X = a;
    wynik = fmod(wynik, X);
}
void kalkulator::C(){
    wynik = 0;
}
