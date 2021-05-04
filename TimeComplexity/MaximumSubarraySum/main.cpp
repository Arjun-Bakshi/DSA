#include <iostream>
#include <chrono>

void max_subarray_sum_1(int arr[], int n);
void max_subarray_sum_2(int arr[], int n);
void max_subarray_sum_3(int arr[], int n);

int main() {
    int arr[] = {-1, 2, 4, -3, 5, 2, -5, 2};
    int n = sizeof(arr)/sizeof(*arr);

    max_subarray_sum_1(arr, n); // O(n^3)
    max_subarray_sum_2(arr, n); // O(n^2)
    max_subarray_sum_3(arr, n); // O(n) -> Kadane's Algorithm

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
    std::cout << "Best: " << best << "\n";

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "endl: " << duration.count() << "ms" << std::endl;
}