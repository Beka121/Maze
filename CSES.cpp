#include <iostream>
using namespace std;

long long sum_of_greatest_odd_divisors(long long n) {
    long long total = 0;
    while (n > 0) {
        
        long long block_size = n - (n / 2);
        total += block_size * (n % 2 + (n / 2) % 2);
        n /= 2;
    }
    return total;
}

int main() {
    long long n;
    while (cin >> n) {
        cout << sum_of_greatest_odd_divisors(n) << endl;
    }
    return 0;
}
