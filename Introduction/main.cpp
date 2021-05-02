#include <iostream>
#include <string>
#include <chrono>

void inputs();
void output_endl();
void output_newline();

int main() {
    std::cout << "This is epic\n" << std::endl;
    inputs();
    std::cout << "Let's actually time the program execution times for endl and \\n \n" << std::endl;
    output_endl();
    output_newline();
    return 0;
}

void inputs() {
    int a, b;
    std::string x;
    
    std::cout << "Now enter two digits and a string" << std::endl;
    std::cin >> a >> b >> x;
    std::cout << "First digit: " << a << ", Second digit: " << b << ", String: " << x << "\n" << std::endl;
}

void output_endl() {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Hello World" << std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "endl: " << duration.count() << "ms" << std::endl;
}

void output_newline() {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Hello World\n";
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "\\n: " << duration.count() << "ms" << std::endl;
}