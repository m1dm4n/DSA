#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int findCircleNum(const vector<vector<int>> &mat)
{
    int n = mat.size(), province = 0;
    vector<bool> check(n, false);
    stack<int> city;
    for (int i = 0; i < n; ++i)
    {
        if (check[i])
            continue;
        check[i] = 1;
        for (int j = 0; j < n; ++j)
        {
            if (j == i)
                continue;
            if (mat[i][j])
                city.push(j);
        }
        while (!city.empty())
        {
            int cur = city.top();
            city.pop();
            if (check[cur])
                continue;
            check[cur] = 1;
            for (int c = 0; c < n; ++c)
            {
                if (c == cur)
                    continue;
                if (mat[cur][c])
                    city.push(c);
            }
        }
        ++province;
    }
    return province;
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