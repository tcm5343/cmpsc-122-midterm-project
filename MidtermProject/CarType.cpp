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

#define INPUT_FILE "autodata.txt"
#define OUTPUT_FILE "output.txt"

CarType::CarType() {
}

void CarType::initialize() {
    readFromCSV();
}

void CarType::print() {

    // print out to console and output file
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

void CarType::readFromCSV() {
    // variable declarations
    std::ifstream inputFile;
    std::string str;

    // reads each line of the inputFile and adds it to the vector
    inputFile.open(INPUT_FILE);
    while (std::getline(inputFile, str)) {

        std::cout << str.substr(0, str.find(",")) << std::endl;
        while (!str.empty() && str.find(",") != -1) {
            str = str.substr(str.find(",") + 1, str.length()); // shortens the str
            std::cout << str.substr(0, str.find(",")) << std::endl;
        }
    }
    inputFile.close();
}
