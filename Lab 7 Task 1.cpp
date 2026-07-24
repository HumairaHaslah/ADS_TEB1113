#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <functional>

using namespace std;

// Dijkstra Algorithm
vector<int> dijkstra(vector<vector<pair<int,int> > > &adj, int src)
{
    int V = adj.size();

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while(!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u])
            continue;

        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main()
{
    // City names
    vector<string> city;

    city.push_back("Kuala Lumpur");
    city.push_back("Ipoh");
    city.push_back("Penang");
    city.push_back("Melaka");
    city.push_back("Johor Bahru");

    int V = 5;

    vector<vector<pair<int,int> > > adj(V);

    // Road connections (distance in KM)
 
    adj[0].push_back(make_pair(1,120));   // KL -> Ipoh
    adj[0].push_back(make_pair(2,200));   // KL -> Penang

    adj[1].push_back(make_pair(0,120));   // Ipoh -> KL
    adj[1].push_back(make_pair(2,90));    // Ipoh -> Penang
    adj[1].push_back(make_pair(4,180));   // Ipoh -> JB

    adj[2].push_back(make_pair(0,200));   // Penang -> KL
    adj[2].push_back(make_pair(1,90));    // Penang -> Ipoh
    adj[2].push_back(make_pair(3,80));    // Penang -> Melaka

    adj[3].push_back(make_pair(2,80));    // Melaka -> Penang
    adj[3].push_back(make_pair(4,250));   // Melaka -> JB

    adj[4].push_back(make_pair(1,180));   // JB -> Ipoh
    adj[4].push_back(make_pair(3,250));   // JB -> Melaka

    int src = 0;   // Kuala Lumpur (src : source)

    vector<int> shortest = dijkstra(adj, src);

    cout << "Shortest Distance from " << city[src] << endl << endl;

    // Display
    for(int i = 0; i < V; i++)
    {
        cout << city[src] << " -> " << city[i] << " = " << shortest[i] << " km" << endl;
    }

    return 0;
}
