/**
 * \file StackTest.cpp
 * 
 * This file contains a main function for the stack
 * tests. It tests all methods implementeds in structure.
 *
 * \date Creation: 20/06/2017
 * \date Alteration: 20/06/2017
 * \author Lucas Fonseca dos Santos
 */
#include "../include/Stack.h"
#include <iostream>
#include <string>

using namespace std;

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
    cout << "+[#] COMPARE IF TWO EQUALS STACKS ARE EQUALS:+\n";
    cout << "+[#] STACK_1:\n";
    cout << "Inserction Element [9]: " << s.push(9) << "\n";
    cout << "Inserction Element [9]: " << s.push(9) << "\n";
    cout << "Inserction Element [1]: " << s.push(1) << "\n";
    cout << "Inserction Element [6]: " << s.push(6) << "\n";
    cout << "Inserction Element [9]: " << s.push(9) << "\n";
    cout << "Inserction Element [9]: " << s.push(9) << "\n";
    cout << "Inserction Element [6]: " << s.push(6) << "\n";
    cout << "Inserction Element [6]: " << s.push(6) << "\n";
    cout << "Inserction Element [2]: " << s.push(2) << "\n";
    cout << "+[#] STACK_2:\n";
    Stack stackTwo;
    cout << "Inserction Element [9]: " << stackTwo.push(9) << "\n";
    cout << "Inserction Element [9]: " << stackTwo.push(9) << "\n";
    cout << "Inserction Element [1]: " << stackTwo.push(1) << "\n";
    cout << "Inserction Element [6]: " << stackTwo.push(6) << "\n";
    cout << "Inserction Element [9]: " << stackTwo.push(9) << "\n";
    cout << "Inserction Element [9]: " << stackTwo.push(9) << "\n";
    cout << "Inserction Element [6]: " << stackTwo.push(6) << "\n";
    cout << "Inserction Element [6]: " << stackTwo.push(6) << "\n";
    cout << "Inserction Element [2]: " << stackTwo.push(2) << "\n";
    //cout << "[#] ARE THE STACKS EQUALS? " << s.equals(stackTwo) << "\n";
    cout << "+--------------------------------------------+\n";
    cout << "+[#] PRINT OUT WITH PARAMETER 50, > STACK SIZE:\n";
    cout << stackTwo.print(50) << "\n";
    cout << "+--------------------------------------------+\n";
    cout << "+[#] PRINT OUT WITH PARAMETER 0, < STACK SIZE:\n";
    cout << stackTwo.print(0) << "\n";
    cout << "+--------------------------------------------+\n";
    cout << "+[#] PRINT OUT WITH PARAMETER 4, < STACK SIZE:\n";
    cout << stackTwo.print(4) << "\n";
    cout << "+--------------------------------------------+\n";
    cout << "+[#] PRINT OUT WITH PARAMETER STACK SIZE:\n";
    cout << stackTwo.print(stackTwo.getSize()) << "\n";
    cout << "+--------------------------------------------+\n";
    return 0;
 }