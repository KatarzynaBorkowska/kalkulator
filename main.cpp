/*
 Wykorzystując technikę dziedziczenia i wirtualizacji, połącz istniejące - utworzone do tej pory klasy kalkulatorów tak, aby obsługa operacji na nich dotyczyła typu podstawowego, a dokładna mechanika powinna być zaimplementowana w typach pochodnych.
 Np. metoda "oblicz" powinna być odpowiednio zaimplementowana według typu.
 Staraj unikać się duplikacji kodu.

 Umożliw wybór typu działania kalkulatora według preferencji użytkownika w menu programu.
 */

#include "naukowy.hpp"
#include "z_M.hpp"
#include "zwykly.hpp"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    kalkulator_Z Z;
    kalkulator_M M;
    kalkulator_N N;
    string s = "";
    int odp = 1;
    
    while (odp != 4) {
        cout << "Wybierz obcję: \n"
            << "1) kalkulator zwykly\n"
            << "2) kalkulator z M\n"
            << "3) kalukulator naukowy\n"
            << "4) koniec\n";
        
        cin >> odp;
        switch (odp) {
            case 1:
                // zwykły
                Z.wprowadz();
                break;
            case 2:
                // zwykły z M
                M.wprowadz();
                break;
            case 3:
                // naukowy
                N.wprowadz();
                break;
                
            default:
                break;
        }
    }
    return 0;
}

