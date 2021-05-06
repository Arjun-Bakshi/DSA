#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

void binary_search_1(int arr[], int n, int x);
void binary_search_2(int arr[], int n, int x);
void lower_upper_bound();

int main() {

    int n = 0;
    std::srand(std::time(0));

    std::cout << "Enter an array size" << std::endl;
    std::cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = i;
        // std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    int search = std::rand() % n;

    binary_search_1(arr, n, search);
    binary_search_2(arr, n, search);
    std::cout << "\n";

    lower_upper_bound();
    std::cout << "\n";

    // Smallest Solution -> Function Change
    /*int x = -1;
    for (int b = z; b >= 1; b /= 2) {
        while (!ok(x + b)) x += b;
    }
    int k = x + 1;*/

    // Maximum Value -> Function Increasing then Decreasing
    /*int x = -1;
    for (int b = z; b >= 1; b /= 2) {
        while (f(x + b) < f(x + b + 1)) x += b;
    }
    int k = x + 1;*/
    
    return 0;
}

void binary_search_1(int arr[], int n, int x) {
    int a = 0, b = n - 1;
    auto start = std::chrono::high_resolution_clock::now();
    while (a <= b) {
        int k = (a + b) / 2;
        if (arr[k] == x) {
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "Ordinary Binary Search: " << duration.count() << "ms" << std::endl;
            std::cout << x << " found at index: " << k << "\n";
        }
        if (arr[k] > x) b = k - 1;
        else a = k + 1;
    }
}

void binary_search_2(int arr[], int n, int x) {
    int k = 0;
    auto start = std::chrono::high_resolution_clock::now();
    for (int b = n / 2; b >= 1; b /= 2) {
        while (k + b < n && arr[k + b] <= x) k += b;
    }
    if (arr[k] == x) {
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Jump Binary Search: " << duration.count() << "ms" << std::endl;
        std::cout << x << " found at index: " << k << "\n"; 
    }
}

void lower_upper_bound() {
    int n = 14;
    int arr[] = {0, 1, 1, 2, 3, 3, 4, 5, 6, 6, 7, 7, 7, 8};
    int x;

    std::cout << "Enter a value to search for from 0 to 8\n";
    std::cin >> x;

    std::cout << "Lower bound\n";
    auto k = std::lower_bound(arr, arr + n, x) - arr;
    if (k < n && arr[k] == x) {
        std::cout << x << " found at index: " << k << "\n";
    }

    std::cout << "Number of elements that are " << x << ": ";
    auto a = std::lower_bound(arr, arr + n, x);
    auto b = std::upper_bound(arr, arr + n, x);
    std::cout << b - a << "\n";

    std::cout << "Number of elements that are " << x << " using equal_range: ";
    auto r = std::equal_range(arr, arr + n, x);
    std::cout << r.second - r.first << "\n";
}