#include <iostream>
#include <vector>
#include <string>

void v_iterate();
void v_back();
void v_declare();
void s_operations();

int main() {

    v_iterate();
    v_back();
    v_declare();
    s_operations();

    return 0;
}

void v_iterate() {
    std::vector<int> v;

    v.push_back(3); // [3]
    v.push_back(2); // [3,2]
    v.push_back(5); // [3,2,5]

    std::cout << v[0] << "\n"; // 3
    std::cout << v[1] << "\n"; // 2
    std::cout << v[2] << "\n"; // 5

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << "\n";
    }

    for (auto x : v) {
        std::cout << x << "\n";
    }
}

void v_back() {
    std::vector<int> v;

    v.push_back(5);
    v.push_back(2);
    std::cout << v.back() << "\n"; // 2
    v.pop_back();
    std::cout << v.back() << "\n"; // 5
}

void v_declare() {
    std::vector<int> v = {2,4,2,5,1};

    // size 10, initial value 0
    std::vector<int> v_ten(10);

    // size 10, initial value 5
    std::vector<int> v_init(10, 5);
}

void s_operations() {
    std::string a = "hatti";
    std::string b = a + a;
    std::cout << b << "\n"; // hattihatti
    b[5] = 'v';
    std::cout << b << "\n"; // hattivatti
    std::string c = b.substr(3,4);
    std::cout << c << "\n"; // tiva
}