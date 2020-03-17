#include <vector>
#include <iostream>
#include <math.h>
#include <string>
#include <random>


std::pair<int*, int> read_array(std::string input_s) {
    int length = std::count(input_s.begin(), input_s.end(), ' ') + 1;
    int *arr = new int[length];
    int flag[length];
    for (int i = 0; i < length; i++) {
        flag[i] = 1;
    }

    int i = 0, j = 0;
    for (int i = 0; i < length; i++) {
        arr[i] = 0;
    }
    while (i < input_s.size()) {
        if (input_s[i] != ' ') {
            if (input_s[i] == '-') {
                flag[j] = -1;
            } else {
                arr[j] = arr[j] * 10 + flag[j] * (input_s[i] - 48);
            }
        } else {
            j++;
        }
        i++;
    }
    return std::make_pair(arr, length);
}

int partition(int* arr, int l, int r) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(l, r);

    int pivot_idx = dis(gen), j = l;
    int pivot = arr[pivot_idx];

    std::swap(arr[pivot_idx], arr[r]);

    for (int i = l; i < r; i++) {
        if (arr[i] <= pivot) {
            std::swap(arr[i], arr[j]);
            j++;
        }
    }

    std::swap(arr[r], arr[j]);

    return j;
}


int random_select(int* arr, int l, int r, int k) {

    while (l <= r) {
        if (l == r) {
            if (k != 1) {
                std::cout << "error!" << std::endl;
            }
            return arr[l];
        }
        int j = partition(arr, l, r);
        if (j - l + 1 < k) {
            k = k - (j - l + 1);
            return random_select(arr, j + 1, r, k);
        } else {
            return random_select(arr, l, j, k);
        }
    }
}

int main() {

    std::string input_s;
    std::getline(std::cin, input_s);

    int N;
    int* arr;
    std::tie(arr, N) = read_array(input_s);

    int k;
    std::cin >> k;

    int answer = random_select(arr, 0, N - 1, k);

    std::cout << answer << std::endl;

    return 0;
}