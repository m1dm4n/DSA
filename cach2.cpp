#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int cnt = 0;

struct DSU {
    vector<int> root;
    vector<int> rank;
    
};

void uf(DSU &dsu, const int &n)
{
    dsu.root.resize(n);
    dsu.rank.resize(n);
    cnt = n;
    for (int i = 0; i < n; ++i)
    {
        dsu.root[i] = i;
        dsu.rank[i] = 1;
    }
}
int find(DSU &dsu, const int &a)
{
    if (a == dsu.root[a])
        return a;
    return dsu.root[a] = find(dsu, dsu.root[a]);
}
void uni(DSU &dsu, const int &a, const int &b)
{
    int roota = find(dsu, a), rootb = find(dsu, b);
    if (roota != rootb)
    {
        if (dsu.rank[roota] > dsu.rank[rootb])
            dsu.root[rootb] = roota;
        else if (dsu.rank[roota] < dsu.rank[rootb])
            dsu.root[roota] = rootb;
        else
        {
            dsu.root[rootb] = roota;
            ++dsu.rank[roota];
        }
        --cnt;
    }
}
int findCircleNum(vector<vector<int>> &mat)
{
    DSU dsu;
    int n = mat.size();
    uf(dsu, n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            if (mat[i][j])
                uni(dsu, i, j);
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];
    cout << "So luong cac tinh: " << findCircleNum(mat) << endl;

    return 0;
}