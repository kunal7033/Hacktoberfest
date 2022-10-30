








































Refresh

Time (IST)	Status	Lang	Test Cases	Code
2021-07-20 20:41:11	Correct	cpp	-	View
2021-07-20 20:39:07	Wrong	cpp	-	View
2021-07-20 20:35:59	Wrong	cpp	-	View
2021-07-20 20:35:37	Wrong	cpp	-	View
2021-07-20 20:33:00	Wrong	cpp	-	View
2021-07-20 20:32:32	Wrong	cpp	-	View
C++ (g++ 5.4)
Average Time:
20m
Your Time:
13m




Custom Input
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    unordered_set<int> s;
	    
	    for(int i=0; i<n; i++){
	        if(s.find(x-arr[i])!=s.end())
	        return true;
	        
	        s.insert(arr[i]);
	    }
	    return false;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
  // } Driver Code Ends
