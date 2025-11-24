#include <bits/stdc++.h>
using namespace std;

#define INF 999
#define N 10

int findMinNode(int dist[N],int visited[N],int nodes){
    int minDist = INF, nextNode = -1;
    for(int i=0;i<nodes;i++){
        if(!visited[i] && dist[i] < minDist){
            minDist = dist[i];
            nextNode = i;
        }
    }

    return nextNode;
}

void dijkstra(int cost[N][N],int dist[N],int visited[N],int nodes,int source){
    for(int i=0;i<nodes;i++){
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for(int count=1;count < nodes - 1;count++){
        int nextNode = findMinNode(dist,visited,nodes);
        if (nextNode == -1) break;
        visited[nextNode] = 1;

        for(int i=0;i<nodes;i++){
            if(!visited[i] && dist[nextNode] + cost[nextNode][i] < dist[i])
                dist[i] = dist[nextNode] + cost[nextNode][i];
        }
    }
}

int main()
{
    int cost[N][N], dist[N], visited[N];
    int nodes,source;

    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter cost matrix: \n";
    for(int i=0;i<nodes;i++)
        for(int j=0;j<nodes;j++)
            cin >> cost[i][j];
    
    cout << "Enter source node (1 to " << nodes << "): ";
    cin >> source;
    source--;

    dijkstra(cost,dist,visited,nodes,source);

    cout << "\nShortest path from node " << source + 1 << ":\n";
    for(int i=0;i<nodes;i++)
        cout << "To node " << i + 1 << " = " << dist[i] << endl;

    return 0;
}