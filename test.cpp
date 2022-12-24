#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MOdiff1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
bool isPrime(ll n);
void fast();
void clk();
ll fact(ll n);
ll nCr(ll n, ll r);
ll gcd(ll a, ll b);
ll expo(ll a, ll b, ll m);
ll mod_add(ll a, ll b, ll m);
ll mod_mul(ll a, ll b, ll m);
ll mod_sub(ll a, ll b, ll m);
ll lcm(ll a, ll b);
ll msbof(ll n);
bool isPrime(ll n);
void primeFactors(ll n);
bool isPowerOfTwo(ll n);


void solve(ll testcase)
{
    // write code here
}
ll t = 1;
int main()
{
    fast();
    cin >> t;
    while (t--)
    {
        solve(t);
        // clk();
    }
    return 0;
}
//-----------------functions--------------//
void clk()
{
    clock_t time = clock();
    solve(t);
    time = clock() - time;
    cout << "time=" << (float)time / CLOCKS_PER_SEC << endl;
}
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
bool isPowerOfTwo(ll n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
ll fact(ll n)
{
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}

ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll expo(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
ll msbof(ll n)
{
    if (n == 0)
        return 0;

    ll msb = 0;
    n = n / 2;
    while (n != 0)
    {
        n = n / 2;
        msb++;
    }

    return (1 << msb);
}
bool isPrime(ll n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}