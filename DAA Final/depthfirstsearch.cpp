#include <iostream>
using namespace std;
#include <stdlib.h>
int n, m, k, i, j, cost[100][100], v, visited[100], visit[100], stk[100], top=-1;

int main() {
  cout<<"Enter the number of vertices: ";
  cin>>n;
  cout<<"Enter the number of edges: ";
  cin>>m;
  cout<<"-----------EDGES------------"<<endl;
  for(k=1; k<=m; k++) {
    cin>>i>>j;
    cost[i][j]=1;
  }
  
  cout<<"Enter the initial vertex to traverse from: ";
  cin>>v;
  cout<<"--------DFS ORDER OF VISITED VERTICES--------"<<endl;
  cout<<v<<" ";
  visited[v]=1;
  k=1;
  while(k<n) {
    for(j=n; j>=1; j--) {
      if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1) {
        visit[j]=1;
        stk[top]=j;
        top++;
      }
    }
    v=stk[--top];
    cout<<v<<" ";
    k++;
    visit[v]=0;
    visited[v]=1;
  }
  cout<<endl;
  return 0;
}
