#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef float fl;
typedef double db;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fillArray(a, n, t) for (int i = 0; i < n; i++) {a[i] = t}
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front

const long long INF = 2e18;
const long long MOD = 1000000007;
const double PI = 3.14159;
const double EPSILON = 1e-6;

int minRefills(vector<int> x, int n, int L) {
    int numRefills = 0, curRefill = 0;

    while (curRefill <= n) {
        int lastRefill = curRefill;

        while (curRefill <= n && x[curRefill + 1] - x[lastRefill] <= L) {
            curRefill++;
        }

        //cannot find a gas station in distance L
        if (curRefill == lastRefill) {
            return -1; // -1 mins impossible
        }

        if (curRefill <= n) {
            numRefills++;
        }
    }

    return numRefills;
}

int main()
{
    fastio;

    int distance; //the distance from A to B
    cin >> distance;

    int length;
    cin >> length;

    int n; //the number of gas stations
    cin >> n;
    vector<int> x(n + 2);
    x[0] = 0;
    x[n + 1] = distance;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    cout << minRefills(x, n, length) << "\n";

    return 0;
}