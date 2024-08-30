#include <iostream>
using namespace std;

int n, i, j, cost[100][100];

int min_key(int key[], bool visited[]) {
  int min=999, min_index;
  for(int v=0; v<n; v++) {
    if(visited[v]==false && key[v]<min) {
      min=key[v];
      min_index=v;
    }
  }
  return min_index;
}

void print_mst(int parent[]) {
  int mincost=0;
  cout<<"Edge\tWeight"<<endl;
  for(i=1; i<n; i++) {
    cout<<parent[i]<<"-"<<i<<"\t"<<cost[i][parent[i]]<<endl;
    mincost=mincost+cost[i][parent[i]];
  }
  cout<<"Total cost = "<<mincost<<endl;
}

void find_mst() {
  int parent[n], key[n];
  bool visited[n];
  for(i=0; i<n; i++) {
    key[i]=999;
    visited[i]=false;
    parent[i]=-1;
  }
  key[0]=0;
  parent[0]=-1;
  for(int x=0; x<n-1; x++){
    int u=min_key(key, visited);
    visited[u]=true;
    for(int v=0; v<n; v++) {
      if(cost[u][v]!=0 && visited[v]==false && cost[u][v]<key[v]) {
        parent[v]=u;
        key[v]=cost[u][v];
      }
    } 
  } 
  print_mst(parent);
}

int main() {
  cout<<"Enter the number of vertices of a graph: ";
  cin>>n;
  cout<<"Enter the values of cost adjacency matrix: "<<endl;
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      cin>>cost[i][j];
    }
  }
  find_mst();
  return 0;
}
