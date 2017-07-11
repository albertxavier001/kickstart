#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

typedef long long LL;
typedef vector<pair<LL, LL> > RangeList;


LL coverAll(RangeList& intervals) {
    LL left = intervals[0].first, right = intervals[0].second;
    LL area = 0;
    for (int i = 1; i < intervals.size(); ++i) {
        // 前面自成一个区间，那么就此分开
        if (intervals[i].first > right) {
            area += right - left + 1;
            left = intervals[i].first;
            right = intervals[i].second;
        } else if (intervals[i].second > right) {
            right = intervals[i].second;
        }
    }
    area += right - left + 1;

    return area;
}


LL cover(RangeList& intervals) {
    // 注意初始值
    LL Tail = intervals[0].first - 1, secondTail = Tail, TailIndex = -1;
    vector<LL> maxPoints(intervals.size());

    for (int i = 0; i < intervals.size(); ++i) {
        // 更新独立贡献值
        if (i > 0 && intervals[i].first > secondTail) {
            maxPoints[TailIndex] += min(Tail, intervals[i].first - 1) - (secondTail + 1) + 1;
        }

        // 更新secondTail值
        if (Tail > intervals[i].second)
            secondTail = max(secondTail, intervals[i].second);
        else
            secondTail = max(Tail, intervals[i].first-1);

        // 更新Tail值
        if (intervals[i].second > Tail) {
            Tail = intervals[i].second;
            TailIndex = i;
        }
    }

    // 别忘了最后还得再算一次！
    maxPoints[TailIndex] += Tail - (secondTail+1) + 1;

    // 找出最大的独立贡献值
    LL maxPoint = 0;
    for (int i = 0; i < maxPoints.size(); ++i) {
        maxPoint = max(maxPoint, maxPoints[i]);
    }
    return maxPoint;
}


int main() {
            freopen("C-small-practice.in", "r", stdin);
     freopen("input.txt", "r", stdin);
        freopen("output_ref.txt", "w", stdout);
    int t;
    cin >> t;
    // t = 1;
    for (int time = 1; time <= t; ++time) {
        LL N, L1, R1, A, B, C1, C2, M;
        cin >> N >> L1 >> R1 >> A >> B >> C1 >> C2 >> M;
        RangeList intervals;
        for (int i = 0, x = L1, y = R1; i < N; ++i) {
            cout << "x = " << x << " y = " << y << endl;
            intervals.push_back(make_pair(min(x, y), max(x, y)));
            LL x_last = x, y_last = y;
            x = (A * x_last + B * y_last + C1) % M;
            y = (A * y_last + B * x_last + C2) % M;
        }
        sort(intervals.begin(), intervals.end());
        for (auto inv : intervals) {
            cout << "(" << (LL)inv.first << ", " << (LL)inv.second << ")\n";
        }
        cout << "Case #" << time << ": " << coverAll(intervals) - cover(intervals) << endl;
    }

    return 0;
}