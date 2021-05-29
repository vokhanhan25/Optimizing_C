#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

int myrandom (int i) { return std::rand()%i;}

int a[100000005];

int main() {
    freopen("output.txt", "w", stdout);
    int i, j, x, n = 10000000;
    int loop = 10, testcase = 10, t = 2;
    double total_time_not_optimized = 0, total_time_optimized = 0;
    vector<double> time_optimized, time_not_optimized;
    double stdev_optimized = 0;
    double stdev_not_optimized = 0;
        
        while (loop--) {        
            auto start = high_resolution_clock::now();
            
            for (i = 0; i < n; ++i) {
                j = 100;
                a[i] = i + j + x * x;
            }

            auto stop = high_resolution_clock::now();
            duration<double> elapsed = (stop - start);
            time_not_optimized.push_back(elapsed.count());
            total_time_not_optimized += elapsed.count();

            start = high_resolution_clock::now();
            
            j = 100;
            int tmp = j * x * x;
            for(i = 0; i < n; ++i) {
                a[i] = i + tmp;
            }

            stop = high_resolution_clock::now();
            elapsed = (stop - start);
            time_optimized.push_back(elapsed.count());
            total_time_optimized += elapsed.count();

        stdev_optimized = 0;
        stdev_not_optimized = 0;
        double mean_optimized = total_time_optimized / testcase;
        double mean_not_optimized = total_time_not_optimized / testcase;
        for (int i = 0; i < testcase; i++) {
            stdev_optimized += (time_optimized[i] - mean_optimized) * (time_optimized[i] - mean_optimized);
            stdev_not_optimized += (time_not_optimized[i] - mean_not_optimized) * (time_not_optimized[i] - mean_not_optimized);
        }
        }
        cout << "n = " << n << "\n";
        cout << "Optimized: \n";
        // cout << "Max time =  " << max_2 << "\n";
        // cout << "Min time = " << min_2 << "\n";
        cout << "Total time = " << total_time_optimized << "\n";
        cout << "Standard deviation = " << stdev_optimized << "\n";
        cout << "\n";
        cout << "Not optimizedh: \n";
        // cout << "Max time =  " << max_1 << "\n";
        // cout << "Min time = " << min_1 << "\n";
        cout << "Total time = " << total_time_not_optimized << "\n";
        cout << "Standard deviation = " << stdev_not_optimized << "\n";
        cout << "/------------------------------------------/\n\n";

}