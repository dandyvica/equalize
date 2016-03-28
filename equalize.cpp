#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

// very simple utility used to output all lines of an ASCII file with
// the same length. The desired line length is output as a second argument.
// Shorter lines are padded with blanks and longer lines are simply trimmed.
//
// usage: equalize <file> <line length>
//
// compile with GCC: g++ equalize.cpp -o equalize -std=c++11
int main(int argc, char *argv[]) 
{
    // line read from file
    string line;

    // check arguments
    if (argc != 3)
    {
        cout << "wcc file line_length" << endl;
        exit(1);
    }

    // file handle
    ifstream input_file(argv[1]);

    // check if file is opened
    if (!input_file)
    {
        cout << "Unable to open file " << argv[1] << endl;
        exit(2);
    }

    // desired line length
    int desired_length = stoi(argv[2]);

    // read each line of the input file
    while (getline(input_file, line))
    {
        // get line length
        auto line_length = line.length();

        // send output with setw() with padded blanks if line length <= desired length
        if (line_length <= desired_length)
            cout << left << setw(desired_length) << line << endl;
        else 
            cout << line.substr(0, desired_length) << endl;
    }

    // close file and display values as: min max
    input_file.close();

}

