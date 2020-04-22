/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CarType.cpp
 * Author: miller
 * 
 * Created on April 20, 2020, 5:28 PM
 */

#include <string>
#include "CarType.h"

CarType::CarType() {
}

std::string CarType::toString() {
    std::string result = this->name;
    for (std::vector<std::string>::iterator i = this->attributes.begin(); i != this->attributes.end(); ++i) {
        result.append(" " + *i);
    }
    return result;
}
