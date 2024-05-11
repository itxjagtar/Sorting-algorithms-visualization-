#include <iostream>
#include <iomanip>
using namespace std;
class Arr{
    public:
    virtual void EnterArray()=0;
    virtual void InitialArray()=0;
    virtual void SortArray()=0;
    virtual void DisplaySortArray()=0;
};
class CountingSort:public Arr {
private:
    int* count;
    int max_value;
    int * arr;
    int size;
public:
    CountingSort(int max_val,int size) {
        max_value = max_val;
        count = new int[max_value + 1];
        for (int i = 0; i <= max_value; ++i) {
            count[i] = 0;
        }
        this->size=size;
        arr=new int[size];
    }

    ~CountingSort() {
        delete[] count;
        delete[] arr;
    }

    void EnterArray() override  {
        cout << "Enter Elements of Array: " << endl;
        for(int i = 0; i < size; i++) {
            cin >> arr[i];
            cin.get();
        }
        cout << endl;
    }

    void InitialArray() override {
        cout << "Initial Array: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << "  " ;
        }
        cout << endl;
        cin.get();
    }

    void DisplayArrayStepWise(int step) {
        cout << "Array after step " << step + 1 << ": ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void SortArray() override {
        for (int i = 0; i < size; ++i) {
            count[arr[i]]++;
        }
        for (int i = 1; i <= max_value; ++i) {
            count[i] += count[i - 1];
        }
        int* sorted = new int[size];
        for (int i = size - 1; i >= 0; --i) {
            sorted[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }
        for (int i = 0; i < size; ++i) {
            arr[i] = sorted[i];
            DisplayArrayStepWise(i);
            cin.get();
        }

        delete[] sorted;
    }

    void DisplaySortArray() override {
        cout << "Sorted Array: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cin.get();
    }
};
class Bubble_Sorting:public Arr {
    int size;
    int* array;

public:
    Bubble_Sorting(int s) {
        size = s;
        array = new int[size];
    }

    void EnterArray() override {
        cout << "Enter Elements of Array: " << endl;
        for(int i = 0; i < size; i++) {
            cin >> array[i];
        }
        cout << endl;
    }

    void InitialArray() override {
        cout << "Initial Array: ";
        display();
        cout << endl;
    }

    void SortArray() override {
        for(int i = 0; i < size - 1; i++) {
            for(int j = 0; j < size - i - 1; j++) {
                if(array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
            cout << endl;
            cout << "Press Enter To continue: " << endl;
            cin.get();
            cout << "Step " << i + 1 << ": ";
            display();
            cout << endl;
        }
    }

    void DisplaySortArray() override {
        cout << "Sorted Array: ";
        display();
        cout << endl;
    }

    void display() {
        cout << "Elements of Array: ";
        for(int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
    }

    ~Bubble_Sorting() {
        delete[] array;
    }
};

class SelectionSort:public Arr {
private:
    int *arr;
    int n;

public:
    SelectionSort(int n1) {
        n = n1;
        arr = new int[n];
    }

    ~SelectionSort() {
        delete[] arr;
    }

    void EnterArray() override {
        for (int i = 0; i < n; i++) {
            cout << "Enter the element " << i + 1 << " in the array: ";
            cin >> arr[i];
        }
    }

    void InitialArray() override {
        cout << "Initial array: ";
        for (int i = 0; i < n; i++) {
            cout << "|" << arr[i] << "| ";
        }
        cout << endl;
    }

    void SortArray() override {
        int min;
        for (int i = 0; i < n - 1; i++) {
            min = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            if (min != i) {
                int temp;
                temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
            cout << "Press Enter to see the next iteration...";
            cin.get();
            cout << "Array after iteration " << i + 1 << ":" << endl;
            for (int k = 0; k < n; k++) {
                if (k == i || k == min) {
                    cout << "|*" << arr[k] << "*| ";
                } else {
                    cout << "| " << arr[k] << " ";
                }
            }
            cout << "|" << endl;
        }
    }

    void DisplaySortArray() override {
        cout << "Sorted Array: ";
        for (int k = 0; k < n; k++) {
            cout << "|" << arr[k] << "| ";
        }
        cout << endl;
    }
};
class HeapSort: public Arr {
private:
    int *heap;
    int size;

    void heapify(int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[largest])
            largest = left;

        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(n, largest);
        }
    }

public:
    HeapSort(int n) {
        size = n;
        heap = new int[size];
    }

    ~HeapSort() {
        delete[] heap;
    }

   void EnterArray() override {
        for (int i = 0; i < size; i++) {
            cout << "Enter the element " << i + 1 << " in the array: ";
            cin >> heap[i];
        }
    }

    void InitialArray() override {
        cout << "Initial array: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void SortArray() override {
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(size, i);
        for (int i = size - 1; i > 0; i--) {
            swap(heap[0], heap[i]);
            heapify(i, 0);
            cout << "Iteration " << size - i << ": ";
            for (int j = 0; j < size; ++j)
                cout << heap[j] << " ";
            cin.get();
        }
    }

    void DisplaySortArray() override {
        cout << "Sorted array using heap sort: ";
        for (int i = 0; i < size; ++i)
            cout << heap[i] << " ";
        cout << endl;
    }
};


int main() {
     Arr * a1;
     int n;
     int choice;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid input. Number of elements must be positive." << endl;
        return 1;
    }
    cout << "--------------------------------------------------------"<< endl;
    cout << " Select the Algorithm " << endl;
    cout << setw(20) <<" 1- Selection Sort" << endl;
    cout << setw(20) <<" 2- Heap Sort" << endl;
    cout << setw(20) <<" 3- Bubble Sort" << endl;
    cout << setw(20) <<" 4- Counting Sort" << endl;
    cout << "--------------------------------------------------------"<< endl;
    cout << "Enter the choice: ";
    cin >> choice;
    SelectionSort s1(n);
    HeapSort h1(n);
    Bubble_Sorting b1(n);
    CountingSort c1(100,n);
    switch (choice)
    {
    case 1:
    cout << endl;
    cout << "--------------------------------------------------" << endl;
    cout << setw(40) << "Selection Sort Algorithm "<< endl;
    cout << endl;
        a1=&s1;
    a1->EnterArray();
    a1->InitialArray();
    cout << "Press Enter to start selection sort..." << endl;
    cin.ignore();
    a1->SortArray();
    a1->DisplaySortArray();
    cout << "--------------------------------------------------" << endl;
    break;

    case 2:
    cout << endl;
    cout << "--------------------------------------------------" << endl;
    cout << setw(40) <<  "Heap Sort Algorithm "<< endl;
    cout <<endl;
     a1=&h1;
      a1->EnterArray();
    a1->InitialArray();
    cout << "Press Enter to start sorting..." << endl;
    cin.get();
    a1->SortArray();
    a1->DisplaySortArray();
    cout << "--------------------------------------------------" << endl;
    break;

    case 3:
    cout << endl;
    cout << "--------------------------------------------------" << endl;
    cout << setw(40) <<  "Bubble Sort Algorithm "<< endl;
    cout <<endl;
     a1=&b1;
      a1->EnterArray();
    a1->InitialArray();
    cout << "Press Enter to start sorting..." << endl;
    cin.get();
    a1->SortArray();
    a1->DisplaySortArray();
    cout << "--------------------------------------------------" << endl;
    break;

    case 4:
    cout << endl;
    cout << "--------------------------------------------------" << endl;
    cout << setw(40) <<  "Counting Sort Algorithm "<< endl;
    cout <<endl;
     a1=&c1;
      a1->EnterArray();
    a1->InitialArray();
    cout << "Press Enter to start sorting..." << endl;
    cin.get();
    a1->SortArray();
    a1->DisplaySortArray();
    cout << "--------------------------------------------------" << endl;
    break;
    default:
    cout << "Wrong input! Please enter 1 or 2"<< endl;
        break;
    }
    return 0;
}

