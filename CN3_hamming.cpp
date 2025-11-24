#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cout << "Enter number of data bits: ";
    cin >> m;

    int data[20],code[50];

    cout << "Enter data bits: ";
    for(int i = 0; i < m;i++)
        cin >> data[i];

    int r = 0;
    while ( (1 << r) < (m + r + 1)) r++;
    int n = m + r;

    int j = 0;
    for(int i=1;i<=n;i++){
        if((i & (i-1)) == 0) code[i] = 0;
        else code[i] = data[j++];
    }

    for(int i=0;i<r;i++){
        int parityPos = (1 << i);
        int parity = 0;
        for(int k = 1;k<=n;k++)
            if(k & parityPos) parity ^= code[k];
        code[parityPos] = parity;
    }

    cout << "\nEncoded Hamming Codeword: ";
    for(int i=1;i<=n;i++) cout << code[i] << " ";
    cout << endl;

    int received[50];
    cout << "\nEnter the received codeword: ";
    for(int i=1;i<=n;i++) cin>>received[i];

    int errorPos = 0;
    for(int i=0;i<r;i++){
        int parityPos = (1 << i);
        int parity = 0;
        for(int k=1;k<=n;k++)
            if(k & parityPos) parity ^= received[k];
        if(parity != 0) errorPos += parityPos;
    }

    if(errorPos == 0)
        cout << "No error detected.\n";
    else {
        cout << "Error detected at position: " << errorPos << endl;
        cout << "Corrected Codeword: ";
        for(int i=1;i<=n;i++) cout << code[i] << " ";
        cout << endl;
    }

    return 0;
}