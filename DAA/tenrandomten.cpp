#include<iostream>
using namespace std;
#include<stdlib.h>

int main() {
  int i, a[10];
  for(i=0; i<10; i++) {
    a[i]=rand()%10;
  }
  cout<<"The ten random numbers are:"<<endl;
  for(i=0; i<10; i++) {
    cout<<a[i]<<" ";
  }
  cout<<endl;
  return 0;
}
