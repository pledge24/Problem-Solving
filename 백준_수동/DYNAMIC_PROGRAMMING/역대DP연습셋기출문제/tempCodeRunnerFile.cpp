dp[n][k] = dp[n][k-1];

            if(n - pow(2, k) > 0){
                if(dp[n-pow(2, k)][k] > 0){
                    dp[n][k] = (dp[n][k] + dp[n-pow(2, k)][k]) % DIV; 
                }
                else{
                    dp[n][k] = (dp[n][k] + dp[n-pow(2, k)][k-1]) % DIV; 
                }
            }
            else if(n - pow(2, k) == 0){
                dp[n][k] = (dp[n][k] + 1) % DIV;
            }