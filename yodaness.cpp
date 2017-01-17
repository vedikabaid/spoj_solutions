#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
string a[300001],b[300001];
int arr[300001],bit[300001],n;
map < string , int > m;
int read(int x)
{
    int s=0;
    while(x>0)
    {
        s+=bit[x];
        x=x-(x&-x);
    }
    return s;
}
void upd(int x)
{
    while(x<=n)
    {
        bit[x]++;
        x=x+(x&-x);
    }
}
int main()
{
    int t,i,j;
    ios_base::sync_with_stdio(0);
    cin>>t;
    long long ans=0,tt=0;
    while(t--)
    {
        cin>>n;
        m.clear();
        ans=0;
        memset(bit,0,sizeof(bit));
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            m.insert(mp(a[i],i));
        }
        for(i=0;i<n;i++)
        {
            cin>>b[i];

        }
        tt=0;
        for(i=0;i<n;i++)
        {
           arr[i]=m[b[i]]+1;
        }
        for(i=n-1;i>=0;i--)
        {
            ans+=read(arr[i]);
            upd(arr[i]);
        }
        cout<<ans<<endl;
    }


}
