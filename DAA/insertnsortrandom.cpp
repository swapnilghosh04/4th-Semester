#include<iostream>
using namespace std;
#include<stdlib.h>
class insertnsortrandom {
  int n, i, temp, j, k, count=0, a[1000];
  public:
        void input_length() {
          cout<<"Enter the size of the array: ";
          cin>>n;
        }
        
        int insert_n_sort_random() {
          for(i=0; i<n; i++) {
            a[i]=rand();
            temp=a[i];
            count++;
            j=i-1;
            while(j>=0 && a[j]>temp) {
              count=count+2;
              a[j+1]=a[j];
              j--;
            }
            a[j+1]=temp;
            
            cout<<"Array after sorting: "<<endl;
            for(k=0; k<=i; k++) {
              cout<<a[k]<<" ";
            }
            cout<<endl;
          }
          return count;
        }
};

int main() {
  insertnsortrandom ob;
  ob.input_length();
  int insertCount=ob.insert_n_sort_random();
  cout<<"The number of comparisons are: "<<insertCount;
  
  return 0;
}
