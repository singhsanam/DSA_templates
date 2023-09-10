#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define int             long long
#define all(a)          a.begin(),a.end()
#define endl            "\n"
#define fill(a,b) memset(a, b, sizeof(a))
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
void segtr(vector<int>&st,int a[],int i,int l,int r){
    if(l==r) {
        st[i]=a[l];
        return;
    }
    int m=(l+r)/2;
    segtr(st,a,2*i+1,l,m);
    segtr(st,a,2*i+2,m+1,r);
    st[i]=st[2*i+1]+st[2*i+2];
}
int getsum(vector<int>&st,int i,int lx,int rx,int l,int r){
    if(r<lx||l>rx) return 0;
    if(l>=lx&&r<=rx) return st[i];
    int m=(l+r)/2;
    int c1=getsum(st,2*i+1,lx,rx,l,m);
    int c2=getsum(st,2*i+2,lx,rx,m+1,r);
    return c1+c2;
}
void update(vector<int>&st,int i,int j,int val,int l,int r){
    if(j<l||r<j) return;
    if(l==r){
        st[i]=val;
        return;
    }
    int m=(l+r)/2;
    update(st,2*i+1,j,val,l,m);
    update(st,2*i+2,j,val,m+1,r);
    st[i]=st[2*i+1]+st[2*i+2];
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    //cin>>t;
while(t--){
    int i,j,x=0,y=0,p=0,n,q=-1,u=0,v=0,k,c=0;
    cin>>n>>q;
    int a[n];
    int n1=1;
    n1=4*n;
    vector<int>st(n1+1,0);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    segtr(st,a,0,0,n-1);
    while(q--){
        cin>>u;
        if(u==1){
            cin>>i>>v;
            update(st,0,i,v,0,n-1);
            a[i]=v;
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<getsum(st,0,l,r,0,n-1)<<endl;//sum from [l,r]
        }
    }

    }
}