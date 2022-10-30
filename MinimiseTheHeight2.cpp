








































Refresh

Time (IST)	Status	Lang	Test Cases	Code
2020-12-26 16:03:43	Wrong	cpp	-	View
2020-12-26 16:03:39	Wrong	cpp	-	View
2020-12-26 15:59:12	Wrong	cpp	-	View
2020-12-26 15:58:11	Wrong	cpp	-	View
2020-12-26 15:57:46	Wrong	cpp	-	View
2020-12-06 14:27:03	Wrong	cpp	-	View
2020-12-06 14:21:23	Wrong	cpp	-	View
2020-12-06 14:20:20	Wrong	cpp	-	View
2020-12-06 14:18:00	Wrong	cpp	-	View
2020-12-06 12:39:30	Wrong	cpp	-	View
2020-11-30 12:33:50	Correct	cpp	-	View
2020-11-28 12:07:35	Wrong	cpp	-	View
2020-11-28 11:59:26	Wrong	cpp	-	View
2020-11-28 11:59:00	Compilation Error	cpp	-	View
2020-11-28 11:57:58	Compilation Error	cpp	-	View
2020-11-28 11:54:51	Wrong	cpp	-	View
2020-11-28 11:47:10	Wrong	cpp	-	View
2020-11-28 11:32:37	Wrong	cpp	-	View
2020-11-28 11:29:06	Wrong	cpp	-	View
2020-11-28 11:11:46	Wrong	cpp	-	View
C++ (g++ 5.4)
Average Time:
25m
Your Time:
3m




Custom Input
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
         vector<pair<int, int>> v;
        vector<int> taken(n);
        
        // we will store all possible heights in a vector
        for(int i = 0; i < n; i++){
            if(arr[i] - k >= 0){
                v.push_back({arr[i] - k, i});
            }
            v.push_back({arr[i] + k, i});
        }
        sort(v.begin(), v.end());
        int elements_in_range = 0;
        int left = 0;
        int right = 0;
        
        // By two pointer we will traverse v and whenever we will get a range
        // in which all towers are included, we will update the answer.
        while(elements_in_range < n && right < v.size()){
            if(taken[v[right].second] == 0){
                elements_in_range++;
            }
            taken[v[right].second]++;
            right++;
        }
        int ans = v[right - 1].first - v[left].first;
        while(right < v.size()){
            if(taken[v[left].second] == 1){
                elements_in_range--;
            }
            taken[v[left].second]--;
            left++;
            
            while(elements_in_range < n && right < v.size()){
                if(taken[v[right].second]==0){
                    elements_in_range++;
                }
                taken[v[right].second]++;
                right++;
            }
            
            if(elements_in_range == n){
                ans = min(ans, v[right - 1].first - v[left].first);
            }
            else{
                break;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
