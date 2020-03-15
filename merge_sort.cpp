#include <vector>
#include <iostream>
#include <math.h>

using namespace std;


int* merge(int arr_1[], int arr_2[], size_t n1, size_t n2) {
    int i=0, j=0, k=0;
    int* result = new int[n1 + n2];

    while ((i < n1) || (j < n2)) {
        if (i == n1) {
            while (j < n2) {
                result[k] = arr_2[j];
                j++;
                k++;
            }
        } else if (j == n2) {
            while (i < n1) {
                result[k] = arr_1[i];
                i++;
                k++;
            }
        } else {
            if (arr_1[i] < arr_2[j]) {
                result[k] = arr_1[i];
                i++;
            } else {
                result[k] = arr_2[j];
                j++;
            }
            k++;
        }
    }

    return result;
}

int* merge_sort(int arr[], size_t N) {
    if (N == 1) {
        return arr;
    }
    int n = round(float(N) / 2);

    int* arr_ = (arr + n);

    int* arr_1 = new int[n];
    arr_1 = merge_sort(arr, n);

    int* arr_2 = new int[N - n];
    arr_2 = merge_sort(arr_, N - n);

    return merge(arr_1, arr_2, n, N - n);
}

//void merge_sort_recursive(int& arr) {
//
//}

int main() {
    int N;
    cin >> N;

    int* arr = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    arr = merge_sort(arr, N);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }

    cout << endl;

    return 0;
}