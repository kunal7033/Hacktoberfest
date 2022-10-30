








































Refresh

Time (IST)	Status	Lang	Test Cases	Code
2020-12-26 15:44:19	Correct	cpp	-	View
2020-12-26 15:43:50	Wrong	cpp	-	View
2020-12-26 15:43:30	Wrong	cpp	-	View
2020-12-26 15:43:00	Correct	cpp	-	View
2020-12-26 15:42:22	Wrong	cpp	-	View
2020-12-06 19:10:41	Correct	cpp	-	View
2020-12-06 18:47:30	Compilation Error	cpp	-	View
C++ (g++ 5.4)




Custom Input

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Function to return minimum number of jumps to end of array
int minJumps(int a[], int n){
    // Your code here
   if(n<=1)
   {
       return 0;
   }
   if(a[0]==0)
   {
       return -1;
   }
   int jump=1;
   int step=a[0],maxreach=a[0];
   for(int i=1; i<n; i++)
   {
       if(i==n-1)
       {
           return jump;
       }
       maxreach=max(maxreach,i+a[i]);
       
       step--;
       if(step==0)
       {
           jump++;
           
           if(i>=maxreach)
           {
               return -1;
           }
           step=maxreach -i;
       }
       
       
   }
    return jump;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
