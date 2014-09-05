#include <iostream>
#include <cctype>
#include <string>
#include "error.h"
#include "stack.h"
#include "strlib.h"
#include "rational.h"
using namespace std;

/* Function prototypes */
void applyOperator(char op, Stack<Rational> & operandStack);
void helpCommand();
Rational stringToRational(string s);

/* Main program */
int main(int argc, char *argv[]) {
   cout << "RPN Calculator Simulation (type H for help)" << endl;
   Stack<Rational> operandStack;
   while (true) {
      cout << "> ";
      string line;
      getline(cin, line);
      if (line.length() == 0) line = "Q";
      char ch = toupper(line[0]);
      if (ch == 'Q') {
         break;
      } else if (ch == 'C') {
         operandStack.clear();
      } else if (ch == 'H') {
         helpCommand();
      } else if (isdigit(ch)) {
         operandStack.push(stringToRational(line));
      } else {
         applyOperator(ch, operandStack);
      } 
   }
return 0; 
}

void applyOperator(char op, Stack<Rational> & operandStack) {
   Rational result;
   Rational rhs = operandStack.pop();
   Rational lhs = operandStack.pop();
   switch (op) {
    case '+': result = lhs + rhs; break;
    case '-': result = lhs - rhs; break;
    case '*': result = lhs * rhs; break;
    case '/': result = lhs / rhs; break;
    default:  error("Illegal operator");
   }
   cout << result << endl;
   operandStack.push(result);
}
/*
 * Function: helpCommand
 * Usage: helpCommand();
 * ---------------------
 * This function generates a help message for the user.
 */
void helpCommand() {
  cout << "Enter expressions in Reverse Polish Notation," << endl;
  cout << "in which operators follow the operands to which" << endl;
  cout << "they apply.  Each line consists of a number, an" << endl;
  cout << "operator, or one of the following commands:" << endl;
  cout << "  Q -- Quit the program" << endl;
  cout << "  H -- Display this help message" << endl;
  cout << "  C -- Clear the calculator stack" << endl;
}

Rational stringToRational(string s) {
  int slashPos = s.find('/');
  string n;
  string d;
  if (slashPos < 1) {
    n = s;
    d = "1";
  } else {
    n = s.substr(0, slashPos);
    d = s.substr(slashPos + 1);
  }
  Rational rat(atoi(n.c_str()), atoi(d.c_str())); // stringToIngeger isn't working for some reason
  cout << rat << endl;
  return rat;
}





