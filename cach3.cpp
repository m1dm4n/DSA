#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct DSU {
    vector<int> root;   
    int numberOfProvince;
};

void Create_DSU(DSU &dsu, const int &n)
{
    dsu.root.resize(n);
    dsu.numberOfProvince = n;
    for (int i = 0; i < n; ++i)
        dsu.root[i] = i;
}

int Find(DSU &dsu, const int &a)
{
    if (a == dsu.root[a])
        return a;
    return dsu.root[a] = Find(dsu, dsu.root[a]);
}
void Union(DSU &dsu, const int &a, const int &b)
{
    int roota = Find(dsu, a), rootb = Find(dsu, b);
    if (roota != rootb)
    {
        dsu.root[rootb] = roota;
        --dsu.numberOfProvince;
    }
}

int findCircleNum(vector<vector<int>> &mat)
{
    DSU dsu;
    int n = mat.size();
    Create_DSU(dsu, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (mat[i][j])
                Union(dsu, i, j);
    return dsu.numberOfProvince;
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