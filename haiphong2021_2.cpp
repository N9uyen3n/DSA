#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Hàm sử dụng Sàng Euler để tạo danh sách số nguyên tố từ 2 đến n-1
vector<int> sievePrimes(int n) {
    vector<bool> isPrime(n, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
        // Duyệt qua các số nguyên tố đã tìm được (theo thứ tự tăng dần)
        for (int k : primes) {
            if (k * i >= n) break;
            isPrime[k * i] = false;
            if (i % k == 0) break;
        }
    }
    return primes;
}

// Hàm tạo tập hợp số nguyên tố dưới dạng unordered_set để tìm kiếm nhanh
unordered_set<int> primeFactorization() {
    int n = 10000000;
    vector<int> primesList = sievePrimes(n);
    unordered_set<int> primes(primesList.begin(), primesList.end());
    return primes;
}

// Hàm kiểm tra số Super Prime
int isSuperPrime(int number, const unordered_set<int>& primes) {
    int count = 0, number1 = number;
    
    // Kiểm tra nếu số ban đầu không phải là số nguyên tố
    if (primes.find(number) == primes.end()) {
        return 0;
    }
    
    // Kiểm tra nếu thêm một chữ số vào cuối vẫn là số nguyên tố
    for (int i = 1; i < 10; ++i) {
        if (primes.find(number * 10 + i) != primes.end()) {
            count++;
            break;
        }
    }
    
    // Kiểm tra nếu loại bỏ từng chữ số cuối vẫn là số nguyên tố
    while (number1 > 0) {
        if (primes.find(number1) == primes.end()) {
            break;
        }
        number1 /= 10;
    }
    
    if (number1 == 0) count++;
    
    return (count == 2) ? 1 : 0;
}

int main()
{
    int n = 0, t = 0, u = 0, v = 0;
    cin >> n;
    
    unordered_set<int> primes = primeFactorization();
    vector<int> prefixSum(n + 1);

    for (int i = 0; i < n; ++i) {   
        int a;
        cin >> a;
        prefixSum[i + 1] = prefixSum[i] + isSuperPrime(a, primes);
  		
    }

    cin >> t;
    for (int i = 0; i < t; ++i)
    {
    	cin >> u >> v;
    	cout << prefixSum[v] - prefixSum[u - 1] << "\n";
    }
    
    return 0;
}
