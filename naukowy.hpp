//
//  naukowy.hpp
//  kalkulator
//
//  Created by Kasia on 23/11/2021.
//

#ifndef naukowy_hpp
#define naukowy_hpp

#include <stdio.h>
#include <string>
#pragma once
#include <ostream>
#include "z_M.hpp"

class kalkulator_N : kalkulator_M{
public:
    
    void wprowadz();
    std::string dzialanie(std::string);
    std::string usuwanie_zer(std::string);
    double to_double(std::string);
    std::string procent(std::string,std::string);
    virtual ~kalkulator_N() = default;
};

#endif /* naukowy_hpp */
