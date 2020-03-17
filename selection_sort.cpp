#include <vector>
#include <iostream>

using namespace std;


void selection_sort(int* to_sort, size_t N) {
    for (size_t k = 0 ; k < N; k++) {
        int min_val = to_sort[k];
        int idx = k;
        for (size_t i = k; i < N; i++) {
            if (to_sort[i] < min_val) {
                min_val = to_sort[i];
                idx = i;
            }
        }
        swap(to_sort[idx], to_sort[k]);
    }
}


int main() {
    size_t N;
    cin >> N;

    int* array = new int[N];

    for (int i = 0; i < N; i++) {
        int insert;
        cin >> insert;
        array[i] = insert;
    }

    selection_sort(array, N);

    for (int i = 0; i < N; i++) {
        cout << array[i] << ' ';
    }

    cout << endl;

    return 0;
}

