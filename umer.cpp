//C++ Program starts
#include<iostream>
using namespace std;


class Bubble_Sorting{
int size;
int* array;

public:

Bubble_Sorting(int s){
    size=s;
    array=new int[size];
}

void input(){
cout<<"Enter Elements of Array: "<<endl;
for(int i=0;i<size;i++){
   cin>>array[i];
}
cout<<endl;
}

void display(){
cout<<"Elements of Array: "<<endl;
for(int i=0;i<size;i++){
    cout<<array[i]<<" ";
}
cout<<endl;
}

void sorting(){
     for(int i=0;i<size-1;i++) {
            for(int j=0;j<size-i-1;j++) {
                if(array[j]>array[j+1]) {

                    int temp=array[j];
                    array[j]=array[j+1];
                    array[j+1]=temp;
                }
            }

            cout<<endl;
        cout<<"Press Enter To continue: "<<endl;
        cin.get();
        cout<<"Step"<<i+1<<" :";
        display();
        cout<<endl;   
    }
}

~Bubble_Sorting(){
delete[] array;
}

}
;

int main()
{
    int size;
cout<<"Enter size of Array: ";      cin>>size;

Bubble_Sorting bs(size); 

bs.input();
cout<<endl;
bs.display();
cout<<endl;
cout<<"                                       Visualize Sorted Array                                "<<endl;
bs.sorting();
cout<<endl;

return 0;  
}

