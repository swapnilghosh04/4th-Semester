#include <iostream>
#include <cstring>
using namespace std;

void prefixSuffixArray(char* pat, int M, int* pps) {
    int length = 0;
    pps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[length]) {
            length++;
            pps[i] = length;
            i++;
        } else {
            if (length != 0)
                length = pps[length - 1];
            else {
                pps[i] = 0;
                i++;
            }
        }
    }
}

void KMPAlgorithm(char* text, char* pattern) {
    int M = strlen(pattern);
    int N = strlen(text);
    int* pps = new int[M];
    prefixSuffixArray(pattern, M, pps);
    int i = 0;
    int j = 0;
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        if (j == M) {
            cout << "Found pattern at index " << i - j << endl;
            j = pps[j - 1];
        }
        else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = pps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    int textLength, patternLength;
    cout << "Enter the length of the text: ";
    cin >> textLength;
    cout << "Enter the length of the pattern: ";
    cin >> patternLength;

    char* text = new char[textLength + 1];
    char* pattern = new char[patternLength + 1];

    cout << "Enter the text: ";
    cin.ignore();
    cin.getline(text, textLength + 1);

    cout << "Enter the pattern: ";
    cin.getline(pattern, patternLength + 1);

    cout << "The pattern is found in the text at the following index(s):\n";
    KMPAlgorithm(text, pattern);

    return 0;
}

