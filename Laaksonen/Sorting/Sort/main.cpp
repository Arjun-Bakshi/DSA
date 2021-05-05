#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void vector_print(std::vector<int> v);
void vector_sort();
void array_print(int arr[], int n);
void array_sort();
void string_sort();

int main() {

    vector_sort();
    std::cout << "\n";
    array_sort();
    std::cout << "\n";
    string_sort();
    return 0;
}

void vector_print(std::vector<int> v) {

    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << " ";
    }
    std::cout << "\n";
}

void array_print(int arr[], int n) {
    
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void vector_sort() {

    std::vector<int> v = {4, 2, 5, 3, 5, 8, 3};

    std::cout << "Original: ";
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

    std::cout << "Original: ";
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

    std::cout << "Original: ";
    std::cout << s << "\n";

    sort(s.begin(), s.end());
    std::cout << "Sorted: ";
    std::cout << s << "\n";

    sort(s.rbegin(), s.rend());
    std::cout << "Reverse sort: ";
    std::cout << s << "\n";
}