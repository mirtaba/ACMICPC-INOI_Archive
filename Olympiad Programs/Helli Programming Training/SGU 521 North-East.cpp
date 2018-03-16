#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

const int MAX_N = 100005;
const int MAX_POS = 1000005;
const int MAX_BIT = 2*MAX_POS + 1000;

struct Point
{
    int x, y, id;
    Point() {}
    Point(int xx, int yy, int i) : x(xx), y(yy), id(i) {}
}

int n;
int tree[3*MAX_POS];
Point points[MAX_N], points2[MAX_N];
int am[MAX_N];
int go[MAX_N], come[MAX_N];
bool can[MAX_N], will[MAX_N];

int bit_get(int id) {
    int ans = 0;
    while (id > 0) {
        ans = max(ans, tree[id]);
        id -= (id & -id);
    }
    return ans;
}

void bit_update(int id, int val) {
    while (id < MAX_BIT) {
        tree[id] = max(tree[id], val);
        id += (id & -id);
    }
}

bool cmp1(const Point &a, const Point &b) {
    if (a.y != b.y)
        return a.y < b.y;
    if (a.x != b.x)
        return a.x < b.x;
    return a.id < b.id;
}

bool cmp2(const Point &a, const Point &b) {
    if (a.y != b.y)
        return a.y > b.y;
    if (a.x != b.x)
        return a.x > b.x;
    return a.id < b.id;
}

int get_best(Point points[], int ans[]) {
    fill(tree, tree + MAX_BIT, 0);
    vector < int > todo;
    for (int i = 0; i < n; i++) {
        ans[points[i].id] = 1 + bit_get(points[i].x + 1 - 1);
        todo.push_back(i);
        if (i == n - 1 || points[i].y != points[i + 1].y) {
            for (int j = 0; j < (int) todo.size(); j++)
                bit_update(points[todo[j]].x + 1, ans[points[todo[j]].id]);
            todo.clear();
        }
    }
    int best = 0;
    for (int i = 0; i < n; i++)
        best = max(best, ans[i]);
    return best;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        points[i] = Point(x + MAX_POS, y + MAX_POS, i);
    }

    sort(points, points + n, cmp1);
    int best = get_best(points, go);

    sort(points, points + n, cmp2);
    for (int i = 0; i < n; i++)
        points2[i] = Point(2*MAX_POS - points[i].x, points[i].y, points[i].id);
    get_best(points2, come);

    for (int i = 0; i < n; i++) if (go[points[i].id] + come[points[i].id] == best+1)
        am[go[points[i].id]]++;

    int ncan = 0, nwill = 0;
    for (int i = 0; i < n; i++) if (go[points[i].id] + come[points[i].id] == best+1) {
        can[points[i].id] = true;
        ncan++;
        if (am[go[points[i].id]] == 1) {
            will[points[i].id] = true;
            nwill++;
        }
    }

    printf("%d", ncan);
    for (int i = 0; i < n; i++) if (can[i])
        printf(" %d", i + 1);
    printf("\n");

    printf("%d", nwill);
    for (int i = 0; i < n; i++) if (will[i])
        printf(" %d", i + 1);
    printf("\n");

    return 0;
}
