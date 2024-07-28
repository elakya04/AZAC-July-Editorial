#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<long> solution(long x, long n, vector<long> lights) 
{
    // Set to store the positions of traffic lights
    set<long> positions;
    // Multiset to store lengths of intervals
    multiset<long> intervals;

    // Initially, there is one interval of the whole street
    positions.insert(0);
    positions.insert(x);
    intervals.insert(x);

    vector<long> results(n);

    // Loop over each traffic light position
    for (long i = 0; i < n; i++) 
    {
        long position = lights[i];

        // Find the nearest traffic lights to the left and right
        auto it_right = positions.upper_bound(position);
        long right = *it_right;
        long left = *prev(it_right);

        // Remove the interval between left and right
        intervals.erase(intervals.find(right - left));

        // Insert new intervals
        intervals.insert(position - left);
        intervals.insert(right - position);

        // Insert the new traffic light position
        positions.insert(position);

        // The longest passage without traffic lights
        long longest = *intervals.rbegin();
        results[i] = longest;
    }

    return results;
}

int main() 
{
    // Read input values for x and n
    long x, n;
    cin >> x >> n;
    
    // Read the positions of the traffic lights
    vector<long> lights(n);
    for (long i = 0; i < n; i++) {
        cin >> lights[i];
    }
    
    // Call the solution function and get the results
    vector<long> results = solution(x, n, lights);
    
    // Output the results
    for (long i = 0; i < results.size(); i++)     {
        cout << results[i] << " ";
    }
    cout << endl;
    
    return 0;
}