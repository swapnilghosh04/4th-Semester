#include <iostream>
using namespace std;

class CountingSort {
  public:
         void counting_sort(int input[], int length) {
            int min=99999, max=-99999;
            for(int i=0; i<length; i++) {
              if(max<input[i])
                max=input[i];
              if(min>input[i])
                min=input[i];
            }
            
            int countingarraylength=max-min+1;
            int countingarray[countingarraylength], sorted[length];
            for(int i=0; i<countingarraylength; i++) {
              countingarray[i]=0;
            }
            
            for(int i=0; i<length; i++) {
              countingarray[input[i]-min]++;
            }
            
            for(int i=1; i<countingarraylength; i++) {
              countingarray[i]=countingarray[i]+countingarray[i-1];
            }
            
            for(int i=0; i<length; i++) {
              sorted[--countingarray[input[i]-min]]=input[i];
            }
            
            for(int i=0; i<length; i++) {
              input[i]=sorted[i];
            }
        }
        
        void display(int array[], int length) {
            cout<<"[";
            for(int i=0; i<length; i++) {
              cout<<array[i];
              if(i!=(length-1))
                cout<<", ";
            }
            cout<<"]"<<endl;
        }
};

int main() {
  int length;
  CountingSort ob;
  cout<<"Enter the number of elements: ";
  cin>>length;
  int *input=new int[length];
  cout<<"Enter the array elements:"<<endl;
  for(int i=0; i<length; i++) {
    cout<<"a["<<i<<"] = ";
    cin>>input[i];
  }
  
  cout<<"Input Array: ";
  ob.display(input, length);
  ob.counting_sort(input, length);
  cout<<"Output Array: ";
  ob.display(input, length);
  return 0;
}
