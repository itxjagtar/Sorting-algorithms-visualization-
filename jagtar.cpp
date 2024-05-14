#include <iostream>
using namespace std;

class Array {
private:
    int size;
    int* arr;

public:
    Array(int s) {
        size = s;
        arr = new int[size];
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    ~Array() {
        delete[] arr;
    }

    void insertionSort() {
        for (int i = 1; i < size; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
                cout << "Press Enter to continue: ";
                cin.ignore();
                cin.get();
                display();
            }
            arr[j + 1] = key;
            cout << "Press Enter to continue: ";
            cin.ignore();
            cin.get();
            display();
        }
    }

    void display() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    Array arr(size);
    cout << "Original array: ";
    arr.display();
    arr.insertionSort();
    cout << "Sorted array: ";
    arr.display();
    return 0;
}
