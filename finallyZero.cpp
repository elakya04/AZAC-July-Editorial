/*You can get a detailed explanation here
https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/editorial/
*/
// DFS Traversal.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    // Whenever A City With Positive Value Is Encountered.
    // Edge Needs To Be Reversed.

    void reverseEdge(int curr, vector<vector<int>> &adj, int &count, vector<bool> &vis) {
        
        // Base Case.
        if (vis[curr] == true) return;

        // Mark Current City As Visited.
        vis[curr] = true;

        for (auto neighborCity : adj[curr]) {

            // Reversing The Edge In Case Of Adjacent City With Positive Value.
            // City With Positive Value Implies There Is An Edge To Current City (Not From Current City).

            if (vis[abs(neighborCity)] == false) 
                if (neighborCity > 0) count++;
            
            // Recursive Call For The Neighboring City.
            reverseEdge(abs(neighborCity), adj, count, vis);
        }
    }

    int minReorder(int n, vector<vector<int>> &connections) {
        
        vector<vector<int>> adj (n);
        vector<bool> vis (n, false);

        for (int i = 0; i < connections.size(); ++i) {

            int u = connections[i][0]; // Source City.
            int v = connections[i][1]; // Destination City.

            // Modification To Standard Approach.
            // In Adjacency List Of Destination City, Append Negative Value Of Source City.

            adj[u].push_back(v);
            adj[v].push_back(-u);
        }

        int count = 0;
        
        // Start DFS Traversal From Capital City.
        reverseEdge(0, adj, count, vis);

        return count;
    }
};