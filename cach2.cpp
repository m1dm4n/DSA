#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int findCircleNum(const vector<vector<int>> &mat)
{
    int n = mat.size(), provinces = 0;
    vector<bool> check(n, false);
    for (int i = 0; i < n; ++i)
    {
        if (check[i])
            continue;
        queue<int> city;
        city.push(i);
        check[i] = 1;

        while (!city.empty())
        {
            int cur = city.front();
            city.pop();
            for (int c = 0; c < n; ++c)
                if (mat[cur][c] && !check[c])
                {
                    check[c] = 1;
                    city.push(c);
                }
        }
        ++provinces;
    }
    return provinces;
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
