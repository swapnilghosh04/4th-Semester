#include <iostream>
using namespace std;

int main() {
  int i, j, k, cost[100][100], n;
  cout<<"Enter the total number of vertices: ";
  cin>>n;
  cout<<"Enter the data in cost adjacency matrix: "<<endl;
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      cin>>cost[i][j];
    }
  }
  
  for(k=0; k<n; k++) {
    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        if(cost[i][j]>cost[i][k]+cost[k][j])
          cost[i][j]=cost[i][k]+cost[k][j];
      }
    }
    
    cout<<"The data of cost adjacency matrix is: "<<endl;
    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        cout<<cost[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}
