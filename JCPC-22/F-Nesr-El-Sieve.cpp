#include <iostream>
#include <fstream>
#include <string>

int gcd(int one, int two) {
    if (one == 0) return two;
    if (two == 0) return one;
    if (one > two) {
        return gcd(one % two, two);
    }
    else {
        return gcd(one, two % one);
    }
}

int main(int argc, char** argv) {

    std::string line, lined;

    std::ifstream inputfile("sieve.in");

    getline(inputfile, line);
    int number = stoi(line);

    for (int i = 0; i < number; i++) {
        getline(inputfile, line);
        getline(inputfile, lined);

        std::cout << gcd(line.length(), lined.length()) << std::endl;
        
    }

    return 0;
}