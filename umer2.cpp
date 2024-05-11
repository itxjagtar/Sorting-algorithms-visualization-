//C++ Program starts
#include<iostream>
using namespace std;

void counting_sort(int ary[],int n){

int max=ary[0];
for(int i=1;i<n;i++){
if (ary[i]>max){
    max=ary[i];
}
}

int* count= new int[max+1]{0};
for(int i=0;i<n;i++){
    count[ary[i]]++;
}

for(int i=1;i<=max;i++){
    count[i]+=count[i-1];
}

int* sorted=new int[n];
for(int i=n-1;i>=0;i--){
sorted[--count[ary[i]]]=ary[i];
}

for(int i=0;i<n;i++){
    ary[i]=sorted[i];
}

delete[] count;
delete[] sorted;
};


int main()
{
int s;
cout<<"Size of array: ";            cin>>s;

int* arr=new int[s];
cout<<"Enter elements of array: "<<endl;       
for(int i=0;i<s;i++){
    cin>>arr[i];
}
cout<<endl;

cout<<"Given array: ";
for(int i=0;i<s;i++){
    cout<<arr[i]<<"  ";
}
cout<<endl;
counting_sort(arr,s);

cout<<"Sorted Array: ";
for(int i=0;i<s;i++){
    cout<<arr[i]<<"  ";
}

delete[] arr;
return 0;
}
