#include <vector>
#include <iostream>
#include <math.h>
#include <string>
#include <random>


std::pair<int*, int> read_array(std::string input_s) {
    int length = std::count(input_s.begin(), input_s.end(), ' ') + 1;
    int* arr = new int[length];
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


void qsort(int* arr, int l, int r) {

    if (l < r) {
        int j = partition(arr, l, r);

        qsort(arr, l, j - 1);
        qsort(arr, j + 1, r);

    }

}

void qsort_tail_eliminated(int* arr, int l, int r) {

    while (l < r) {
        int j = partition(arr, l ,r);

        qsort_tail_eliminated(arr, l, j - 1);
        l = j + 1;
    }
}



void qsort_faster(int* arr, int l, int r) {

    while (l < r) {
        int j = partition(arr, l, r);

        if (j >= (l + r) / 2) {
            qsort_faster(arr, j + 1, r);
            r = j - 1;
        } else {
            qsort_faster(arr, l, j - 1);
            l = j + 1;
        }

    }

}

int main() {

    std::string input_s;
    std::getline(std::cin, input_s);

    int N;
    int* arr;
    std::tie(arr, N) = read_array(input_s);

    qsort_faster(arr, 0, N - 1);

    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl;

    return 0;
}