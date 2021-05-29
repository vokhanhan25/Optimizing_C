#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

int myrandom (int i) { return std::rand()%i;}

int LinearSearch (vector<int> a, int n, int x) {
    for (int i = 0; i < n; i++)
        if (a[i] == x)   
            return i;
    return -1;
}

int BinarySearch (vector<int> a, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (a[mid] == x) 
            return mid;

        if (a[mid] < x) 
            l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    freopen("output.txt", "w", stdout);
    vector<string> inp = {"n1000", "n10000", "n100000", "n1000000"};
    int n, x, value, testcase;
    double mean_binary, mean_linear, stdev_binary, stdev_linear, total_time_linear, total_time_binary;
    double max_binary, max_linear, min_binary, min_linear;
    vector<double> time_linear, time_binary;
    vector<int> a;
    testcase = 10;
    for (int file_index = 0; file_index < inp.size(); file_index++) {
        string file_name_tm = "data/" + inp[file_index] + ".txt";
        cout << file_name_tm << "\n";
        char* file_name = &file_name_tm[0];
        freopen(file_name, "r", stdin);
        
        
        int loop = 10;
        while (loop--) {
            cin >> n >> x;
            for (int i = 0; i < n; i++) {
                cin >> value;
                a.push_back(value);
            }

            auto start = high_resolution_clock::now();
            BinarySearch(a, 0, n - 1, x);
            auto stop = high_resolution_clock::now();
            duration<double> elapsed = (stop - start);
            time_binary.push_back(elapsed.count());
            total_time_binary += elapsed.count();

            start = high_resolution_clock::now();
            LinearSearch(a, n, x);
            stop = high_resolution_clock::now();
            elapsed = (stop - start);
            time_linear.push_back(elapsed.count());
            total_time_linear += elapsed.count();

            a.clear();
            a.shrink_to_fit();
        }
        stdev_linear = 0;
        stdev_binary = 0;
        mean_linear = total_time_linear / testcase;
        mean_binary = total_time_binary / testcase;
        max_binary = max_linear = 0.0;
        min_binary = min_linear = 1000.0;
        for (int i = 0; i < testcase; i++) {
            stdev_linear += (time_linear[i] - mean_linear) * (time_linear[i] - mean_linear);
            stdev_binary += (time_binary[i] - mean_binary) * (time_binary[i] - mean_binary);
            // if (max_linear < time_linear[i])
            //     max_linear = time_linear[i];

            // if (max_binary < time_binary[i])
            //     max_binary = time_binary[i];

            // if (min_linear > time_linear[i])
            //     min_linear = time_linear[i];

            // if (min_binary > time_binary[i])
            //     min_binary = time_binary[i];
            max_linear = max(max_linear, time_linear[i]);
            max_binary = max(max_binary, time_binary[i]);
            min_linear = min(min_linear, time_linear[i]);
            min_binary = min(min_binary, time_binary[i]);
            // cout << time_linear[i] << "\n";
        }
        

        stdev_linear = sqrt(stdev_linear / testcase);
        stdev_binary = sqrt(stdev_binary / testcase);

        cout << "Linear Search: \n";
        // cout << "Max time =  " << max_linear << "\n";
        // cout << "Min time = " << min_linear << "\n";
        cout << "Total time = " << total_time_linear << "\n";
        cout << "Standard deviation = " << stdev_linear << "\n";

        cout << "\n";
        cout << "Binary Search: \n";
        // cout << "Max time =  " << max_binary << "\n";
        // cout << "Min time = " << min_binary << "\n";
        cout << "Total time = " << total_time_binary << "\n";
        cout << "Standard deviation = " << stdev_binary << "\n";
        cout << "/------------------------------------------/\n\n";
    }
}