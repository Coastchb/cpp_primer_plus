#include <iostream>
#include <random>
using namespace std;


int main() {
    srand((unsigned)time(NULL));

    int neg_cnt = 0, total_cnt = 0;
    for (int i = 0; i < 1000000; i++) {
        total_cnt += 1;
        double v = rand() / static_cast<double>(RAND_MAX);
        cout << v << endl;
        if (v >= 0.010101) {
            continue;
        } else {
            // neg_cnt += 1;
        }
    }
    
    cout << "total_cnt:" << total_cnt << ";neg_cnt:" << neg_cnt << endl;
    
}

