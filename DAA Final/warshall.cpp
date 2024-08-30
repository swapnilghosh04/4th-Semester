#include <iostream>
using namespace std;

int main() {
  int n, i, j, k, a[100][100];
  cout<<"Enter the number of vertices: ";
  cin>>n;
  cout<<"Enter the graph data in matrix form: "<<endl;
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      cin>>a[i][j];
    }
  }
  
  for(k=0; k<n; k++) {
    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        a[i][j]=a[i][j] || (a[i][k] && a[k][j]);
      }
    }
    
    cout<<"The data of adjacency matrix is: "<<endl;
    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        cout<<a[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}
