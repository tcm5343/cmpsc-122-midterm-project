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
#include <iostream>
#include <fstream>
#include <string>

#ifndef CARTYPE_H
#define CARTYPE_H

#define INPUT_FILE "autodata.txt"

class CarType {
public:
    CarType();
    std::string name;
    std::vector<std::string> attributes;
    std::string toString();
    void addToFile();
    void print();
    bool hasFeature(std::string feature);

    bool operator<(const CarType& d) {
        if (name < d.name) {
            return true;
        }
        if (name == d.name) {
            return false;
        }
        return false;
    }

    bool operator>(const CarType& d) {
        if (name > d.name) {
            return true;
        }
        if (name == d.name) {
            return false;
        }
        return false;
    }

private:

};

#endif /* CARTYPE_H */

