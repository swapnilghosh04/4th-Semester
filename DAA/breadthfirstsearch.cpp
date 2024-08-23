#include <iostream>
using namespace std;
int i, n, adj[100][100], visited[100], queue[100], j, front=-1, rear=-1;

void bfs(int v) {
  for(i=1; i<=n; i++) {
    if(adj[v][i] && !visited[i])
      queue[++rear]=i;
  }
  if(front<=rear) {
    visited[queue[front]]=1;
    queue[front++];
  }
}


int main() {
  int v;
  cout<<"Enter the number of vertices: ";
  cin>>n;
  for(i=0; i<=n; i++) {
    queue[i]=0;
    visited[i]=0;
  }
  cout<<"Enter the graph data in matrix form: "<<endl;
  for(i=1; i<=n; i++) {
    for(j=1; j<=n; j++) {
      cin>>adj[i][j];
    }
  }
  cout<<"Enter the starting vertex: ";
  cin>>v;
  bfs(v);
  cout<<"The nodes which are reachable are: ";
  for(i=1; i<=n; i++) {
    if(visited[i])
      cout<<i;
    else
      cout<<"BFS is not possible. Not all nodes are reachable.";
  }
  return 0;
}
  
  
