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
    
    /**
     * Returns the name of the car and all of its attributes on one line, 
     * primarily used for testing
     * @return 
     */
    std::string toString();
    
    /**
     * Writes a car to the input file with the correct CSV formatting
     */
    void addToFile();
    
    /**
     * prints the car to the console formatted
     */
    void print();
    
    /**
     * checks if the car has a specific feature
     * @param feature
     * @return - bool if it exists
     */
    bool hasFeature(std::string feature);

    bool operator<(const CarType& d) {
        if (name < d.name) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator>(const CarType& d) {
        if (name > d.name) {
            return true;
        }
        else {
            return false;
        }
    }
    
    // pretty sure this is not needed but just for my own sanity
    CarType operator=(const CarType c) {
        name = c.name;
        attributes = c.attributes;
        return *this;
    }

private:

};

#endif /* CARTYPE_H */

