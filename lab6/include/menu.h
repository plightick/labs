#ifndef MENU_H
#define MENU_H

#include "string_class.h"
#include "string_exceptions.h"
#include <iostream>
#include <sstream>
#include <limits>
#include <string>

using namespace std;

template<typename T>
T checkNumbers();

void handInputString(String& str);
void printStringMenu();
void showStrings(const String& str1, const String& str2);
void concatenateStrings(const String& str1, const String& str2);
void stringMenu();

#endif