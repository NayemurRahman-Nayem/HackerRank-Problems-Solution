//      Bismillah-ir-Rahman-ir-Rahim


#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef unsigned long long ull ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
typedef vector<vi> vvi ;
typedef vector<vl> vvl ;
typedef pair<int, int> pii ;
typedef pair<float, float> pff ;
typedef pair<double, double> pdd ;
typedef pair<ll, ll> pll ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
#define el << '\n'
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll bin_expo(ll base, ll pow, ll m)
{       if (pow == 0) return 1;
        ll ret = bin_expo(base, pow / 2, m) % m;
        if (pow & 1)return (ret % m * ret % m * base % m) % m;
        else return (ret % m * ret % m) % m;}
ll mod_add(ll a, ll b, ll m) { return ( ( a % m ) + ( b % m ) ) % m ; }
ll mod_sub(ll a, ll b, ll m) { return ( ( a % m ) - ( b % m ) ) % m ; }
ll mod_mul(ll a, ll b, ll m) { return ( ( a % m ) * ( b % m ) ) % m ; }
ll mod_div(ll a, ll b, ll m) { return ( ( a % m ) * bin_expo(b, m - 2, m) ) % m ; }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};
const ll infLL = 1e18 ;
const ll inf = 1e17 + 7 ;
const ll mod1 = 1e9 + 7 ;
const ll mod2 = 999999937 ; 
const int mx = 1e6 + 123 ;
const double eps = 1e-7 ;


ll Hash1[mx] , Hash2[mx] ; 
ll prime1[mx] , prime2[mx] ; 
ll P1 = 137 , P2 = 149 ; 
ll n , m ;  


ll Hashval1(ll l , ll r)
{
        return  ((Hash1[r] - (1LL*Hash1[l-1]*prime1[r-l+1]) % mod1) % mod1 + mod1) % mod1;
}


ll Hashval2(ll l , ll r)
{
        return ((Hash2[r] - (1LL*Hash2[l-1]*prime2[r-l+1]) % mod2) % mod2 + mod2) % mod2;  
}

ll getHashval1(string s)
{
        ll H = 0 ;
        for(int i=0;i<s.size();i++)
        {
                H = ((1LL*H*P1) + s[i] % mod1 ) % mod1 ; 
        }
        return H ; 
}

ll getHashval2(string s) 
{
        ll H = 0 ; 
        for(int i=0;i<s.size();i++) 
        {
                H = ( (1LL*H*P2) + s[i] % mod2 ) % mod2 ; 
        }
        return H ; 
}



void solution()
{ 
        string s , c ; 
        cin >> s >> c ; 
        queue<char>q ;
        ll H1 = getHashval1(s) ; 
        ll H2 = getHashval2(s) ; 
        ll Hs1 = 0 ;
        ll Hs2 = 0 ; 
        ll ans = 0 ;    
        for(auto ch:c) 
        {
                q.push(ch) ;
                ll len = q.size() ;  
                Hs1 = ( (1LL*Hs1*P1) + ch % mod1 ) % mod1 ; 
                Hs2 = ( (1LL*Hs2*P2) + ch % mod2 ) % mod2 ;
                Hash1[len] = Hs1 ; 
                Hash2[len] = Hs2 ; 
                ll r = len ; 
                ll l = len - s.size() ; 
                ll val1 = Hashval1(l+1,r) ;
                ll val2 = Hashval2(l+1,r) ; 
                if(val1==H1 and val2==H2) 
                {
                        ans ++ ; 
                        for(int j=0;j<s.size();j++) q.pop() ; 
                        Hs1 = Hash1[q.size()] ; 
                        Hs2 = Hash2[q.size()] ; 
                } 
        }
        cout << ans << endl ; 
}


int main()
{
        fastIO;
        // file() ;
        prime1[0] = prime2[0] = 1 ; 
        for(int i=1;i<mx;i++)
        {
                prime1[i] = ( 1LL * prime1[i-1] * P1 ) % mod1 ; 
                prime2[i] = ( 1LL * prime2[i-1] * P2 ) % mod2 ; 
        }
        int _ = 1; cin >> _;
        while (_--) solution();
        return 0;
} 