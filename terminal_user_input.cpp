#include "splashkit.h"

using namespace std;

string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

double read_double(string prompt)
{
    string line;
    double result;

    line = read_string(prompt);

    while (not is_number(line) )
    {
        write_line("Please enter a number.");
        line = read_string(prompt);
    }

    result = convert_to_double(line);

    return result;
}
double read_double(string prompt, double min, double max)
{
    string line;
    double result = read_double(prompt);
    
    while ( result <= min or result >= max )
    {
        write_line("Please enter a number between " + to_string(min) + " and " + to_string(max));
        result = read_double(prompt);
    }
    
    return result;
}

int read_integer(string prompt)
{
    string line;
    int result;

    line = read_string(prompt);

    while (not is_integer(line) )
    {
        write_line("Please enter a whole number.");
        line = read_string(prompt);
    }

    result = convert_to_integer(line);

    return result;
}

int read_integer(string prompt, int min, int max)
{
    int result;

    result = read_integer(prompt);

    while ( result < min or result > max )
    {
        write_line("Please enter a number between " + to_string(min) + " and " + to_string(max));
        result = read_integer(prompt);
    }

    return result;
}
bool read_boolean(string prompt)
{
    string line = trim(to_lowercase(read_string(prompt)));
    while (line != "yes" && line != "y" && line != "no" && line != "n")
    {
        line = trim(to_lowercase(read_string("Invalid input: ")));
    }
    return (line == "yes" || line == "y");
}
