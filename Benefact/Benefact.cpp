#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define MOD (int) 1e9+7
#define all(v) (v).begin(),(v).end()
#define tc(t) ll t; cin >> t; while (t--)
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rf(i, a, b) for (ll i = a; i >= b; i--)
#define ll long long
#define pb push_back
#define Harsh_Srivastava ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define inf (int)(1e18)
#define ini(a, i) memset(a, i, sizeof(a))
#define vi vector<int>
#define fi first
#define se second
#define pi pair<int, int>
#define vii vector<ii>
#define sz(s) s.size()
#define bits(n) __builtin_popcount(n)
typedef pair<int, ll> ipair;

const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
int max(int a, int b) {if (a > b) return a; else return b;}
int min(int a, int b) {if (a < b) return a; else return b;}
void pr(int x) {cout << x;}
void prl(int x) {cout << x << "\n";}


http://www.spoj.com/problems/BENEFACT/


vector<ipair> adj[50001];
ll dist[50001] = {0};
int n;


int dij(int src) {
    priority_queue<ipair, vector<ipair>, greater<ipair> >pq;
    bool vis[n + 1] = {false};
    pq.push(make_pair(0, src));
    for (int y = 1; y <= n; y++) dist[y] = 1e9;
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (!vis[u]) vis[u] = true;
        else continue;

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            ll weight = adj[u][i].second;
            if (weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    ll mx = 0;
    int id;
    for (int k = 1; k <= n; k++) {if (mx < dist[k]) {mx = dist[k], id = k;}};

    return id;
}

void solve() {
    int a, b, c;

    cin >> n;
    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int j = 0; j < n - 1; ++j) {
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    int y = dij(1);
    ll ans = dist[dij(y)];
    cout << ans << "\n";
}


signed main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w", stdout);
#endif

    Harsh_Srivastava;
    //srand(time(NULL));
    tc(t)
    solve();
}

