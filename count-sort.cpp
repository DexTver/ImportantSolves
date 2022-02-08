#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> hlp(101);
    int n, x;
    /*cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        hlp[x]++;
    }*/
    while (cin >> x){
        hlp[x]++;
    }
    for (int i = 0; i < 101; i++){
        for (int j = 0; j < hlp[i]; j++){
            cout << i << " ";
        }
    }

    return 0;
}