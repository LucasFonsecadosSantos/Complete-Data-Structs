/**
 * \file StackTest.cpp
 * 
 * This file contains a main function for the stack
 * tests. It tests all methods implementeds in struct.
 *
 * \date Creation: 20/06/2017
 * \date Alteration: 20/06/2017
 * \author Lucas Fonseca dos Santos
 */
 #include "../include/Stack.h"
 #include <iostream>
 #include <string>

 int main() {
    Stack s;
    cout << "+--------------------------------------------+\n";
    cout << "Inserction Element [9]: " << s.push(9) << "\n";
    cout << "Inserction Element [9]: " << s.push(9) << "\n";
    cout << "Inserction Element [1]: " << s.push(1) << "\n";
    cout << "Inserction Element [6]: " << s.push(6) << "\n";
    cout << "Inserction Element [9]: " << s.push(9) << "\n";
    cout << "Inserction Element [9]: " << s.push(9) << "\n";
    cout << "Inserction Element [6]: " << s.push(6) << "\n";
    cout << "Inserction Element [6]: " << s.push(6) << "\n";
    cout << "Inserction Element [2]: " << s.push(2) << "\n";
    cout << "+--------------------------------------------+\n";
    cout << "Pop Element: " << s.pop() << "\n";
    cout << "Pop Element: " << s.pop() << "\n";
    cout << "Pop Element: " << s.pop() << "\n";
    cout << "Pop Element: " << s.pop() << "\n";
    cout << "Pop Element: " << s.pop() << "\n";
    cout << "Pop Element: " << s.pop() << "\n";
    cout << "Pop Element: " << s.pop() << "\n";
    cout << "Pop Element: " << s.pop() << "\n";
    cout << "Pop Element: " << s.pop() << "\n";
    cout << "+--------------------------------------------+\n";
    cout << "Inserction Element [9]: " << s.push(9) << "\n";
    cout << "Inserction Element [9]: " << s.push(9) << "\n";
    cout << "Inserction Element [1]: " << s.push(1) << "\n";
    cout << "Inserction Element [6]: " << s.push(6) << "\n";
    cout << "Inserction Element [9]: " << s.push(9) << "\n";
    cout << "Inserction Element [9]: " << s.push(9) << "\n";
    cout << "Inserction Element [6]: " << s.push(6) << "\n";
    cout << "Inserction Element [6]: " << s.push(6) << "\n";
    cout << "Inserction Element [2]: " << s.push(2) << "\n";
    cout << "+--------------------------------------------+\n";
    return 0;
 }