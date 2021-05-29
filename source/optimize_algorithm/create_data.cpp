#include <iostream>
#include <stdlib.h>     
#include <time.h> 
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("data/n1000000.txt", "w", stdout);
    srand (time(NULL));
    vector<int> a;
    int n = 1000000;
    int x;
        for (int k = 0; k < 10; k++) {
            for (int i = 0; i < n; i++) {
                x = rand() % 1000000;
                a.push_back(x);
            }
            x = a[rand() % (a.size())];
            
            sort (a.begin(), a.end());
            cout << n << " ";
            if (k < 5)
                cout << x << "\n";
            else
                cout << -1 << "\n";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << "\n";
            a.clear();
            a.shrink_to_fit();
        }
}