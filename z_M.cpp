//
//  z_M.cpp
//  kalkulator
//
//  Created by Kasia on 23/11/2021.
//

#include "z_M.hpp"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void kalkulator_M::wprowadz(){
    string z,last = "!";
    cout << "Podaj jeden ze znakow jaki chcesz wykonać w zadaniu. + - * / % (działanie modulo) „s” oznaczający pierwiastek 2-giego stopnia\nE - wyjscie z programu,\t C - wyzerowanie\tMC - wyzerowanie i zapisanie\t MR - wyswietla liczbe z pamieci\nJeżeli uznasz,że chcesz zmienic znak lub liczbe wcisnij d\nM+ dodaje liczbe z pamieci\tM- odejmije liczbe z pamieci itd.\n";
    wyswietl();
    do{
        cin >> z;
        
        if(isnumber(z[z.size()-1])){
            switch (last[0]) {
                case '+':
                    dodaj(stod(z));
                    break;
                case '-':
                    odejmnij(stod(z));
                    break;
                case '*':
                    pomnoz(stod(z));
                    break;
                case '/':
                    podziel(stod(z));
                    break;
                case '%':
                    modulo(stod(z));
                    break;
                case '!':
                    podmien(stod(z));
                    break;
                default:
                    break;
            }
            last = "!";
        }
        else if(z == "s")
            potega(0.5);
        else if(z == "C"){
            C();
            last = "!";
        }
        else if(z[0] == 'M'){
            switch (z[1]) {
                case 'C':
                    MC();
                    break;
                case 'R':
                    wyswietl_MR();
                    break;
                case '+':
                    Mplus();
                    break;
                case '-':
                    Mminus();
                    break;
                case '*':
                    Mpomnoz();
                    break;
                case '/':
                    Mpodziel();
                    break;
                case '%':
                    Mmodulo();
                    break;
                default:
                    break;
            }
        }
        else{
            last = z;
        }
        
        if(z != "E" && z != "e")
            wyswietl();
        else
            C();
        
    }while(z != "E" && z != "e");
}

double kalkulator_M::zwraca()
{
    return wynik_M;
}
/*
double kalkulator_M::zamiana(string s)
{
    
    return stod(s);
}

string kalkulator_M::ogarnij_znak(string s){
    
    string p;
    
    if(s.size() == 1)
        return s;
    if(s[s.size() - 2] == 'M'){
        p += s[s.size() - 2];
        p += s[s.size() - 1];}
    else
        p = s[s.size() - 1];
    return p;
    
}*/

void kalkulator_M::wyswietl(){
    cout << "\t-> " << wynik_M << endl;
}

void kalkulator_M::wyswietl_MR(){
    wynik_M = M;
}

void kalkulator_M::zapiszM()
{
    M = wynik_M;
}

double kalkulator_M::Mzwraca(){
    wynik_M = M;
    return wynik_M;
}

void kalkulator_M::podmien(double a){
    X = a;
    wynik_M = X;
}

void kalkulator_M::dodaj(double a){
    X = a;
    wynik_M += X;
}

void kalkulator_M::potega(double a){
    X = a;
    wynik_M = pow(wynik_M,X);
}

void kalkulator_M::odejmnij(double a){
    X = a;
    wynik_M -=  X;
}
void kalkulator_M::pomnoz(double a){
    X = a;
    wynik_M *= X;
}
void kalkulator_M::podziel(double a){
    X = a;
    wynik_M /= X;
}
void kalkulator_M::modulo(double a){
    X = a;
    wynik_M = fmod(wynik_M, X);
}

void kalkulator_M::C(){
    wynik_M = 0;
}

void kalkulator_M::MC(){
    M = wynik_M;
    wynik_M = 0;
}

void kalkulator_M::Mplus(){
    M += wynik_M;
}

void kalkulator_M::Mminus(){
    M -= wynik_M;
}

void kalkulator_M::Mpierwiastek(){
    M = sqrt(M);
}
void kalkulator_M::Mpomnoz(){
    M *= wynik_M;
}
void kalkulator_M::Mpodziel(){

    M /= wynik_M;
}
void kalkulator_M::Mmodulo(){
    M = fmod(M,wynik_M);
}
