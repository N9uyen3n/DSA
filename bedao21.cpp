#include <iostream>
#include <vector>
using namespace std;

// Sàng số nguyên tố để tìm các số nguyên tố nhỏ hơn n
vector<long long> primeFactorization() {
    const int n = 10000000; // Giới hạn số nguyên tố
    vector<bool> isPrime(n, true);
    vector<long long> primes;
    
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
        for (long long p : primes) {
            if (i * p >= n) break;
            isPrime[i * p] = false;
            if (i % p == 0) break;
        }
    }
    return primes;
}

int countDivisors(long long number, const vector<long long>& primes) {
    int totalDivisors = 1;
    for (long long prime : primes) {
        if (prime * prime > number) break;
        int exponent = 0;
        while (number % prime == 0) {
            exponent++;
            number /= prime;
        }
        if (exponent > 0) {
            totalDivisors *= (exponent + 1);
        }
    }
    if (number > 1) { 
        totalDivisors *= 2; 
    }
    return totalDivisors;
}


int main() {
    int t;
    cin >> t; // Nhập số lượng test case

    vector<long long> primes = primeFactorization(); // Tạo danh sách số nguyên tố trước

    while (t--) {
        long long number;
        cin >> number;

        if (number < 36) {
            cout << "NO\n";
            continue; // Bỏ qua số không hợp lệ
        }

        int count = countDivisors(number, primes);
        // cout << count << "\n";
        if (count == 9) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
