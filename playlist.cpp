#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest subsequence without repeating elements
int longest_sequence(vector<int>& play, int n) {
    int i = 0;  // Start of the current window
    int j = 0;  // End of the current window
    int maxlen = 1;  // Length of the longest subsequence found
    set<int> mpp;  // Set to keep track of unique elements in the current window

    while (i < n && j < n) {
        // Expand the window by moving 'j' and adding unique elements to the set
        while (j < n && !mpp.count(play[j])) {
            mpp.insert(play[j]);
            maxlen = max(maxlen, j - i + 1);  // Update the maximum length
            j++;
        }
        // If a duplicate is found, shrink the window by moving 'i' and removing elements from the set
        if (j < n && mpp.count(play[j])) {
            mpp.erase(play[i]);
            i++;
        }
    }
    return maxlen;  // Return the length of the longest subsequence
}

int main(){
    int n; cin >> n;  // Input the number of elements
    vector<int> play(n);
    for (int i = 0; i < n; i++) {
        cin >> play[i];  // Input the elements
    }
    int ans = longest_sequence(play, n);  // Find the longest subsequence length
    cout << ans << endl;  // Output the result
    return 0;
}
