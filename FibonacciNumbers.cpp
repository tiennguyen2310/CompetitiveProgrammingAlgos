#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define fi first
#define se second
#define int ll
 
const int MOD = 1e9 + 7;
 
struct Matrix
{
    vector <vector <int> > v;
 
    Matrix(int row, int col)
    {
        v.resize(row + 1, vector <int>(col + 1, 0));
    }
    int row() const
    {
        return v.size() - 1;
    }
    int col() const
    {
        return v[0].size() - 1;
    }
    Matrix operator * (Matrix &b)
    {
        Matrix a = *this;
        Matrix res(a.row(), b.col());
        for(int i = 1; i <= a.row(); i++)
        {
            for(int j = 1; j <= b.col(); j++)
            {
                for(int k = 1; k <= a.col(); k++)
                {
                    res.v[i][j] = (res.v[i][j] + a.v[i][k] * b.v[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};
 
int n;
 
Matrix Pow(Matrix a, int b)
{
    if(b == 0)
    {
        Matrix res(a.row(), a.col());
        for(int i = 1; i <= a.row(); i++)
        {
            for(int j = 1; j <= a.col(); j++)
            {
                if(a.v[i][j] != 0) res.v[i][j] = 1;
            }
        }
        return res;
    }
    if(b == 1)return a;
    Matrix res = Pow(a, b / 2);
    res = res * res;
    if(b % 2 != 0) res = res * a;
    return res;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
    if(n == 0)
    {
        cout << 0;
        return 0;
    }
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    Matrix Coso(2, 2);
    Coso.v[1][1] = 1;
    Coso.v[1][2] = 1;
    Coso.v[2][1] = 1;
    Coso.v[2][2] = 0;
    Matrix Heso(2, 1);
    Heso.v[1][1] = 1;
    Heso.v[2][1] = 0;
    Coso = Pow(Coso, n - 1);
    Matrix res = Coso * Heso;
    cout << res.v[1][1];
}
