#include<iostream>
using namespace std;
class randomnumbernsorting {
  int n, i, j, min, temp, a[1000], b[1000];
  public:
        void input_length() {
          cout<<"Enter the size of the array: ";
          cin>>n;
        }
        
        void input_array() {
          time_t t1;
          srand((unsigned) time(&t1));
          for(i=0; i<n; i++) {
            b[i]=rand()%1000;
          }
        }
        
        void copy_array() {
          for(i=0; i<n; i++) {
            a[i]=b[i];
          }
        }
        
        int insertion() {
          int count=0;
          for(i=0; i<n; i++) {
            temp=a[i];
            j=i-1;
            while(j>=0 && a[j]>temp) {
              count++;
              a[j+1]=a[j];
              j--;
            }
            a[j+1]=temp;
         }
         return count;
       }
       
       int selection() {
        int count=0;
        for(i=0; i<n-1; i++) {
          min=i;
          for(j=i+1; j<n; j++) {
            count++;
            if(a[j]<a[min]) {
              min=j;
            }
          }
          if(min!=i) {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
          }
        }
        return count;
      }
      
      int bubble() {
        int count=0;
        for(i=0; i<n-1; i++) {
          for(j=0; j<n-i-1; j++) {
            count++;
            if(a[j]>a[j+1]) {
              temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;
            }
          }
        }
        return count;
      }
      
      void display() {
        for(i=0; i<n; i++) {
          cout<<a[i]<<" ";
        }
        cout<<endl;
      }
};

int main() {
  randomnumbernsorting ob;
  ob.input_length();
  ob.input_array();
  ob.copy_array();
  ob.display();
  
  int bubbleCount=ob.bubble();
  
  ob.copy_array();
  ob.display();
  int selectionCount=ob.selection();
  
  ob.copy_array();
  ob.display();
  int insertionCount=ob.insertion();
  
  cout<<endl<<"Number of Comparisons in Bubble Sort: "<<bubbleCount;
  cout<<endl<<"Number of Comparisons in Selection Sort: "<<selectionCount;
  cout<<endl<<"Number of Comparisons in Insertion Sort: "<<insertionCount;
  
  return 0;
}
              
          
            
