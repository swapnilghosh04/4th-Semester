#include<iostream>
#include <cstring>
using namespace std;
void naiveFindPatrn(char* mainString, char* pattern, int
array[], int *index) {
int patLen = strlen(pattern);
int strLen = strlen(mainString);
for(int i = 0; i<=(strLen - patLen); i++) {
int j;
for(j = 0; j<patLen; j++) {
if(mainString[i+j] != pattern[j])
break;
}
if(j == patLen) {
(*index)++;
array[(*index)] = i;
}
}
}
int main() {
int mainStringLength, patternLength;
cout << "Enter the length of the text: ";
cin >> mainStringLength;
cout << "Enter the length of the pattern: ";
cin >> patternLength;
char* mainString = new char[mainStringLength + 1];
char* pattern = new char[patternLength + 1];
cout << "Enter the text: ";
cin.ignore();
cin.getline(mainString, mainStringLength + 1);
cout << "Enter the pattern: ";
cin.getline(pattern, patternLength + 1);
int locArray[mainStringLength];
int index = -1;
naiveFindPatrn(mainString, pattern, locArray, &index);
for(int i = 0; i <= index; i++) {
cout << "Pattern found at position: " << locArray[i]<< endl;
}
return 0;
}
