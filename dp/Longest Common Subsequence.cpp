#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence

int lcs(int x, int y, string s1, string s2){
    // your code here
    // couldn't solve it on my own 
    // very standard
    // dp[i][j] -> length of longest common subsequence in s1[0...i] and s2[0...j]
    // MAIN IDEA
    /*
      either the last character can match with the other last character or it doesn't
      it is brilliant catch to solve the problem, 
      case 1) if they match then for sure the optimal subsequence will contain the last character
      case 2) if they doesn't match then we will take max of two as written below
      
      dp[i][j] = 
                 case 1) s1[i] == s2[j]
                 1 + dp[i-1][j-1]
                 
                 case 2) s1[i] != s2[j]
                 max(dp[i][j-1], max[i-1][j]) (one of the last character will obvioulsy won't 
                                                match with any character)
                    
    */
    vector<vector<int>> dp(x, vector<int>(y,0));
    // first row
    for(int i=0; i<y; ++i){
        if(s2[i]==s1[0]){
            dp[0][i] = 1;
            while(i<y){
                dp[0][i] = 1;
                i++;
            }
        }
    }
    //first col
    for(int i=0; i<x; ++i){
        if(s1[i]==s2[0]){
            dp[i][0] = 1;
            while(i<x){
                dp[i][0] = 1;
                i++;
            }
        }
    }
    for(int r=0; r<x; r++){
        for(int c=0; c<y; c++){
            if(r>0 && c>0){
                if(s1[r]==s2[c]){
                    dp[r][c] = 1 + dp[r-1][c-1];
                }
                else
                    dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
            }
            // cout<<dp[r][c]<<" ";
        }
        // cout<<endl;
    }
    return dp[x-1][y-1];
}




