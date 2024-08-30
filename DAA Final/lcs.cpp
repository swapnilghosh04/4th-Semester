#include <iostream>
using namespace std;

class LCS {
  public:
         string LCS_length(string X, string Y) {
            int m=X.length(), n=Y.length(), i, j;
            int** c=new int*[n+1];
            char** b=new char*[n];
            for(i=0; i<n; i++) {
              b[i]=new char[m];
            }
            for(i=0; i<(n+1); i++) {
              c[i]=new int[m+1];
            }
            for(i=0; i<=n; i++) {
              c[i][0]=0;
            }
            for(i=0; i<=m; i++) {
              c[0][i]=0;
            }
            
            for(i=1; i<=n; i++) {
              for(j=1; j<=m; j++) {
                if(Y.at(i-1)==X.at(j-1)) {
                  c[i][j]=c[i-1][j-1]+1;
                  b[i-1][j-1]='d';
                } else if(c[i-1][j]>=c[i][j-1]) {
                    c[i][j]=c[i-1][j];
                    b[i-1][j-1]='u';
                  } else {
                      c[i][j]=c[i][j-1];
                      b[i-1][j-1]='l';
                    }
              }
            }
            return print_LCS(b, X, (n-1), (m-1));
        }
        
        string print_LCS(char* b[], string X, int i, int j) {
            if((i==-1) || (j==-1))
              return"";
            else if(b[i][j]=='d')
              return print_LCS(b, X, (i-1), (j-1))+X.at(j);
            else if(b[i][j]=='u')
              return print_LCS(b, X, (i-1), j);
            else
              return print_LCS(b, X, i, (j-1));
        }
};

int main() {
  LCS ob;
  string A, B, lcs;
  cout<<"Enter the first string: ";
  cin>>A;
  cout<<"Enter the second string: ";
  cin>>B;
  lcs=ob.LCS_length(A, B);
  cout<<"LCS is: "<<lcs<<endl;
  return 0;
}

