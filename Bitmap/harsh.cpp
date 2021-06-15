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



https://www.spoj.com/problems/BITMAP/

string arr[182];
int a[182][182];
queue<pair<int, int>> q;

bool isValid(int x, int y, int r, int c) {
    return (x >= 0 && y >= 0 && x < r && y < c);
}

void bfs(int r, int c) {
    memset(a, -1, sizeof(a));

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (arr[i][j] == '1') {
                q.push({i, j});
                a[i][j] = 0;
            }
        }
    }

    int time = 1;

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<int, int> p = q.front();
            q.pop();
            if (isValid(p.first - 1, p.second, r, c) && a[p.first - 1][p.second] == -1)
            {
                q.push(make_pair(p.first - 1, p.second));
                a[p.first - 1][p.second] = time;
            }
            if (isValid(p.first + 1, p.second, r, c) && a[p.first + 1][p.second] == -1)
            {
                q.push(make_pair(p.first + 1, p.second));
                a[p.first + 1][p.second] = time;
            }
            if (isValid(p.first, p.second - 1, r, c) && a[p.first][p.second - 1] == -1)
            {
                q.push(make_pair(p.first, p.second - 1));
                a[p.first][p.second - 1] = time;
            }
            if (isValid(p.first, p.second + 1, r, c) && a[p.first][p.second + 1] == -1)
            {
                q.push(make_pair(p.first, p.second + 1));
                a[p.first][p.second + 1] = time;
            }
        }
        time++;
    }
}



void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    bfs(n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
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

