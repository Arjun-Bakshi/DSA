#include <iostream>
#include <typeinfo>

int main() {
    long long x = 123456789123456789LL;
    std::cout << "This is a " << typeid(x).name() << "(long long): " << x << std::endl;

    int a = 123456789;
    long long b = a * a;
    std::cout << a << " * " << a <<" -> This is a " << typeid(b).name() << "(long long? -> int): " << b << std::endl;

    long long new_a = 123456789;
    long long new_b = new_a * new_a;
    std::cout << new_a << " * " << new_a << " -> This is a " << typeid(new_b).name() << "(long long): " << new_b << std::endl;

    return 0;
}