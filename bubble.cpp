#include <iostream>
#include <vector>
#include <time.h>

using std::cout;
using std::endl;
using std::vector;

void bubbleSort(vector<int>& arr);

int main()
{
    srand(time(0));
    vector<int> arr;
    cout << "Basic array: " << endl;
    for (int i = 0; i < (rand() % 10 + 5); i++) {
        arr.push_back(rand() % 25 + 1);
        cout << arr[i] << ' ';
    }
    cout << endl;
    bubbleSort(arr);
    int endTime = clock();
    cout << "Sorted array: " << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    cout << "Time: " << endTime / 1000.0 << " s" << endl;
    return 0;
}

void bubbleSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
