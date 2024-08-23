#include <iostream>
using namespace std;

int main() {
  int i, j, k, flag, n, a[1000];
  time_t t1;
  srand((unsigned) time(&t1));
  cout<<"Enter the size of the array: ";
  cin>>n;
  for(i=0; i<n; i++) {
    while(1) {
      k=rand()%5;
      flag=0;
      
      for(j=0; j<i; j++) {
        if(a[j]==k)
          flag=1;
      }
      
      if(flag==0) {
        a[i]=k;
        break;
      }
    }
  }
  
  for(i=0; i<n; i++) {
    cout<<a[i]<<" ";
  }
  cout<<endl;
  return 0;
}
