#include <iostream>

using namespace std;

typedef struct node {
  int data;
  struct node* link;
} NODE;

class RadixSortLinkedList {
public:
  void radixSortLinkedList(int a[], int n) {
    int i, j, k, r, step;
    display(a, n);
    NODE *p[10];
    cout << "size of NODE = " << sizeof(NODE) << endl;
    cout << "size of p = " << sizeof(p) << endl;
    cout << "p[0] = " << p[0] << endl;
    cout << "p[1] = " << p[1] << endl;
    cout << "p[2] = " << p[2] << endl;
    cout << "p[3] = " << p[3] << endl;
    cout << "p[4] = " << p[4] << endl;
    cout << "p[5] = " << p[5] << endl;
    cout << "p[6] = " << p[6] << endl;
    cout << "p[7] = " << p[7] << endl;
    cout << "p[8] = " << p[8] << endl;
    cout << "p[9] = " << p[9] << endl;
    cout << "p[0]->data = " << p[0]->data << endl;
    cout << "p[0]->link = " << p[0]->link << endl;
    for(i=0; i<10; i++) {
      p[i]->link=NULL;
      cout << "passed" << endl;
    }
    for(step=1; step<=3; step++) {
      for(i=0, j = 1; i<n; i++, j *= 10) {
        r=(a[i]/j)%10;
        NODE *temp=p[r];
        while(temp->link!=NULL) {
          temp=temp->link;
        }
        NODE *temp1=new node;
        temp1->data=a[i];
        temp1->link=NULL;
        temp->link=temp1;
      }
      for(i=0, k = 0; i<10; i++) {
        NODE *temp=p[i];
        while(temp!=NULL) {
          a[k++]=temp->data;
        }
      }
    }
    NODE *t = p[0];
    while(t!=NULL) {
      cout << t->data << ", ";
      t = t->link;
    }
  }

  void display(int a[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
      cout << a[i];
      if (i != (n - 1))
        cout << ", ";
    }
    cout << " ]" << endl;
  }
};

int main() {
  RadixSortLinkedList ob;
  int *array = new int[7];
  array[0] = 62;
  array[1] = 956;
  array[2] = 451;
  array[3] = 32;
  array[4] = 98;
  array[5] = 10;
  array[6] = 3;
  ob.radixSortLinkedList(array, 7);
  ob.display(array, 7);
  return 0;
}
