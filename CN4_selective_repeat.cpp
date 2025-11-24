#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void selectiveRepeatARQ(int totalFrames, int windowSize) {
    vector<bool> ack(totalFrames, false);
    int sent = 0;

    cout << "\n--- Selective Repeat ARQ Simulation ---\n";

    while (sent < totalFrames) {
        cout << "Sender: Sending window frames " << sent 
             << " to " << min(sent + windowSize, totalFrames) - 1 << endl;

        for (int i = sent; i < min(sent + windowSize, totalFrames); i++) {
            if (!ack[i]) {
                int error = rand() % 4; 
                if (error == 0) {
                    cout << "Receiver: Frame " << i << " lost!\n";
                } else {
                    cout << "Receiver: Frame " << i << " received. Sending ACK.\n";
                    ack[i] = true;
                }
            }
        }

        bool anyPending = false;
        for (int i = sent; i < min(sent + windowSize, totalFrames); i++) {
            if (!ack[i]) {
                anyPending = true;
                cout << "Sender: Retransmitting Frame " << i << endl;
            }
        }

        // Slide window only for continuous ACKed frames
        while (sent < totalFrames && ack[sent]) sent++;

        if (!anyPending)
            cout << "Sender: Sliding window...\n\n";
        else
            cout << "Sender: Waiting for ACKs...\n\n";
    }

    cout << "All frames sent successfully!\n";
}

int main() {
    srand(time(0)); 

    int n, w;
    cout << "Enter total number of frames: ";
    cin >> n;
    cout << "Enter window size: ";
    cin >> w;

    selectiveRepeatARQ(n, w);
    return 0;
}
