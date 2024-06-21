
//==============================================================================
//
//  menu.cpp
//
//==============================================================================
//  guillaume plante <guillaume.plante@luminator.com>
//==============================================================================



#include "stdafx.h"
#include "log.h"
#include "cm.h"
#include "menu.h"
#include <iostream>

// Display the main menu
void ConsoleMenu::displayMainMenu() {
    setCursorPosition(0, 0);
    COUTC("===============================================");
    COUTC("               TEST APPLICATION                ");
    COUTC("===============================================");
    std::cout << std::endl;
    COUTY("   MAIN MENU");
    std::cout << std::endl;
    std::cout << "1. Codemeter Tests" << std::endl;
    std::cout << "2. Codemeter Initialize" << std::endl;
    std::cout << "3. Codemeter Uninitialize" << std::endl;
    std::cout << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << std::endl;
    if (lastWasInvalid) {
        COUTMM("Error: Invalid Option Selected");
    }
    std::cout << std::endl;
    COUTCSNR("Enter your choice: ");
}

// Display the sub-menu
void ConsoleMenu::displaySubMenu() {
    clearScreen();
    setCursorPosition(0, 0);
    
    COUTC("===============================================");
    COUTC("               TEST APPLICATION                ");
    COUTC("===============================================");
    std::cout << std::endl;

    COUTY("   MAIN MENU --> Codemeter Tests");

    std::cout << std::endl;

    std::cout << "1. Run Test 1" << std::endl;
    std::cout << "2. Run Test 2" << std::endl;
    std::cout << "3. Run Test 3" << std::endl;
    std::cout << std::endl;
    std::cout << "0. Back to Main Menu" << std::endl;
    std::cout << std::endl;
    if (lastWasInvalid) {
        COUTMM("Error: Invalid Option Selected");
    }
    std::cout << std::endl;
    COUTCSNR("Enter your choice: ");
}

// Main menu option functions
void ConsoleMenu::mainMenuOption1() {
    int choice;
    while (true) {
        std::cin >> choice;
        handleSubMenuInput(choice);

        // Exit to main menu if user selects option 4
        if (choice == 4) {
            clearScreen();
            break;
        }
    }
}

void ConsoleMenu::mainMenuOption2() {
    std::cout << "Codemeter Initialize" << std::endl;
    
    CodemeterClient::getInstance().Initialize();
}

void ConsoleMenu::mainMenuOption3() {
    std::cout << "Codemeter Uninitialize" << std::endl;

    CodemeterClient::getInstance().Destroy();
}

// Sub-menu option functions
void ConsoleMenu::subMenuOption1() {
    std::cout << "Test 1 selected." << std::endl;
    // Add functionality for Sub-Option 1 here
}

void ConsoleMenu::subMenuOption2() {
    std::cout << "Test 2 selected." << std::endl;
    // Add functionality for Sub-Option 2 here
}

void ConsoleMenu::subMenuOption3() {
    std::cout << "Test 3 selected." << std::endl;
    // Add functionality for Sub-Option 3 here
}

// Handle main menu input
void ConsoleMenu::handleMainMenuInput(int choice) {
    lastWasInvalid = false;
    switch (choice) {
        case 1:
            mainMenuOption1();
            break;
        case 2:
            mainMenuOption2();
            break;
        case 3:
            mainMenuOption3();
            break;
        case 0:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            COUTMM("Invalid choice. Please try again.");
            lastWasInvalid = true;
            break;
    }
}

// Handle sub-menu input
void ConsoleMenu::handleSubMenuInput(int choice) {
    lastWasInvalid = false;
    switch (choice) {
        case 1:
            subMenuOption1();
            break;
        case 2:
            subMenuOption2();
            break;
        case 3:
            subMenuOption3();
            break;
        case 0:
            std::cout << "Returning to main menu." << std::endl;
            break;
        default:
            COUTMM("Invalid choice. Please try again.");
            lastWasInvalid = true;
            break;
    }
}

// Run the program
void ConsoleMenu::run() {
    int choice;
    clearScreen();
    while (true) {
        displayMainMenu();
        std::cin >> choice;
        if (choice == 0) {
            break;
        }
        handleMainMenuInput(choice);
    }
}


void ConsoleMenu::clearScreen() {
    // Use system call to clear the console screen
    system("cls");
}

void ConsoleMenu::setCursorPosition(int x, int y) {
    // Set cursor position in console
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}