








































Refresh

Time (IST)	Status	Lang	Test Cases	Code
2021-01-27 20:08:22	Correct	cpp	-	View
2021-01-27 20:03:48	RunTime Error	cpp	-	View
2021-01-27 20:02:12	RunTime Error	cpp	-	View
2021-01-27 19:52:07	Wrong	cpp	-	View
2021-01-27 13:19:11	Wrong	cpp	-	View
2021-01-27 13:16:12	Wrong	cpp	-	View
2021-01-27 13:08:26	Wrong	cpp	-	View
2021-01-27 13:03:20	Wrong	cpp	-	View
C++ (g++ 5.4)
Average Time:
30m
Your Time:
17m




Custom Input
#include <bits/stdc++.h>
using namespace std;

char nonrepeatingCharacter(string S);

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    
        char ans = nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends


// Complete this function
char nonrepeatingCharacter(string S)
{
   //Your code here
    int h[26]={0};
    bool flag=false;
    for(int i=0; i<S.size(); i++)
    {
        h[S[i]-'a']++;
    }
    for(int i=0; i<S.size(); i++)
    {
        if(h[S[i]-'a']==1)
        {
            return S[i];
            flag=true;
        }
    }
    if(flag==false)
    return '$';
}
