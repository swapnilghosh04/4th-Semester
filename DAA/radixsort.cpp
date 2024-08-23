#include<iostream>
using namespace std;

int main() {
  int a[100], b[100], c[100][100], i, j, max, p, r, temp, k;
  
  cout<<"Enter the 10 values for the a[] array: "<<endl;
  for(i=0; i<10; i++) {
    cout<<"a["<<i<<"]=";
    cin>>a[i];
  }
  cout<<"The 10 values of the a[] array are: "<<endl;
  for(i=0; i<10; i++) {
    cout<<a[i]<<" ";
  }
  cout<<endl;
  
  for(i=0; i<10; i++) {
    b[i]=0;
  }
  cout<<"The 10 elements of the b[] array: "<<endl;
  for(i=0; i<10; i++) {
    cout<<b[i]<<" ";
  }
  cout<<endl;

  max=a[0];
  for(i=1; i<10; i++) {
    if(max<a[i]) {
      max=a[i];
    }
  }
  
  int count=0;
  while(max>0) {
    max=max/10;
    count++;
  }
  
  temp=1;
  for(p=0; p<count; p++) {
    for(i=0; i<10; i++) {
      r=a[i]/temp;
      r=r%10;
      c[r][b[r]]=a[i];
      b[r]++;
    }
    temp=temp*10;
    
    int k=0;
    for(i=0; i<10; i++) {
      for(j=0; j<b[i]; j++) {
        a[k]=c[i][j];
        k++;
      }
      b[i]=0;
    }
  }
  
  cout<<"The array is: "<<endl;
  for(k=0; k<10; k++) {
    cout<<a[k]<<" ";
  }
  cout<<endl;
}    
  
