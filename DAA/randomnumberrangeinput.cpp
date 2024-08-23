#include<iostream>
using namespace std;
#include<stdlib.h>

int main() {
  int a, l, h;
  time_t t1;
  srand((unsigned) time(&t1));
  cout<<"Enter the lower range: ";
  cin>>l;
  cout<<"Enter the higher range: ";
  cin>>h;
  a=(rand()%(h-l+1))+l;
  cout<<a<<endl;
  return 0;
}
