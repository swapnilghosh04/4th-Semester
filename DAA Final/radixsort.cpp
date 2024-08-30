#include <iostream>
using namespace std;

int main() {
  int a[100], b[100], temp, max, i, j, n, p, r, c[100][100], k;
  cout<<"Enter the size of a[] array: ";
  cin>>n;
  cout<<"Enter the elements of a[] array: "<<endl;
  for(i=0; i<n; i++) {
    cout<<"a["<<i<<"] = ";
    cin>>a[i];
  }
  cout<<"The unsorted list is: ";
  for(i=0; i<n; i++) {
    cout<<a[i]<<" ";
  }
  cout<<endl;

  for(i=0; i<n; i++) {
    b[i]=0;
  }
  
  cout<<"The elements of the b[] array are:"<<endl;
  for(i=0; i<n; i++) {
    cout<<b[i]<<" ";
  }
  cout<<endl;
  
  max=a[0];
  for(i=1; i<n; i++) {
    if(max<a[i])
      max=a[i];
  }
  
  int count=0;
  while(max>0) {
    max=max/10;
    count++;
  }
  
  temp=1;
  for(p=0; p<count; p++) {
    for(i=0; i<n; i++) {
      r=a[i]/temp;
      r=r%10;
      c[r][b[r]]=a[i];
      b[r]++;
    }
    temp=temp*10;
    
    int k=0;
    for(i=0; i<n; i++) {
      for(j=0; j<b[i]; j++) {
        a[k]=c[i][j];
        k++;
      }
      b[i]=0;
    }
  }
  
  cout<<"The sorted list is: ";
  for(k=0; k<n; k++) {
    cout<<a[k]<<" ";
  }
  cout<<endl;
  return 0;
}
