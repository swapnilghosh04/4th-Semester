#include <iostream>
using namespace std;
#define max 100

int main() {
  int a[max], temp[max], k, i, j, n, size, l1, h1, l2, h2;
  cout<<"Enter the number of elements of the array: ";
  cin>>n;
  cout<<"Enter the array elements:"<<endl;
  for(i=0; i<n; i++) {
    cout<<"a["<<i<<"] = ";
    cin>>a[i];
  }
  
  cout<<"The unsorted list is: ";
  for(i=0; i<n; i++) {
    cout<<a[i]<<" ";
  }
  cout<<endl;
  
  for(size=1; size<n; size=size*2) {
    l1=0;
    k=0;
    while(l1+size<n) {
      h1=l1+size-1;
      l2=h1+1;
      h2=l2+size-1;
      
      if(h2>=n)
        h2=n-1;
        
      i=l1;
      j=l2;
      while(i<=h1 && j<=h2) {
        if(a[i]<=a[j])
          temp[k++]=a[i++];
        else
          temp[k++]=a[j++];
      }
      
      while(i<=h1)
        temp[k++]=a[i++];
      while(j<=h2)
        temp[k++]=a[j++];
      
      l1=h2+1;
    }
    
    for(i=l1; k<n; k++) {
      temp[k++]=a[i];
    }
    for(i=0; i<n; i++) {
      a[i]=temp[i];
    }
    
    cout<<endl<<"Size = "<<size<<endl<<"Elements are:"<<endl;
    for(i=0; i<n; i++) {
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }
  
  cout<<endl<<"Sorted list is: ";
  for(i=0; i<n; i++) {
    cout<<a[i]<<" ";
  }
  cout<<endl;
  return 0;
}
