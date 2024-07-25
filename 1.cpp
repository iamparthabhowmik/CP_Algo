/* iamparthabhowmik */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
template<class T> using oset=tree<T,null_type,greater_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
// greater, less_equal, greater_equal, *X.find_by_order(ind), X.order_of_key(elem)
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << nl;
#else
#define debug(x)
#endif 
void __BUG(){ 
#ifndef ONLINE_JUDGE
freopen("error.txt", "w", stderr);
#endif 
}
#define int long long
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define nl "\n"
#define Nl "\n"
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define all(x) x.begin(), x.end()
#define ff(i, a, b) for(int i=a; i<b; i++)
#define rf(i, a, b) for(int i=a; i>=b; i--)
#define ain(arr,a,b) for(int i=(a); i<(b); i++) cin>>(arr)[i];
#define aout(arr,a,b) for(int i=(a); i<(b); i++) cout<<(arr)[i]<<" ";
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
typedef vector<vector<int>> vvi;
typedef map<int,int> mii;
typedef set<int> si;
int MOD = 1e9+7;
int MOD1 = 998244353;

int32_t main(){
    fastio(); __BUG();

    int n; cin>>n;

    vector<int> arr(1<<n);
    for(int i=0; i<(1<<n); i++){
        cin>>arr[i];
    }

    int dp[1<<n][n+1];

    for(int mask=0; mask<(1<<n); mask++){
        dp[mask][0]=arr[mask];
        for(int j=1; j<n+1; j++){
            if(mask&(1<<(j-1))){
                dp[mask][j]=dp[mask][j-1]+dp[mask^(1<<(j-1))][j-1];
            }
            else dp[mask][j]=dp[mask][j-1];
        }
    }

    int ans[1<<n];
    for(int i=0; i<(1<<n); i++){
        ans[i]=dp[i][n];
        cout<<ans[i]<<" ";
    }






    return 0;
}