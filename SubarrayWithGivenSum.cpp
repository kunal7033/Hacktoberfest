








































Refresh

Time (IST)	Status	Lang	Test Cases	Code
2020-11-24 10:19:29	Correct	cpp	-	View
C++ (g++ 5.4)
Average Time:
20m
Your Time:
30m




Custom Input
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find the subarray with given sum k
// arr: input array
// n: size of array
vector<int> subarraySum(int arr[], int n, int s){
    
    // Your code here
    int last=0, start=0;
    unsigned long long cursum=0;
    bool flag=false;
    vector<int> res;
    for(int i=0; i<n; i++)
    {
        cursum+=arr[i];
        if(cursum>=s)
        {
            last =i;
        
        while(cursum>s && start<last )
        {
        cursum -= arr[start];
        start++;
        }
        if(cursum==s)
        {
            res.push_back(start+1);
            res.push_back(last+1);
            
            flag=true;
            break;
        }
        }
    }
    if(flag==false)
    {
        res.push_back(-1);
    }
    
    return res;
}

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        vector<int>res;
        res = subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
