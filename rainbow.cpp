#include <bits/stdc++.h>
using namespace std;
int n,c;
int a[1001],p[1001],s[1001],w[1001],vis[1001];
int root(int x)
{
    while(x!=p[x])
    {
        p[x]=p[p[x]];
        x=p[x];
    }
    return x;
}
void ini()
{
    for(int i=0;i<1001;i++)
    {
        p[i]=i;
        s[i]=1;
        vis[i]=0;
        w[i]=0;
    }
}
void uni(int x,int y)
{
    int xx=root(x);
    int yy=root(y);
    if(xx!=yy)
    {
        if(s[xx]>s[yy]){
        p[yy]=p[xx];
        s[xx]=s[xx]+s[yy];
        w[xx]=w[xx]+w[yy];
        }
        else
        {
            p[xx]=p[yy];
            s[yy]=s[yy]+s[xx];
            w[yy]=w[yy]+w[xx];
        }

    }
}
int main()
{
    int i,j,v,x,r=0;

    ios::sync_with_stdio(0);
    cin>>n>>c;
    while(n!=0||c!=0)
    {
        ini();
        pair < int , int >  q[1001];
       for(i=0;i<n;i++)
        {
            cin>>a[i];
            w[i]=a[i];
        }
       for(i=0;i<n;i++)
       {
           cin>>v;
           for(j=0;j<v;j++)
           {
               cin>>x;
               uni(x-1,i);
           }
       }
       r=1;

       for(i=0;i<n;i++)
       {
           if(i==p[i])
           {

               q[r++]=make_pair(s[i],w[i]);
           }
       }
       int dp[r+1][c+1];
       for(i=0;i<=r;i++)
       {

           for(j=0;j<=c;j++)
           {
               if(i==0||j==0)
                dp[i][j]=0;
               else if(q[i].second<=j)
                dp[i][j]=max(dp[i-1][j],q[i].first+dp[i-1][j-q[i].second]);
               else
                dp[i][j]=dp[i-1][j];

           }

       }

        cout<<dp[r][c]<<endl;

        cin>>n>>c;
    }


}
