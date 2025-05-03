// Copyright (c) 2025 Gustav I
// Created by: Gustav I
// Created on: May 1, 2025
// This is the casino game's codes.cpp file (dictionary of valid codes and values)

// Codes.h
#ifndef CODES_H
#define CODES_H
#include <vector>
#include <string>
#include <map>

// List of symbols used in slot machine
const std::vector<std::string> SYMBOLS = {"💎", "7", "🍒", "🍋", "🔔", "🍊", "🍉"};

// List of bomb codes (color names)
const std::map<std::string, bool> CODE_MAP = {
    {"Red", true}, {"Green", true}, {"Blue", true}, {"Yellow", true}, {"Gray", true}, {"White", true}};

#endif // CODES_H