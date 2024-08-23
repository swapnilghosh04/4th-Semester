#include <iostream>
using namespace std;
int n, i, j, cost[100][100], ne=1, a, u, b, v, mincost=0, parent[100];
int find(int);
int uni(int, int);

int find(int i) {
  while(parent[i])
    i=parent[i];
  return i;
}
int uni(int i, int j) {
  if(i!=j) {
    parent[j]=i;
    return i;
  }
  return 0;
}

int main() {
  int min;
  cout<<"IMPLEMENTATION OF KRUSKAL'S ALGORITHM"<<endl;
  cout<<"Enter the number of vertices: ";
  cin>>n;
  cout<<"Enter the values of the cost adjacency matrix: ";
  for(i=1; i<=n; i++) {
    for(j=1; j<=n; j++) {
      cin>>cost[i][j];
      if(cost[i][j]==0)
        cost[i][j]=999;
    }
  }
  
  cout<<"The edges of Minimum Cost Spanning Tree are: "<<endl;
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
      cout<<ne++<<" edge ("<<a<<", "<<b<<") = "<<min;
      mincost+=min;
    }
    cost[a][b]=cost[b][a]=999;
 }
 cout<<"Minimum Cost = "<<mincost;
 return 0;
}
