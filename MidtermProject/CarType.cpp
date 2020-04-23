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
#include <iomanip>

#include "CarType.h"

CarType::CarType() {
}

void CarType::print() {

    // print out to console
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Attributes: ";
    if (attributes.size() > 0) { // if there are attributes
        std::cout << std::setw(40 - 12) << std::left << attributes[0] << std::endl;

        for (std::vector<std::string>::iterator i = this->attributes.begin() + 1; i != this->attributes.end(); ++i) {
            // I apologize about the block of spaces
            std::cout << "            " << *i << std::endl;
        }
    } else { // if there are attributes
        std::cout << "None" << std::endl;
    }
}

std::string CarType::toString() {
    std::string result = this->name;
    for (std::vector<std::string>::iterator i = this->attributes.begin(); i != this->attributes.end(); ++i) {
        result.append(" " + *i);
    }
    return result;
}

void CarType::addToFile() {

    // std::string outFileName = INPUT_FILE;
    std::ofstream outFile;
    outFile.open(INPUT_FILE, std::ios::app);

    // appends to input file
    outFile << this->name;
    if (attributes.size() > 0) { // if there are attributes
        for (std::vector<std::string>::iterator i = this->attributes.begin(); i != this->attributes.end(); ++i) {
            // I apologize about the block of spaces
            outFile << "," << *i;
        }

    } else { // if there are attributes
        outFile << "None" << std::endl;
    }
    outFile << std::endl;

    outFile.close();
}