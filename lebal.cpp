#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
LL p2[42];
void precompute()
{
    p2[0]=1;
    for(int i=1;i<=40;i++)
    {
        p2[i]=p2[i-1]*2;
    }
    return;
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      precompute();
      int x,y,di;
      int i,j,t;
      S(t);
      int N,M;
      while(t--)
      {
            S(N); S(M);
            int freq_col[42],price_col[42],col[42],price[42];
            memset(freq_col,0,sizeof(freq_col));
            memset(price_col,0,sizeof(price_col));
            while(N--)
            {
                S(x); S(y);
                freq_col[x]+=1;
                price_col[x]+=y;
            }
            di=1;
            for(i=1;i<=40;i++)
            {
                if(freq_col[i])
                {
                    col[di]=freq_col[i];
                    price[di]= price_col[i];
                    di++;
                }
            }
               di--;
            LL dp[42][42][2];
            memset(dp,0,sizeof(dp));
            for(i=0;i<=40;i++) { dp[0][i][0]=0; dp[0][i][1]=0; }
            for(i=0;i<=40;i++) { dp[i][0][0]=1;  dp[i][0][1]=0; }

            for(i=1;i<=di;i++)
            {
                for(j=1;j<=di;j++)
                {
                    dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j-1][0]*(p2[col[i]]-1);

                    dp[i][j][1]= dp[i-1][j][1] + dp[i-1][j-1][1]*(p2[col[i]]-1) + dp[i-1][j-1][0]*price[i]*(p2[col[i]-1]);
                  //  cout<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;

                }
            }
            LL nume=0,deno=0;
            for(i=M;i<=di;i++)
            {
                nume+= dp[di][i][1]; // cost
                deno+= dp[di][i][0]; // ways
            }
            //cout<<nume<<" "<<deno<<endl;
            double ans= (double) (nume)/ (double)(deno);
            printf("%.8lf\n",ans);
      }
return 0;
}
