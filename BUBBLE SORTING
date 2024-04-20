//C++ Program starts
#include<iostream>
using namespace std;


void display(int ary[],int s){

for(int i=0;i<s;i++){
cout<<ary[i]<<" ";
}
cout<<endl;

}

int main()
{
int size;
cout<<"Enter size of array: ";       cin>>size;
cin.ignore();
cout<<"Enter elements of array: ";  
cout<<endl; 

int *arr=new int[size];

for(int i=0;i<size;i++){
     cin>>arr[i];
}
cout<<endl;

cout<<"Elements of array: " ;
display(arr,size);
cout<<endl;
cout<<"***VISUALIZE SORTED ARRAY***"<<endl;

 for(int i=0;i<size-1;i++) {
            for(int j=0;j<size-i-1;j++) {
                if(arr[j]>arr[j+1]) {

                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        cout<<"Press Enter To continue: "<<endl;
        cin.get();
        cout<<"Step"<<i+1<<" :";
        display(arr,size);
        cout<<endl;   
    }
delete[] arr;
 return 0;
}
