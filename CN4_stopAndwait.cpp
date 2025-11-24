#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void stopAndWaitARQ(int totalFrames){
    srand(time(0));
    int frame = 0;

    cout << "\n --- Stop and Wait ARQ Simulation ---\n";
    while (frame < totalFrames) {
        cout << "Sender: Sending frame " << frame << endl;
        int ack = rand() % 2;
        if(ack){
            cout << "Receiver: Frame " << frame << " received. Sending ACK.\n";
            cout << "Sender: ACK received for Frame " << frame << "\n\n";
            frame++;
        }
        else {
            cout << "Receiver: Frame " << frame << " lost a ACK not received.\n";
            cout << "Sender: Timeout! Resending Frame " << frame << "\n\n";
        }
    }

    cout << "All frames send successfully!\n";
}

int main()
{
    int n;
    cout << "Enter total number of frames: ";
    cin >> n;
    stopAndWaitARQ(n);
    return 0;
}