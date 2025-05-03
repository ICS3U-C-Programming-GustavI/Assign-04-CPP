// Copyright (c) 2025 Gustav I
// Created by: Gustav I
// Created on: May 1, 2025
// This is the casino game that allows the user to pick
// between slot machine and bomb defusal games

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <thread>
#include <vector>

#include "Codes.h"

// Function PROCEDURE DECLARATIONS
int plays;  // global variable
int get_valid_game_selection();
int get_number_of_plays();
void slot_machine_spin(int plays);
void bomb_defusal_round(int plays);

// Function implementation
int get_valid_game_selection() {
    std::string selection;  //  local to valid game selection

    while (true) {
        std::cout << "Welcome to Gustav's Casino. Select a game.\n";
        std::cout << "Slot Machine (1) or Bomb Defusal (2): ";
        std::getline(std::cin, selection);
        if (selection == "1" || selection == "Slot Machine") {
            return 1;
        } else if (selection == "2" || selection == "Bomb Defusal") {
            return 2;
        } else {
            std::cout << "Invalid game selection. Please retry.\n\n";
        }
    }
}
//  Number of plays function
int get_number_of_plays() {
    std::cout << "Enter the number of times you'd like to play: ";
    std::cin >> plays;
    if (std::cin.fail()) {
        std::cout << "Please input a valid number of plays.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return get_number_of_plays();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (plays > 0) {
        return plays;
    } else {
        std::cout << "Number must be greater than 0.\n";
        return get_number_of_plays();
    }
}
//  Slot machine function
void slot_machine_spin(int plays) {
    std::vector<std::string> result(3);
    for (int j = 0; j < plays; ++j) {
        for (int i = 0; i < 3; ++i) {
            result[i] = SYMBOLS[rand() % SYMBOLS.size()];
        }
        std::cout << "--------\nResult:\n";
        for (const std::string& symbol : result) {
            std::cout << "| " << symbol << " | ";
        }
        std::cout << "\n";
        if (result[0] == "7" && result[1] == "7" && result[2] == "7") {
            std::cout << "JACKPOT! YEEHAW\n";
        } else if (result[0] == "🍒" && result[1] == \
            "🍒" && result[2] == "🍒") {
            std::cout << "You got a small win!\n";
        } else if (result[0] == "💎" && result[1]
            == "💎" && result[2] == "💎") {
            std::cout << "BLING BLING!YOU’RE THE REAL THING!\n";
        } else if (result[0] == "🔔" && result[1]
            == "🔔" && result[2] == "🔔") {
            std::cout << "DING DING DING. WE GOT A WINNER!\n";
        } else {
            std::cout << "Fun fact: 99% of gamblers quit before they win big. ";
            std::cout << "Don't be one of them." << std::endl;
        }
    }
}
//  Bomb Defusal function
void bomb_defusal_round(int plays) {
    for (int k = 0; k < plays; ++k) {
        std::srand(std::time(nullptr));
        auto it = CODE_MAP.begin();
        std::advance(it, rand() % CODE_MAP.size());
        std::string correct_code =
        it->first;
        std::cout << "Guess the code to defuse the bomb." <<
        "You have 20 seconds!\n";
        std::cout << "Available codes:\n";
        for (const auto& pair : CODE_MAP) {
            std::cout << "- " << pair.first << "\n";
        }
        std::string user_code;
        auto start_time = std::chrono::steady_clock::now();
        bool defused = false;
        while (true) {
            auto current_time = std::chrono::steady_clock::now();
            int seconds_passed =
                std::chrono::duration_cast<std::chrono::seconds>(current_time -
                                                                 start_time)
                    .count();
            if (seconds_passed >= 20) {
                continue;
            }
            std::cout << "Timer: " << (20 - seconds_passed) << "s remaining\n";
            std::getline(std::cin, user_code);
            if (user_code == correct_code) {
                defused = true;
                break;
            } else {
                std::cout << "Incorrect code. Try again!\n";
            }
        }
        if (defused) {
            std::cout << "Great! You saved us all!\n";
        } else {
            std::cout << "Call an ambulance! We’re hurt!\n";
        }
    }
}

//  Call the functions
int main() {
    std::srand(std::time(nullptr));
    int selection = get_valid_game_selection();
    int plays = get_number_of_plays();
    if (selection == 1) {
        slot_machine_spin(plays);
    } else if (selection == 2) {
        bomb_defusal_round(plays);
    }
    return 0;
}
