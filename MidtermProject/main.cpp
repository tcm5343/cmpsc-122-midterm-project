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

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>

/*
 * if PRINT_DEBUG value equals 1 then it will print the actions performed
 */
#define PRINT_DEBUG 0

// function declaration
void displayDefaultMenu();

int main() {
    
    displayDefaultMenu();
    return 0;
}

/**
 * User input is passed so that all the commands are not case sensitive. The
 * body of the function was taken from stackoverflow.
 * https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
 * @param string - passed by reference
 */
void toLowerCase(std::string& string) {
    std::transform(string.begin(), string.end(), string.begin(),
            [](unsigned char c) {
                return std::tolower(c); });
}

/**
 * Checks that the key exists in the map and returns the corresponding value to
 * be used in a switch statement.
 * @param map - depends on which menu is being validated, passed by reference
 * @param input - input from the user (string)
 * @return 
 */
int validateInput(std::map<std::string, int>& map, std::string input) {
    int map_value;
    toLowerCase(input);
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
}

/**
 * Displays the search menu, created a separate function for cleaner code.
 */
void displaySearchMenu() {
    std::map<std::string, int> search_menu_map;
    search_menu_map["exit"] = 0;
    search_menu_map["hasfeature"] = 1;
    search_menu_map["checkauto"] = 2;
    search_menu_map["show"] = 3;

    std::string input;
    int map_value = -1;

    while (map_value != 0) {
        std::cout << std::endl << "Search mode: enter a command (commands are not case sensitive)" << std::endl;
        std::cout << "hasFeature - search by an attribute" << std::endl;
        std::cout << "checkAuto - print out the attributes about a car if it exists in your search list" << std::endl;
        std::cout << "Show - Shows the current list of automobiles that match all of the features you have listed as criteria thus far" << std::endl;
        std::cout << "Exit - exit search mode" << std::endl;

        std::cin >> input; // read in user input (map key)

        // input validation: checks if the key exists in the map
        map_value = validateInput(search_menu_map, input);

        switch (map_value) {
                // terminate program
            case 0:
                break;

                // hasFeature
            case 1:
                std::cout << "hasFeature selected" << std::endl;
                break;

                // checkAuto
            case 2:
                std::cout << "checkAuto selected" << std::endl;
                break;

                // Show
            case 3:
                std::cout << "Show selected" << std::endl;
                break;

            default:
                break;
        }
        std::cout << std::endl;
    }

}

/**
 * Displays the starting (default) menu
 */
void displayDefaultMenu() {
    std::map<std::string, int> default_menu_map;
    default_menu_map["quit"] = 0;
    default_menu_map["search"] = 1;
    default_menu_map["add"] = 2;

    // display initial menu
    std::string input;
    int map_value = -1;
    while (map_value != 0) {
        std::cout << "Enter a command (commands are not case sensitive)" << std::endl;
        std::cout << "Add - add a new automobile (cannot be in search mode)" << std::endl;
        std::cout << "Search - put the program into search mode" << std::endl;
        std::cout << "Quit - terminate the program" << std::endl;

        std::cin >> input; // read in user input (map key)

        // input validation: checks if the key exists in the map
        map_value = validateInput(default_menu_map, input);

        switch (map_value) {
                // terminate program
            case 0:
                break;

                // search
            case 1:
                std::cout << "Search selected" << std::endl;
                displaySearchMenu();
                break;

                // add
            case 2:
                std::cout << "Add selected" << std::endl;
                break;

            default:
                break;
        }
        std::cout << std::endl;
    }
}

/*
 * Resources:
 * https://stackoverflow.com/questions/1939953/how-to-find-if-a-given-key-exists-in-a-c-stdmap
 * 
 */