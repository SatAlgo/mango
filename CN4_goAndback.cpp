#include <bits/stdc++.h>
using namespace std;

void goBackNARQ(int totalFrames,int windowSize){
    srand(time(0));
    int sent = 0;

    cout << "\n --- Go-Back-N ARQ Simulation ---\n";
    while(sent < totalFrames){
        int windowEnd = min(sent+windowSize,totalFrames);

        cout << "Sender: Sending frames " << sent << " to " << windowEnd - 1 << endl;

        int errorFrame = rand() % windowSize;
        bool error = rand() % 2 ;

        if(error && sent + errorFrame < totalFrames){
            cout << "Receiver: Error in Frame " << sent + errorFrame << endl;
            cout << "Sender: Timeout! Resending from Frame " << sent + errorFrame << "\n\n";
            sent = sent + errorFrame;
        } else{
            cout << "Receiver: All frames received successfully.\n";
            sent = windowEnd;
        }
    }
    cout << endl;
    cout << "All frames sent sucessfully!\n";
}

int main()
{
    int n,w;
    cout << "Enter total number of frames: ";
    cin >> n;

    cout << "Enter window size: ";
    cin >> w;

    goBackNARQ(n,w);
    return 0;
}