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

    void mergeSort() {
        mergeSortHelper(0, size - 1);
    }

    void display() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    void mergeSortHelper(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            cout << "Dividing: ";
            displaySubArray(left, right);

            mergeSortHelper(left, mid);
            mergeSortHelper(mid + 1, right);

            merge(left, mid, right);

            cout << "After merging: ";
            displaySubArray(left, right);
            cout << "Press Enter to continue: ";
            cin.ignore();
            cin.get();
        }
    }

    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int i = 0; i < n2; i++)
            R[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }

    void displaySubArray(int left, int right) const {
        for (int i = left; i <= right; i++) {
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
    arr.mergeSort();
    cout << "Sorted array: ";
    arr.display();
    return 0;
}
