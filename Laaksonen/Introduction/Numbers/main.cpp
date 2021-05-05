#include <iostream>
#include <typeinfo>

void factorial();
void is_equal();

int main() {
    long long x = 123456789123456789LL;
    std::cout << "This is a " << typeid(x).name() << "(long long): " << x << std::endl;

    int a = 123456789;
    long long b = a * a;
    std::cout << a << " * " << a <<" -> This is a " << typeid(b).name() << "(long long? -> int): " << b << std::endl;

    long long new_a = 123456789;
    long long new_b = new_a * new_a;
    std::cout << new_a << " * " << new_a << " -> This is a " << typeid(new_b).name() << "(long long): " << new_b << std::endl;

    factorial();

    double y = 0.3 * 3 + 0.1;
    printf("%.20f\n", y);

    is_equal();

    return 0;
}

void factorial() {
    long long x = 1;
    int n, m;

    std::cout << "Enter the factorial n and modulo m: " << std::endl;
    std::cin >> n >> m;

    for (int i = 2; i <= n; i++) {
        x = (x * i) % m;
    }
    std::cout << x % m << "\n";
}

void is_equal() {
    double a, b;

    std::cout << "Enter two numbers to be compared: " << std::endl;
    std::cin >> a >> b;
    if (abs(a - b) < 1e-9) {
        std::cout << "Equal!" << std::endl;        
    } else {
        std::cout << "Not Equal!" << std::endl;
    }
}