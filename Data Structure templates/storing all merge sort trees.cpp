//https://codeforces.com/contest/61/problem/E
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
// #define int             long long
#define all(a)          a.begin(),a.end()
#define endl            "\n"
#define fill(a,b) memset(a, b, sizeof(a))
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
vector<int> merge(int a[],int l,int m,int r){
    int i=l,j=m+1;
    vector<int>v1;
    while(i<=m&&j<=r){
        if(a[i]<=a[j]) v1.push_back(a[i++]);
        else v1.push_back(a[j++]);
    }
    while(i<=m) v1.push_back(a[i++]);
    while(j<=r) v1.push_back(a[j++]);
    for(i=l;i<=r;i++) a[i]=v1[i-l];
    return v1;
}
void msort(int a[],vector<vector<int>>&seg,int i,int l,int r){
    if(l==r){
        vector<int>v1;
        v1.push_back(a[l]);
        seg[i]=v1;
        return;
    }
    int x,y;
    int m=(l+r)/2;
    msort(a,seg,2*i+1,l,m);
    msort(a,seg,2*i+2,m+1,r);
    vector<int>v1;
    v1=merge(a,l,m,r);
    seg[i]=v1;
}   
int ans1=0,ans2=0,tar;
int find1(vector<vector<int>>&seg,int i,int lx,int rx,int l,int r){
    if(l>rx||r<lx) return 0;
    if(l>=lx&&r<=rx){
        int x=lower_bound(seg[i].begin(), seg[i].end(), tar)  - seg[i].begin();
        return x;
    }
    int m=(l+r)/2;
    int c1=find1(seg,2*i+1,lx,rx,l,m);
    int c2=find1(seg,2*i+2,lx,rx,m+1,r);
    return c1+c2;
}            
signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    //cin>>t;
while(t--){
    int i,j,x=0,y=0,p=0,n,q=-1,u=0,v=0,k,c=0,m;
    cin>>n;
    int a[n],b[n];
    rep(i,0,n) {
        cin>>a[i];
        b[i]=a[i];
    }
    int n1=4*n;
    vector<vector<int>>seg(n1);
    msort(a,seg,0,0,n-1);
    // for(i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    long long ans=0;
    for(i=0;i<n;i++){
        tar=b[i];
        long long p=find1(seg,0,0,i,0,n-1);
        long long q=find1(seg,0,i,n-1,0,n-1);
        // cout<<p<<" "<<q<<endl;
        p=i-p;
        // cout<<p<<" "<<q<<endl;

        ans+=p*q;
    }
    cout<<ans<<endl;

    }
}