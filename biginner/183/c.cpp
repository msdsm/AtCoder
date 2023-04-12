#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 100000000; // 十分大きな値

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<vector<long long> > dist(n, vector<long long>(n)); // 各都市間の所要時間
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }

    vector<long> order(n);
    for (int i = 0; i < n; ++i) order[i] = i;

    int cnt = 0;
//int cnt2=0;
    do {
//cnt2++;
        int temp_dist = 0;

        for (int i = 1; i < n; ++i) {
            temp_dist += dist[order[i-1]][order[i]];
        }
        temp_dist+=dist[order[n-1]][0];
//cout << temp_dist << endl;
        if (temp_dist == k) {
//cout << "あ" << endl;
            cnt++;
        }
    } while (next_permutation(order.begin()+1, order.end()));

//cout << cnt2 << endl;
    cout << cnt << endl;
}
