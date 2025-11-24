#include <bits/stdc++.h>
using namespace std;

int main()
{
    string data;
    cout << "Enter the binary data: ";
    cin >> data;

    int cnt1 = 0;
    for(char i : data) if(i == '1') cnt1++;

    string trans_data = data + ((cnt1 % 2 == 0) ? "0" : "1");

    cout << "Data to send: " << trans_data << endl;

    string received_data;
    cout << "\nEnter received data: ";
    cin >> received_data;

    cnt1 = 0;

    for(char i: received_data) if(i == '1') cnt1++;

    if(cnt1 % 2 == 0)
        cout << "\nNo error detected" << endl;
    else 
        cout << "\nError detected" << endl;

    return 0;
}