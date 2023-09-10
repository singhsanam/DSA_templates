int pre[200001];
void buildSparseTable(int arr[], int n, vector<vector<int>> &sparse)
{
    for (int i = 0; i < n; i++)
        sparse[i][0] = arr[i];
 
    /* Build sparse table*/
    for (int m = 1; m < 20; m++)
        for (int i = 0; i <= n - (1 << m); i++)
 
            /* Updating the value of gcd. */
            sparse[i][m] = min(sparse[i][m - 1],
                                 sparse[i + (1 << (m - 1))][m - 1]);
}
int query(int L, int R, vector<vector<int>> &sparse)
{
    /* The maximum power of range that is less than 2 */
    int m = pre[R-L+1];
    // int m = (int)log2(R - L + 1);
    return min(sparse[L][m], sparse[R - (1 << m) + 1][m]);
}
//precomputation of powers or 2 less than equals to i
    // int p1=1,c=0;
    // for(int i=2;i<=200000;i++){
    //     if(p1*2==i) {
    //         p1*=2;
    //         c++;
    //     }
    //     pre[i]=c;
    // }

    //vector<vector<int>> sparse(n, vector<int>(20));
    //buildSparseTable(a, n, sparse);
    //query(l,r,sparse);