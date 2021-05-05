#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <tuple>

template <class T>
void vector_print(std::vector<T> v);
void vector_sort();
void array_print(int arr[], int n);
void array_sort();
void string_sort();
template <class T>
void pair_print(std::vector<std::pair<T,T>> v);
void pair_sort();
template <class T>
void tuple_print(std::vector<std::tuple<T,T,T>> v);
void tuple_sort();
void struct_compare();
bool comp(std::string a, std::string b);
void string_comp();

struct P {
    int x, y;
    bool operator<(const P &p) {
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
};

int main() {

    vector_sort();
    std::cout << "\n";
    array_sort();
    std::cout << "\n";
    string_sort();
    std::cout << "\n";
    pair_sort();
    std::cout << "\n";
    tuple_sort();
    std::cout << "\n";
    struct_compare();
    std::cout << "\n";
    string_comp();
    return 0;
}

template <class T>
void vector_print(std::vector<T> v) {

    std::cout << "[";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i);
        if (i < v.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

void array_print(int arr[], int n) {
    
    std::cout << "[";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i < n - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

template <class T>
void pair_print(std::vector<std::pair<T,T>> v) {

    std::cout << "[";
    for (int i = 0; i < v.size(); i++) {
        std::cout << "(" << v.at(i).first << ", " << v.at(i).second << ")";
        if (i < v.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

template <class T>
void tuple_print(std::vector<std::tuple<T,T,T>> v) {

    std::cout << "[";
    for (int i = 0; i < v.size(); i++) {
        std::cout << "(" << std::get<0>(v[i]) << ", " << std::get<1>(v[i]) << ", " << std::get<2>(v[i]) << ")";
        if (i < v.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

void vector_sort() {

    std::vector<int> v = {4, 2, 5, 3, 5, 8, 3};

    std::cout << "Vector\nOriginal: ";
    vector_print(v);

    std::sort(v.begin(),v.end());
    std::cout << "Sorted: ";
    vector_print(v);

    std::sort(v.rbegin(),v.rend());
    std::cout << "Reverse sort: ";
    vector_print(v);
}

void array_sort() {

    int n = 7;
    int arr[] = {4, 2, 5, 3, 5, 8, 3};

    std::cout << "Array\nOriginal: ";
    array_print(arr, n);

    std::sort(arr, arr + n);
    std::cout << "Sorted: ";
    array_print(arr, n);

    std::sort(arr, arr + n, std::greater<int>());
    std::cout << "Reverse sort: ";
    array_print(arr, n);
}

void string_sort() {
    
    std::string s = "monkey";

    std::cout << "String\nOriginal: ";
    std::cout << s << "\n";

    sort(s.begin(), s.end());
    std::cout << "Sorted: ";
    std::cout << s << "\n";

    sort(s.rbegin(), s.rend());
    std::cout << "Reverse sort: ";
    std::cout << s << "\n";
}

void pair_sort() {

    std::vector<std::pair<int,int>> v;
    v.push_back({1,5});
    v.push_back({2,3});
    v.push_back({1,2});

    std::cout << "Pair\nOriginal: ";
    pair_print(v);

    sort(v.begin(), v.end());
    std::cout << "Sorted: ";
    pair_print(v);

    sort(v.rbegin(), v.rend());
    std::cout << "Reverse sort: ";
    pair_print(v);    
}

void tuple_sort() {

    std::vector<std::tuple<int,int,int>> v;
    v.push_back({2,1,4});
    v.push_back({1,5,3});
    v.push_back({2,1,3});

    std::cout << "Tuple\nOriginal: ";
    tuple_print(v);

    sort(v.begin(), v.end());
    std::cout << "Sorted: ";
    tuple_print(v);

    sort(v.rbegin(), v.rend());
    std::cout << "Reverse sort: ";
    tuple_print(v);   
}

void struct_compare() {
    struct P p;
    p.x = 3;
    p.y = 4;

    std::cout << (1 < p.x) << "\n";
    std::cout << (7 < p.y) << "\n";
}

bool comp(std::string a, std::string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

void string_comp() {

    std::vector<std::string> v = {"pineapple", "apple"};
    
    std::cout << "Vector with String\nOriginal: ";
    vector_print(v);

    sort(v.begin(), v.end(), comp);
    std::cout << "Sorted: ";
    vector_print(v);

    sort(v.rbegin(), v.rend(), comp);
    std::cout << "Reverse sort: ";
    vector_print(v);
}