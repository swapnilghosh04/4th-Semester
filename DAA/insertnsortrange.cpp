#include <iostream>
using namespace std;
class insertnsortrange {
  int n, a[1000], i, j, x, temp;
  public:
        void insert_n_sort_range() {
          int count=0;
          for(x=1; x<=100; x++) {
            n=rand()%(1000-30+1)+30;
            for(i=0; i<n; i++) {
              a[i]=rand()%100;
              temp=a[i];
              j=i-1;
              while(j>=0 && a[j]>temp) {
                count=count+2;
                a[j+1]=a[j];
                j--;
              }
              a[j+1]=temp;
            }
            
            cout<<"size="<<x<<" n="<<n<<" Comparison="<<count<<endl;
         }
        }
};

int main() {
  insertnsortrange ob;
  ob.insert_n_sort_range();
  return 0;
}
          
