#include <iostream>
using namespace std;
class sorting
{
  int n, arr[30];
  public:
        void input_length()
        {
          cout<<"Enter the size of the array: ";
          cin>>n;
        }
        void input_array()
        {
          cout<<"Enter the elements of the array: "<<endl;
          for(int i=0; i<n; i++)
          {
            cout<<"arr["<<i<<"]= ";
            cin>>arr[i];
          }
        }
        void insertion()
        {
          for(int i=0; i<n; i++)
          {
            int temp=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>temp)
            {
              arr[j+1]=arr[j];
              j--;
            }
            arr[j+1]=temp;
          }
        }
        void selection()
        {
          for(int i=0; i<n-1; i++)
          {
            int min=i;
            for(int j=i+1; j<n; j++)
            {
              if(arr[j]<arr[min])
              {
                min=j;
              }
            }
            if(min!=i)
            {
              int temp=arr[i];
              arr[i]=arr[min];
              arr[min]=temp;
            }
          }
        }
        void bubble()
        {
          for(int i=0; i<n-1; i++)
          {
            for(int j=0; j<n-i-1; j++)
            {
              if(arr[j]>arr[j+1])
              {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
              }
            }
          }
        }
        void display()
        {
          for(int i=0; i<n; i++)
          {
            cout<<arr[i]<<" ";
          }
        }
};

int main()
{
  int choice;
  sorting ob;
  ob.input_length();
  ob.input_array();
  while(1)
  {
    cout<<endl<<"Enter 1 for insertion sort"<<endl;
    cout<<"Enter 2 for selection sort"<<endl;
    cout<<"Enter 3 for bubble sort"<<endl;
    cout<<"Enter 4 for display"<<endl;
    cout<<"Enter 5 for exit from the program"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
      case 1: ob.bubble();
              cout<<"Array after sorting:"<<endl;
              ob.display();
              break;
              
      case 2: ob.selection();
              cout<<"Array after sorting:"<<endl;
              ob.display();
              break;
              
      case 3: ob.bubble();
              cout<<"Array after sorting:"<<endl;
              ob.display();
              break;
              
      case 4: ob.display();
              break;
              
      case 5: cout<<endl<<"END OF THE PROGRAM."<<endl;
              break;
              
      default: cout<<"WRONG CHOICE!"<<endl;
               break;
    }
    if(choice==5)
      break;
  }
  return 0;
}
