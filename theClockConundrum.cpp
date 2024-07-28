/*There are many ways to implement the solution, but many involve a lot of casework. Below is the shortest solution we know of.
Walk around the clock in the order 1, 2, …, 12. If we pass by two red strings or two blue strings in a row, the strings don't intersect; otherwise, they do.
This is because if we don't have two red or blue in a row, then the red and blue strings alternate, so there must be an intersection.*/
#include <bits/stdc++.h>
using namespace std;
void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string s;
	for (int i = 1; i <= 12; i++) {
		if (i == a || i == b) {s += "a";}
		if (i == c || i == d) {s += "b";}
	}
	cout << (s == "abab" || s == "baba" ? "YES\n" : "NO\n");
}
 
int main() {
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
}