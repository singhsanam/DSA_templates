#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define int             long long
#define all(a)          a.begin(),a.end()
#define endl            "\n"
#define fill(a,b) memset(a, b, sizeof(a))
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
int MOD;
const int MAXL=64;
int powerm(int a,int b) { //m-> mod
    if(b==0) {
        return 1;
    }
    int curr=a,res=1;
    for(int i=0;i<MAXL;i++) {
        if((1LL<<i)&b) {
            res=(res*curr)%MOD;
        }
        curr=(curr*curr)%MOD;
    }
    return res;
}
vector<int>fac,inv;
    int n=0;
    void facm(int x) { //precomputes factorials!
        n=x;
        fac.resize(n+1),inv.resize(n+1); //till fac[n] and inv[n]
        fac[0]=1;
        for(int i=1;i<=n;i++) {
            fac[i]=(fac[i-1]*i)%MOD;
        }
    }
    void preinv() { //precomputes inverse!
        inv[n]=powerm(fac[n],MOD-2);
        for(int i=n-1;i>=0;i--) {
            inv[i]=(inv[i+1]*(i+1))%MOD;
        }
    }
    int choose(int a,int b) { //get nCr
        if(a<b) {
            return 0;
        }
        return ((fac[a]*inv[b])%MOD*inv[a-b])%MOD;
    }            
signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    //cin>>t;
while(t--){
    int i,j,x=0,y=0,p=0,q=-1,u=0,v=0,k,c=0,m,n1;
    MOD=1e9+7;

    }
}
