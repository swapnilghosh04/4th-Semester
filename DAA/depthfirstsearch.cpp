#include <iostream>
using namespace std;
int n, i, j, cost[100][100], v, visited[100], k, visit[100], top, stk[100];
int main() {
  int m;
  cout<<"Enter the number of vertices: ";
  cin>>n;
  cout<<"Enter the number of edges: ";
  cin>>m;
  cout<<endl<<"EDGES: "<<endl;
  for(k=1; k<m; k++) {
    cin>>i>>j;
    cost[i][j]=1;
  }
  cout<<"Enter initial vertex to traverse from: ";
  cin>>v;
  cout<<"DFS order of visited vertices: ";
  cout<<v<<" ";
  visited[v]=1;
  k=1;
  while(k<n) {
    for(j=n; j>=1; j--)
      if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1) {
        visit[j]=1;
        stk[top]=j;
        top++;
      }
      v=stk[--top];
      cout<<v<<" ";
      k++;
      visit[v]=0;
      visited[v]=1;
  }
  return 0;
}
