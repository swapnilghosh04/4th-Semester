#include <iostream>
using namespace std;
#include <stdlib.h>

int n,i, j, cost[100][100], ne=1, a, b, u, v, mincost=0, parent[100];

int find(int i) {
  while(parent[i]) {
    i=parent[i];
  }
  return i;
}

int uni(int i, int j) {
  if(i!=j) {
    parent[j]=i;
    return 1;
  } else {
      return 0;
    }
}

int main() {
  int min;
  cout<<"Enter the number of vertices: ";
  cin>>n;
  cout<<"Enter the values of cost adjacency matrix: "<<endl;
  for(i=1; i<=n; i++) {
    for(j=1; j<=n; j++) {
      cin>>cost[i][j];
      if(cost[i][j]==0)
        cost[i][j]=999;
    }
  }
  while(ne<n) {
    for(i=1, min=999; i<=n; i++) {
      for(j=1; j<=n; j++) {
        if(cost[i][j]<min) {
          min=cost[i][j];
          a=u=i;
          b=v=j;
        }
      }
    }
    u=find(u);
    v=find(v);
    if(uni(u,v)) {
      cout<<ne++<<" edge "<<"("<<a<<","<<b<<") = "<<min<<endl;
      mincost+=min;
    }
    cost[a][b]=cost[b][a]=999;
  }
  cout<<"Minimum cost = "<<mincost<<endl;
  return 0;
}
