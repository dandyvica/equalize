#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>
#include <cerrno>
#include <iomanip>

using namespace std;

// Very simple utility used to output all lines of an ASCII file with
// the same length. The desired line length is output as a second argument.
// Shorter lines are padded with blanks and longer lines are simply trimmed.
//
// usage: equalize [FILE] [LINE_LENGTH]
//
// compile with GCC: g++ equalize.cpp -o equalize -std=c++11 -O3 -s
int main(int argc, char *argv[]) 
{
    // line read from file
    string line;

    // check arguments
    if (argc != 3)
    {
        cout << "Usage: equalize [FILE] [LINE_LENGTH]" << endl;

        string help = "\nVery simple utility used to output all lines of an ASCII file with the same length.\n"
        "The desired line length is output as a second argument. Shorter lines are padded with blanks and longer lines are simply trimmed.";
        cout << help << endl;

        exit(1);
    }

    // file handle
    ifstream input_file(argv[1]);

    // check if file is opened
    if (input_file.fail())
    {
        cout << "Unable to open file <" << argv[1] << ">. Error <" << std::strerror(errno) << ">" << endl;
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

