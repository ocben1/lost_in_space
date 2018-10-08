//if TERMINAL_USER_INPUT is not defined then include lines 5-15
#ifndef TERMINAL_USER_INPUT
#define TERMINAL_USER_INPUT

#include <string>
using std::string;

//prompts the user to input a string, identifying and declaring that input as a string constant 
string read_string(string prompt);

int read_integer(string prompt);
//prompts the user to input an integer, identifying and declaring that input as a constant variable of type int
int read_integer (string prompt, int min, int max);
//prompts the user to input an integer within a range
double read_double(string prompt);
//prompts the user to input a double, identifying and declaring the user's input to be a constant variable of type double
double read_double(string prompt, double min, double max);
//prompts the user to input a double within a range
bool read_boolean(string prompt);
//prompts the user to input a yes/no response
#endif