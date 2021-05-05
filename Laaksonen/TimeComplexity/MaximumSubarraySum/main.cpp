#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <thread>

void max_subarray_sum_1(int arr[], int n);
void max_subarray_sum_2(int arr[], int n);
void max_subarray_sum_3(int arr[], int n);

int main() {
    // int arr[] = {-1, 2, 4, -3, 5, 2, -5, 2};
    // int n = sizeof(arr) / sizeof(*arr);

    int n = 0;
    srand(time(0));

    std::cout << "Enter an array size" << std::endl;
    std::cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 201 + (-100);
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    
    std::thread first(max_subarray_sum_1, arr, n); // O(n^3)
    std::cout << "First thread running...\n"; 
    std::thread second(max_subarray_sum_2, arr, n); // O(n^2)
    std::cout << "Second thread running...\n";
    std::thread third(max_subarray_sum_3, arr, n); // O(n) -> Kadane's Algorithm
    std::cout << "Third thread running...\n";

    first.join();
    std::cout << "First thread finished\n";
    second.join();
    std::cout << "Second thread finished\n";
    third.join();
    std::cout << "Third thread finished\n";

    return 0;
}

void max_subarray_sum_1(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();

    int best = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k < j; k++) {
                sum += arr[k];
            }
            best = std::max(best, sum);
        }
    }
    std::cout << "O(n^3)" << "\n";
    std::cout << "Best: " << best << "\n";

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "endl: " << duration.count() << "ms" << std::endl;
}

void max_subarray_sum_2(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();
    
    int best = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            best = std::max(best, sum);
        }
    }
    std::cout << "O(n^2)" << "\n";
    std::cout << "Best: " << best << "\n";

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "endl: " << duration.count() << "ms" << std::endl;
}

void max_subarray_sum_3(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();

    int best = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        sum = std::max(arr[i], sum + arr[i]);
        best = std::max(best, sum);
    }
    std::cout << "O(n)" << "\n";
    std::cout << "Best: " << best << "\n";

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "endl: " << duration.count() << "ms" << std::endl;
}