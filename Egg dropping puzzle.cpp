#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */
int eggDrop(int n, int k) 
{
    // your code here
    // dp[i][j] -> minimum number of drops needed for i eggs and j floors
    /* 
     - we can start dropping the egg at any floor and there will be two possiblities, either
       it breaks or it does not
     - and we take max of this two cases 
     - and over all different xs to choose we choose the optimal one i.e. which gives the 
       minimum value
    */
    // dp[i][j] = 1+min(max(dp[i-1][x-1],dp[i][j-x]) x = 1,2,3,..,j)
    // initialisation
    // dp[1][j] = j
    // dp[i][0] = 0
    int dp[n+1][k+1];
    for(int e=0; e<=n; ++e){
        dp[e][0] = 0;
    }
    for(int f=0; f<=k; ++f){
        dp[1][f] = f;
        dp[0][f] = 0;
    }
    for(int e=2; e<=n; ++e){
        for(int f=1; f<=k; ++f){
            dp[e][f] = INT_MAX;
            for(int x=f; x>=1; x--){
                int m = dp[e-1][x-1];
                m = max(m, dp[e][f-x]);
                if(m+1<dp[e][f])
                    dp[e][f] = m+1;
            }
            // cout<<dp[e][f]<<" ";
        }
        // cout<<endl;
    }
    return dp[n][k];
    
}


// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;

        //calling function eggDrop()
        cout<<eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
