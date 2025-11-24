#include <bits/stdc++.h>
using namespace std;

#define INF 999
#define N 10

void distanceVector(int dist[N][N],int via[N][N],int nodes){
    for(int k=0;k<nodes;k++){
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    via[i][j] = via[i][k];
                }
            }
        }
    }
}

int main()
{
    int cost[N][N], dist[N][N], via[N][N];
    int nodes;

    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter cost matrix: " << endl;
    for(int i=0;i<nodes;i++)
        for(int j=0;j<nodes;j++)
            cin >> cost[i][j];
    
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            dist[i][j] = cost[i][j];
            via[i][j] = j;
        }
    }

    distanceVector(dist,via,nodes);

    cout << endl;
    cout << "Final Distance Vector Table: " << endl;
    for(int i=0;i<nodes;i++){
        cout << endl;
        cout << "Router " << i + 1 << ":" << endl;
        cout << "Dest\tNextHop\tDistance\n";
        for(int j=0;j<nodes;j++)
            cout << j + 1 << "\t" << via[i][j] + 1 << "\t" << dist[i][j] << endl;
    }

    return 0;
}