/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CarType.h
 * Author: miller
 *
 * Created on April 20, 2020, 5:28 PM
 */

#include <string>
#include <vector>

#ifndef CARTYPE_H
#define CARTYPE_H

class CarType {
public:
    CarType();
    std::string name;
    std::vector<std::string> attributes;
    std::string toString();

    bool operator<(const CarType& d) {
        if (name < d.name) {
            return true;
        }
        if (name == d.name) {
            return true;
        }
        return false;
    }

    bool operator>(const CarType& d) {
        if (name > d.name) {
            return true;
        }
        if (name == d.name) {
            return true;
        }
        return false;
    }

private:

};

#endif /* CARTYPE_H */

