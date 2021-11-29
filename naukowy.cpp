//
//  naukowy.cpp
//  kalkulator
//
//  Created by Kasia on 23/11/2021.
//

#include "naukowy.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
//using namespace N;
using namespace std;

void kalkulator_N::wprowadz(){
    string s = "";
    cout << "Jak chcesz zakonczyc podaj E\n";
    while(s != "E" && s != "e")
    {
        cin >> s;
        if(s != "E" && s != "e")
            cout << usuwanie_zer(dzialanie(s)) << endl << endl;
    }
}

string tab_dzialan[] = {"%","p","^","*","/","+","-"};
string tab_dzialan2[] = {"%p^","*/","+-"};

double kalkulator_N::to_double(string s)
{
    return stod(s);
}

std::string kalkulator_N::usuwanie_zer(std::string s){
    
    unsigned long n = s.length() - 1,i;
    
    for(i = n;i > 0;i--)
    
    {
        if(s[i] == '0')
            s.pop_back();
        else if(s[i] == '.')
        {
            s.pop_back();
            return s;
        }
        else
            return s;
    }
    return s;
}


string kalkulator_N::dzialanie(string s)
{
    bool t;
    int i;
    vector<string> v;
    double d;
    string pom = "";
    for(i = 0;i < s.size();i++)
    {
        if(isnumber(s[i]) || s[i] == '.')
            pom += s[i];
        else{
            if(pom.size() != 0){
                v.push_back(pom);}
            else if(!isnumber(s[i+1]) && s[i] == '-' && s[i+1] != '-'){
                v.pop_back();
                d = to_double(pom);
                d *= -1;
                v.push_back(to_string(d));
                continue;
                }
            
            if(s[i] == '-' && s[i+1] == '-')
            {
//                cout << " ------ ";
                pom = '-';
                i++;
            }
            else
                pom = s[i];
            v.push_back(pom);
            pom = "";
        }
    }
    v.push_back(pom);
    
    if(v.size() < 2 ){
        return s;
    }
    else if (v.size() == 2 && v[0] == "-"){
        return v[0] + v[1];
    }
    string p = s;
    s = "";
    bool znak = false;
    for(i = 0;i < 3;i++)
    {
        for(int n = 1;n < v.size();n++)
        {
            t = true;
            size_t  pozycja = v[n].find_first_of(tab_dzialan2[i]);
            if(pozycja == 0)
            {
                double x = to_double(v[n-1]), y = to_double(v[n+1]);
                if(n-2 == 0 && v[n-2] == "-"){
                    x *= -1;
                    znak = true;
                }
                if(v[n] == "+" || v[n] == "-"){
                if(v[n] == "+"){
                    podmien(y);
                    dodaj(x);
                    pom = to_string(zwraca());
                    }
                if(v[n] == "-"){
                    podmien(x);
                    odejmnij(y);
                    pom = to_string(zwraca());
                }}
                if(v[n] == "/"){
                    podmien(x);
                    podziel(y);
                    pom = to_string(zwraca());
                }
                if(v[n] == "*"){
                    podmien(x);
                    pomnoz(y);
                    pom = to_string(zwraca());
                }
                if(v[n] == "^"){
                    podmien(x);
                    potega(y);
                    pom = to_string(zwraca());
                }
                if(v[n] == "p"){
                    podmien(x);
                    potega(1/y);
                    pom = to_string(zwraca());
                }
                if(v[n] == "%")
                    pom = procent(v[n-1], v[n+1]);
                
                for(int j = 0;j < v.size();j++)
                {
                    if(znak == true && j == n-2)
                        j++;
                    else if(j != n && j != n-1 && j != n+1)
                        s += v[j];
                    
                    if(j == n)
                        s += pom;
                }
                znak = false;
                return dzialanie(s);
            }
        }
    }
    return "";
}
string kalkulator_N::procent(string a, string b){
    return to_string((to_double(b)/to_double(a)) * 100);
}

