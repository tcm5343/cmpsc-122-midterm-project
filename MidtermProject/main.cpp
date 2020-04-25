/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: miller
 *
 * Created on April 20, 2020, 1:00 PM
 */

#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <cctype>

#include "CarType.h"
#include "TreeType.h"

/*
 * if PRINT_DEBUG value equals 1 then it will print the actions performed
 */
#define PRINT_DEBUG 0
#define OUTPUT_FILE "results.txt"

// function declaration
void displaySearchMenu(TreeType& searchTree);
int validateInput(std::map<std::string, int>& map, std::string input);
CarType addCarType();

int main() {

    // initialize variables
    TreeType tree;
    tree.initialize();
    
//    TreeType tree2;
//    CarType car;
//    car.name = "car";
//    tree2.PutItem(car);
//    tree2.DeleteItem(car);

    std::map<std::string, int> default_menu_map;
    default_menu_map["quit"] = 0;
    default_menu_map["search"] = 1;
    default_menu_map["add"] = 2;

    // display initial menu
    std::string input;
    int map_value = -1;
    while (map_value != 0) {
        std::cout << "Enter a command (commands are not case sensitive):" << std::endl;
        std::cout << "Add - add a new automobile" << std::endl;
        std::cout << "Search - put the program into search mode" << std::endl;
        std::cout << "Quit - terminate the program" << std::endl;

        std::getline(std::cin, input); // read in user input (map key)
        TreeType searchTree(tree); // tree which will be searched if need be

        // input validation: checks if the key exists in the map
        map_value = validateInput(default_menu_map, input);

        switch (map_value) {
                // terminate program
            case 0:
                break;

                // search
            case 1:
                std::cout << std::endl << "Search selected" << std::endl;

                displaySearchMenu(searchTree);
                break;

                // add
            case 2:
                tree.PutItem(addCarType());
                break;

            default:
                break;
        }
        std::cout << std::endl;
    }

    return 0;
} // main()

/**
 * User input is passed so that all the commands are not case sensitive. The
 * body of the function was taken from stackoverflow.
 * https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
 * @param string - passed by reference
 */
std::string toLowerCase(std::string& string) {
    std::transform(string.begin(), string.end(), string.begin(),
            [](unsigned char c) {
                return std::tolower(c); });
    return string;
} // toLowerCase()

/**
 * Checks that the key exists in the map and returns the corresponding value to
 * be used in a switch statement.
 * @param map - depends on which menu is being validated, passed by reference
 * @param input - input from the user (string)
 * @return 
 */
int validateInput(std::map<std::string, int>& map, std::string input) {
    int map_value;
    input = toLowerCase(input);
    // input validation: checks if the key exists in the map
    if (map.find(input) == map.end()) {
        // not found
        map_value = -1;
        std::cout << "Invalid Command" << std::endl;
    } else {
        // found
        std::map<std::string, int>::iterator i = map.find(input); // find command in map
        map_value = i->second; // assign the commands value to use in switch
    }
    return map_value;
} // validateInput()

/**
 * Displays the search menu, created a separate function for cleaner code.
 */
void displaySearchMenu(TreeType& searchTree) {

    std::map<std::string, int> search_menu_map;
    search_menu_map["exit"] = 0;
    search_menu_map["hasfeature"] = 1;
    search_menu_map["checkauto"] = 2;
    search_menu_map["show"] = 3;

    // initialize writing to file
    std::ofstream file;
    file.open(OUTPUT_FILE, std::ios::app);

    // find name of search from user
    std::cout << "Please enter the name of the search:" << std::endl;
    std::string nameOfSearch;
    std::getline(std::cin, nameOfSearch);
    // write name of search to file
    file << "Name of search: " << nameOfSearch << std::endl;

    std::string input;
    int map_value = -1;

    while (map_value != 0) {
        std::cout << std::endl << "Search mode: enter a command (commands are not case sensitive):" << std::endl;
        std::cout << "hasFeature - search by an attribute" << std::endl;
        std::cout << "checkAuto - print out the attributes about a car if it exists in your search list" << std::endl;
        std::cout << "Show - Shows the current list of automobiles that match all of the features you have listed as criteria thus far" << std::endl;
        std::cout << "Exit - exit search mode" << std::endl;
        std::getline(std::cin, input); // read in user input (map key)

        // input validation: checks if the key exists in the map
        map_value = validateInput(search_menu_map, input);
        std::string carName, feature;
        std::vector<CarType> featurlessCars;

        switch (map_value) {

            case 0: // terminate program
                break;

            case 1: // hasFeature
                std::cout << "Enter a feature: " << std::endl;
                std::getline(std::cin, feature);
                searchTree.hasFeature(feature, featurlessCars);
                for (std::vector<CarType>::iterator i = featurlessCars.begin(); i != featurlessCars.end(); ++i) {
                    searchTree.DeleteItem(*i);
                }
                break;

            case 2: // checkAuto
                std::cout << "Enter the name of the car: " << std::endl;
                std::getline(std::cin, carName);
                searchTree.checkAuto(carName);
                break;

            case 3: // Show
                searchTree.showCommand(file);
                break;

            default:
                break;
        }
    }

    file.close();
} // displaySearchMenu()

/**
 * I included this in main because it includes a menu and I thought it 
 * was better than in CarType..
 * @return 
 */
CarType addCarType() {
    CarType car;

    // car name
    std::string name;
    std::string attr = "";
    std::cout << std::endl << "Please enter the name of the car: " << std::endl;
    std::getline(std::cin, name);
    car.name = name;

    // car attributes
    std::cout << "_Please enter car attributes, one per line, when finished enter 'End': " << std::endl;
    while (attr != "end") {
        std::cout << "Enter an attribute: " << std::endl;
        std::getline(std::cin, attr);
        if (toLowerCase(attr) == "end") {
            break;
        } else {
            car.attributes.push_back(attr);
            toLowerCase(attr);
        }
    }

    //    std::cout << car.toString() << std::endl;
    car.addToFile();
    return car;
}

/*
 * Resources:
 * https://stackoverflow.com/questions/1939953/how-to-find-if-a-given-key-exists-in-a-c-stdmap
 * 
 */

