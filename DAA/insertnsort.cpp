#include<iostream>
using namespace std;
class insertnsort {
  int n, i, temp, j, k, a[1000];
  public:
        void input_length() {
          cout<<"Enter the size of the array: ";
          cin>>n;
        }
        
        void insert_n_sort() {
          for(i=0; i<n; i++) {
            cout<<"Enter a value: ";
            cin>>temp;
            j=i-1;
            while(j>=0 && a[j]>temp) {
              a[j+1]=a[j];
              j--;
            }
            a[j+1]=temp;
          
          for(k=0; k<=i; k++) {
            cout<<a[k]<<" ";
          }
          cout<<endl;
         }
       }
};

int main() {
  insertnsort ob;
  ob.input_length();
  ob.insert_n_sort();
  return 0;
}
