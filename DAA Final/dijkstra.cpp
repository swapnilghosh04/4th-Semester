#include <bits/stdc++.h>
using namespace std;
#define INF 999

int n, cost[100][100], v, i, j;
bool visited[100]={0};
int parent[100], dist[100];

void init() {
  for(int i=0; i<n; i++) {
    parent[i]=i;
    dist[i]=INF;
  }
  dist[v]=0;
}

int getNearest() {
  int minvalue=INF;
  int minnode=0;
  for(int i=0; i<n; i++) {
    if(!visited[i] && dist[i]<minvalue) {
      minvalue=dist[i];
      minnode=i;
    }
  }
  return minnode;
}
     
void dijkstra() {
  for(int i=0; i<n; i++) {
    int nearest=getNearest();
    visited[nearest]=true;
    
    for(int adj=0; adj<n; adj++) {
      if(cost[nearest][adj]!=INF && dist[adj]>dist[nearest]+cost[nearest][adj]) {
        dist[adj]=dist[nearest]+cost[nearest][adj];
        parent[adj]=nearest;
      }
    }
  }
}

void display() {
  cout<<"Node:\t\t\tCost:\t\t\tPath: "<<endl;
  for(int i=0; i<n; i++) {
    cout<<i<<"\t\t\t"<<dist[i]<<"\t\t\t"<<" ";
    cout<<i<<" ";
    int parnode=parent[i];
    
    while(parnode!=v) {
      cout<<" <- "<<parnode<<" ";
      parnode=parent[parnode];
    }
    cout<<endl;
  }
}

int main() {
  cout<<"Enter the number of vertices: ";
  cin>>n;
  cout<<"Enter the values of cost adjacency matrix: "<<endl;
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      cin>>cost[i][j];
    }
  }
  cout<<"Enter the starting node: ";
  cin>>v;
  init();
  dijkstra();
  display();
  return 0;
}
  
  
