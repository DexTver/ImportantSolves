#include <iostream>
#include <vector>
using namespace std;

vector <int> mas;
//codeforces ругается
void merge(int i, int j)
{
    vector <int> b;
    int m = (i + j) / 2;
    int l = i, r = m + 1;
    while (l <= m)
        if (r <= j && mas[r] >= mas[l])
        {
            b.push_back(mas[r]);
            r++;
        }
        else
        {
            b.push_back(mas[l]);
            l++;
        }
    while (r <= j)
    {
        b.push_back(mas[r]);
        r++;
    }
    int s = 0;
    for (int x = i; x <= j; x++)
    {
        mas[x] = b[s];
        s++;
    }
    return;
}

void merge_sort(int i, int j)
{
    int m;
    if (j == i)
    {
        return;
    }
    m = (i + j) / 2;
    merge_sort(i, m);
    merge_sort(m + 1, j);
    merge(i, j);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        int t;
        cin >> t;
        mas.push_back(t);
    }
    merge_sort(0, n - 1);
    for (int x = 1; x <= n; x++)
    {
        cout << mas[n - x] << " ";
    }
    return 0;
}