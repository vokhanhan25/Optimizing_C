#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <chrono>
#include <algorithm>
#include <stdlib.h>
using namespace std;
using namespace std::chrono;

int myrandom (int i) { return std::rand()%i;}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int a[100000005], c[100000005];


int main() {
    freopen("output.txt", "w", stdout);
    vector<string> inp = {"n1000", "n10000", "n100000", "n1000000"};
    
    int n, x, value, testcase;
    double mean_sort, mean_qsort, stdev_sort, stdev_qsort, total_time_qsort, total_time_sort;
    double max_sort, max_qsort, min_sort, min_qsort;
    vector<double> time_qsort, time_sort;
    testcase = 10;
    
    for (int file_index = 0; file_index < inp.size(); file_index++) {
        string file_name_tm = "data/" + inp[file_index] + ".txt";
        cout << file_name_tm << "\n";
        char* file_name = &file_name_tm[0];
        freopen(file_name, "r", stdin);
        
        
        int loop = 10;
        while (loop--) {
            cin >> n;
            for (int i = 0; i < n; i++) {
                cin >> value;
                a[i] = value;
                c[i] = value;
            }
            auto start = high_resolution_clock::now();
            sort(a, a + n);
            auto stop = high_resolution_clock::now();
            duration<double> elapsed = (stop - start);
            time_sort.push_back(elapsed.count());
            total_time_sort += elapsed.count();

            
            start = high_resolution_clock::now();
            qsort(c, n, sizeof(int), compare);
            stop = high_resolution_clock::now();
            elapsed = (stop - start);
            time_qsort.push_back(elapsed.count());
            total_time_qsort += elapsed.count();
        }
        stdev_qsort = 0;
        stdev_sort = 0;
        mean_qsort = total_time_qsort / testcase;
        mean_sort = total_time_sort / testcase;
        max_sort = max_qsort = 0.0;
        min_sort = min_qsort = 1000.0;
        for (int i = 0; i < testcase; i++) {
            stdev_qsort += (time_qsort[i] - mean_qsort) * (time_qsort[i] - mean_qsort);
            stdev_sort += (time_sort[i] - mean_sort) * (time_sort[i] - mean_sort);
            // if (max_qsort < time_qsort[i])
            //     max_qsort = time_qsort[i];

            // if (max_sort < time_sort[i])
            //     max_sort = time_sort[i];

            // if (min_qsort > time_qsort[i])
            //     min_qsort = time_qsort[i];

            // if (min_sort > time_sort[i])
            //     min_sort = time_sort[i];
            max_qsort = max(max_qsort, time_qsort[i]);
            max_sort = max(max_sort, time_sort[i]);
            min_qsort = min(min_qsort, time_qsort[i]);
            min_sort = min(min_sort, time_sort[i]);
            // cout << time_qsort[i] << "\n";
        }
        

        stdev_qsort = sqrt(stdev_qsort / testcase);
        stdev_sort = sqrt(stdev_sort / testcase);

        cout << "qsort: \n";
        // cout << "Max time =  " << max_qsort << "\n";
        // cout << "Min time = " << min_qsort << "\n";
        cout << "Total time = " << total_time_qsort << "\n";
        cout << "Standard deviation = " << stdev_qsort << "\n";

        cout << "\n";
        cout << "sort: \n";
        // cout << "Max time =  " << max_sort << "\n";
        // cout << "Min time = " << min_sort << "\n";
        cout << "Total time = " << total_time_sort << "\n";
        cout << "Standard deviation = " << stdev_sort << "\n";
        cout << "/------------------------------------------/\n\n";
    }
}