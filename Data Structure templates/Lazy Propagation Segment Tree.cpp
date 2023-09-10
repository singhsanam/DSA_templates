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
int getmin(vector<int>&st,vector<int>&left,int i,int lx,int rx,int l,int r){
    if(left[i]!=0){
        st[i]+=left[i];
        if(l!=r){
            left[2*i+1]+=left[i];
            left[2*i+2]+=left[i];
        }
        left[i]=0;
    }
    if(r<lx||l>rx) return 1e18;
    if(l>=lx&&r<=rx) return st[i];
    int m=(l+r)/2;
    int c1=getmin(st,left,2*i+1,lx,rx,l,m);
    int c2=getmin(st,left,2*i+2,lx,rx,m+1,r);
    return min(c1,c2);
}
void update(vector<int>&st,vector<int>&left,int i,int lx,int rx,int val,int l,int r){
    if(lx<=l&&r<=rx) left[i]+=val;
    if(left[i]!=0){
        st[i]+=left[i];
        if(l!=r){
            left[2*i+1]+=left[i];
            left[2*i+2]+=left[i];
        }
        left[i]=0;
    }
    if(l==r||lx<=l&&r<=rx) return;
    if(rx<l||r<lx) return;
    int m=(l+r)/2;
    update(st,left,2*i+1,lx,rx,val,l,m);
    update(st,left,2*i+2,lx,rx,val,m+1,r);
    st[i]=min(st[2*i+1],st[2*i+2]);
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
    vector<int>left(n1+1,0);
    for(i=0;i<n;i++){
        a[i]=0;
        // cin>>a[i];
    }
    segtr(st,a,0,0,n-1);
    while(q--){
        cin>>u;
        if(u==1){
            int l,r;
            cin>>l>>r>>v;
            r--;
            update(st,left,0,l,r,v,0,n-1);
            a[i]=v;
        }
        else{
            int l,r;
            cin>>l>>r;
            r--;
            cout<<getmin(st,left,0,l,r,0,n-1)<<endl;
        }
    }

    }
}