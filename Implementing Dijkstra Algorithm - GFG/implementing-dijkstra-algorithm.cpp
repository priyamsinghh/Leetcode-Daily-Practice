//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>>pq;
        vector<int> dist(V);
        for(int i=0;i<V;i++)
            dist[i] = 1e9;
        dist[S] = 0;
        pq.insert({0,S});
        while(!pq.empty())
        {
            auto it = *(pq.begin()); //value at set top i.e. smaller value 
            int node = it.second;
            int dis = it.first;
            pq.erase(it);
            
            for(auto it : adj[node])
            {
                int edWt = it[1];
                int adjNode = it[0];
                
                if(dis + edWt < dist[adjNode])
                {
                    if(dist[adjNode] != 1e9)
                    {
                        pq.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode] = dis + edWt;
                    pq.insert({dist[adjNode],adjNode});
                }                    
            }
            
        }
        return dist;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends