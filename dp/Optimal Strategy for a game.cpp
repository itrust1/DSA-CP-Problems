

 // } Driver Code Ends


long long maximumAmount(int arr[], int n) 
{
    // Your code here
    // was close to choosing the state 
    // the state is very uncommon and its start and end of the array 
    /* 
     f(i,j) => maximum amount you can get when it is your turn
               from arr[i],arr[i+1],..,arr[j] 
     TRANSITION
      - either you can choose arr[i] or arr[j]
      - lets say you chose arr[i] then in the next turn the player2(p2) will choose such that 
        p2's amount is maximised.
        - let S = arr[i+1] + arr[i+2] + ... + arr[j]
        - let's say p2 chooses arr[i+1] then p1 will get f(i+2,j) amount added 
          ans p2 then will get S - arr[i+1] - f(i+2,j) more amount 
          so net amount p2 will get is = arr[i+1] + S - arr[i+1] - f(i+2,j)
                                       = S - f(i+2,j)
        - if p2 chooses arr[j] then    = S - f(i+1,j-1)
        - p2 will choose max( S-f(i+2,j), S-f(i+1, j-1) ) and p1 will get min of them
      
      => f(i,j) = max( 
                        arr[i] + min(f(i+2,j), f(i+1, j-1) ) ,
                        arr[j] + min(f(i+1,j-1), f(i,j-2) ) 
                     )
    */
    int f[n][n];
    for(int i=0; i<n; ++i)
        f[i][i] = arr[i];
    for(int i=0; i<n-1; ++i)
        f[i][i+1] = max(arr[i],arr[i+1]);
    
    for(int k=2; k<n; k++){
        for(int i=0; i+k<n; ++i){
            int j = i+k;
            f[i][j] = max(arr[i] + min(f[i+2][j], f[i+1][j-1]), 
                          arr[j] + min(f[i+1][j-1], f[i][j-2])  );
            
        }
    }
    return f[0][n-1];
}







// { Driver Code Starts.

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
