#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>

using namespace std;

int main() {

    ifstream in("trick.in");
    ofstream out("trick.out");

    int n = 0;
    in >> n;


    long long x_counter = 1;
    long long value_counter = 0;
    for (int i = 0; i < n; ) {
        string command;
        in >> command;

        if (command == "add") {
            string str_value;
            in >> str_value;

            if (str_value == "?") {
                x_counter += 1;
            } else {
                int value = stoi(str_value);
                value_counter += value;
            }

            i++;
        } else if (command == "multiply"){
            string by;
            in >> by;
            int value;
            in >> value;

            x_counter *= value;
            value_counter *= value;

            i++;
        } else if (command == "subtract") {
            string str_value;
            in >> str_value;

            if (str_value == "?") {
                x_counter -= 1;
            } else {
                int value = stoi(str_value);
                value_counter -= value;
            }

            i++;
        }
    }

    if (x_counter != 0) {
        out << "Epic fail";
    } else {
        out << value_counter;
    }

    out << endl;

    return 0;
}