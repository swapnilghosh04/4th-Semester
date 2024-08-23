#include<iostream>
using namespace std;
#include<stdlib.h>

int main() {
  int i, j, n, temp, a[1000];
  time_t t1;
  srand((unsigned) time(&t1));
  cout<<"Enter the size of the array: ";
  cin>>n;
  for(i=0; i<10; i++) {
    a[i]=rand()%1000;
  }
  cout<<"Before sorting:"<<endl;
  for(i=0; i<10; i++) {
    cout<<a[i]<<" ";
  }
  cout<<endl;
  
  for(i=0; i<n-1; i++) {
    for(j=0; j<n-i-1; j++) {
      if(a[j]>a[j+1]) {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
  
  cout<<"After sorting:"<<endl;
  for(i=0; i<10; i++) {
    cout<<a[i]<<" ";
  }
  cout<<endl;
  return 0;
}
