#include <iostream>
#include <string>
using namespace std;

string xor1(string a, string b) {
    string result = "";
    for (int i = 0; i < b.size(); i++)
        result += (a[i] == b[i]) ? '0' : '1';
    return result;
}

string mod2div(string dividend, string divisor) {
    int pick = divisor.size();
    string tmp = dividend.substr(0, pick);
    int n = dividend.size();

    while (pick < n) {
        if (tmp[0] == '1')
            tmp = xor1(divisor, tmp).substr(1) + dividend[pick];
        else
            tmp = xor1(string(divisor.size(), '0'), tmp).substr(1) + dividend[pick];
        pick++;
    }

    if (tmp[0] == '1')
        tmp = xor1(divisor, tmp).substr(1);
    else
        tmp = xor1(string(divisor.size(), '0'), tmp).substr(1);

    return tmp;
}

int main() {
    string data, key;
    cout << "Enter data: ";
    cin >> data;
    cout << "Enter generator (key): ";
    cin >> key;

    int keylen = key.size();
    string appended_data = data + string(keylen - 1, '0');
    string remainder = mod2div(appended_data, key);
    string codeword = data + remainder;

    cout << "Transmitted Codeword: " << codeword << endl;

    string received;
    cout << "Enter received codeword: ";
    cin >> received;

    string check = mod2div(received, key);
    if (check.find('1') != string::npos)
        cout << "Error detected in received data." << endl;
    else
        cout << "No error detected." << endl;

    return 0;
}


// Enter data: 1101
// Enter generator: 1011
// Transmitted Codeword: 1101001
// Enter received codeword: 1101001
// No error detected.
