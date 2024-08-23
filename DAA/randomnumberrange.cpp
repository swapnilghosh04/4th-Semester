#include<iostream>
using namespace std;
#include<stdlib.h>

int main() {
  int a;
  time_t t1;
  srand((unsigned) time(&t1));
  a=(rand()%101)+100;
  cout<<a<<endl;
  return 0;
}
