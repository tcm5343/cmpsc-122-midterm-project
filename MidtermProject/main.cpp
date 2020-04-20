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

/*
 * if PRINT_DEBUG value equals 1 then it will print the actions performed
 */
#define PRINT_DEBUG 0

/*
 * 
 */
int main() {

    std::map<std::string, int> default_menu_map;
    default_menu_map["Quit"] = 0;
    default_menu_map["Search"] = 1;
    default_menu_map["Add"] = 2;

    //    std::cout << "Map size: " << map.size() << std::endl;

    //    // find the map at a specific key
    //    std::map<std::string, int>::iterator i = map.find("Add");
    //    std::cout << "Map index of Search: " << i->first << std::endl;

    //    // prints the map
    //    for (std::map<std::string, int>::iterator i = map.begin(); i != map.end(); i++) {
    //        std::cout << i->first << " " << i->second << std::endl;
    //    }
    //    

    // display initial menu
    std::string input;
    int map_value = -1;
    while (map_value != 0) {
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "Add - add a new automobile (cannot be in search mode)" << std::endl;
        std::cout << "Search - put the program into search mode" << std::endl;
        std::cout << "Quit - terminate the program" << std::endl;

        std::cin >> input; // read in user input (map key)

        // input validation: checks if the key exists in the map
        if (default_menu_map.find(input) == default_menu_map.end()) {
            // not found
            map_value = -1;
            std::cout << "Invalid Command" << std::endl;
        } else {
            // found
            std::map<std::string, int>::iterator i = default_menu_map.find(input); // find command in map
            map_value = i->second; // assign the commands value to use in switch
        }

        switch (map_value) {
                // terminate program
            case 0:
                break;

                // search
            case 1:
                std::cout << "Search selected" << std::endl;
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

    return 0;
}

/*
 * https://stackoverflow.com/questions/1939953/how-to-find-if-a-given-key-exists-in-a-c-stdmap
 * 
 */