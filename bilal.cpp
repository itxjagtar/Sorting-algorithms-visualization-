#include <iostream>
using namespace std;
class HeapSort {
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
    HeapSort(int arr[], int n) {
        heap = arr;
        size = n;
    }

    void sort() {
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(size, i);

        for (int i = size - 1; i > 0; i--) {
            swap(heap[0], heap[i]);
            heapify(i, 0);
        }
    }

class Selection_Sort{
private:
    int * arr;
    int n;
public:
    Selection_Sort(int n1){
        n=n1;
        arr=new int[n];
    }
    ~Selection_Sort() {
        delete[] arr;
    }
    void enterArray(){
        for( int i=0; i<n; i++){
            cout << "Enter the element " << i+1 << " in the array: ";
            cin >> arr[i];
        }
    }

   void initialArray(){
        cout << "Initial array: ";
        for( int i=0; i<n; i++){
            cout << "|" << arr[i] << "| ";
        }
        cout << endl;
    }

    void sortArray(){
        int min;
        for(int i=0; i<n-1; i++){
            min=i;
            for(int j=i+1; j<n; j++){
                if(arr[j] < arr[min]){
                    min=j;
                }
            }
            if(min !=i){
                int temp;
                temp=arr[i];
                arr[i]=arr[min];
                arr[min]=temp;
            }
            cout << "Press Enter to see the next iteration...";
            cin.get();
            cout << "Array after iteration " << i+1 << ":" << endl;
           for(int k = 0; k < n; k++) {
            if(k == i || k == min) {
                    cout << "|*" << arr[k] << "*| ";
                }else{
            cout << "| " << arr[k] << " ";
        }}
        cout << "|" << endl;
        }
    }

 void displaySortedArray(){
        cout << "Sorted Array: ";
        for(int k=0; k<n; k++){
            cout << "|" << arr[k] << "| ";
        }
        cout << endl;
    }
};

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid input. Number of elements must be positive." << endl;
        return 1;
    }
    Selection_Sort s1(n);
    s1.enterArray();
    s1.initialArray();
    cout << "Press Enter to start sorting..." << endl;
    cin.ignore();
    s1.sortArray();
    s1.displaySortedArray();
    return 0;
}
