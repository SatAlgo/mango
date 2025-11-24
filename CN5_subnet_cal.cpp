#include <bits/stdc++.h>
using namespace std;

vector<int> splitIP(string ip) {
    vector<int> parts;
    string num = "";

    for (char c : ip) {
        if (c == '.') {
            parts.push_back(stoi(num));
            num = "";
        } else {
            num += c;
        }
    }
    parts.push_back(stoi(num));
    return parts;
}

unsigned long ipToLong(vector<int>ip){
    unsigned long result = 0;
    for(int i=0;i<4;i++)
        result = (result << 8) + ip[i];
    return result;
}

string longToIP(unsigned long ip){
    string result = "";
    for(int i=3;i>=0;i--){
        result += to_string((ip >> (8 * i)) & 255);
        if(i != 0){
            result += '.';
        }
    }
    return result;
}

string getWildcard(int cidr) {
    int mask = 0xFFFFFFFF << (32 - cidr);
    unsigned long wildcard = (~mask) & 0xFFFFFFFF;
    return longToIP(wildcard);
}

int main()
{
    string ipInput, subnetInput;
    cout << "Enter IP address: ";
    cin >> ipInput;

    cout << "Enter subnet mask: ";
    cin >> subnetInput;

    vector<int> ip = splitIP(ipInput);
    unsigned long ipLong = ipToLong(ip);

    int cidr = 0;
    unsigned long maskLong = 0;

    if(subnetInput[0] == '/'){
        cidr = stoi(subnetInput.substr(1));
        maskLong = 0xFFFFFFFF << (32 - cidr);
    }else{
        vector<int>mask = splitIP(subnetInput);
        maskLong = ipToLong(mask);
        unsigned long temp = maskLong;
        while(temp & 0x80000000){
            cidr++;
            temp <<= 1;
        }
    }

    unsigned long network = ipLong & maskLong;
    unsigned long broadcast = network | (~maskLong);
    unsigned long firstHost = network + 1;
    unsigned long lastHost = broadcast - 1;
    unsigned long totalHosts = pow(2,32-cidr) - 2;

    cout << "\n--- Subnet Calculation Results ---\n";
    cout << "IP Address               : " << ipInput << endl;
    cout << "Subnet Mask              : " << longToIP(maskLong) << endl;
    cout << "Wildcard Mask            : " << getWildcard(cidr) << endl;
    cout << "Network Address          : " << longToIP(network) << endl;
    cout << "Boradcast Address        : " << longToIP(broadcast) << endl;
    cout << "First Host Address       : " << longToIP(firstHost) << endl;
    cout << "Last Host Address        : " << longToIP(lastHost) << endl;
    cout << "CIDR Notation            : " << cidr << endl;
    return 0;
}