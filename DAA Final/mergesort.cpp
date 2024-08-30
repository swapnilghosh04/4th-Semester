#include <iostream>
using namespace std;

void split_merge(int a[], int low, int mid, int high) {
  int b[100], c[100];
  for(int j=low, l=0; j<=mid; j++, l++) {
    b[l]=a[j];
  }
  for(int k=mid+1, l=0; k<=high; k++, l++) {
    c[l]=a[k];
  }
  
  int l=0, r=0;
  int x=low;
  while(l<(mid-low+1) && r<(high-mid)) {
    if(b[l]<c[r]) {
      a[x]=b[l];
      x++;
      l++;
    } else {
        a[x]=c[r];
        x++;
        r++;
      }
  }
  while(l<(mid-low+1)) {
    a[x]=b[l];
    x++;
    l++;
  }
  while(r<(high-mid)) {
    a[x]=c[r];
    x++;
    r++;
  }
}

void merge_sort(int a[], int low, int high) {
  if(low<high) {
    int mid=(low+high)/2;
    merge_sort(a, low, mid);
    merge_sort(a, mid+1, high);
    split_merge(a, low, mid, high);
  }
}

int main() {
  int a[100], n;
  cout<<"Enter the size of the array: ";
  cin>>n;
  cout<<"Enter the array elements: "<<endl;
  for(int i=0; i<n; i++) {
    cout<<"a["<<i<<"] = ";
    cin>>a[i];
  }
  merge_sort(a, 0, 9);
  cout<<"The sorted array is: "<<endl;
  for(int i=0; i<n; i++) {
    cout<<a[i]<<" ";
  }
  cout<<endl;
  return 0;
}
