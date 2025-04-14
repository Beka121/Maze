#include <iostream>
using namespace std;

long long sum_of_greatest_odd_divisors(long long n) {
    long long total = 0;
    for (long long i = 1; i <= n; ++i) {
        long long num = i;
        while (num % 2 == 0) {
            num /= 2;
        }
        total += num;
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
