#include <iostream>

// 素数かどうかをチェックする関数
bool is_prime(int N) {
    if (N <= 1) return false;
    for (int p = 2; p*p <= N; ++p) {
        if (N % p == 0) return false;
    }
    return true;
}

int main(int, char**)
{
    int number;
    std::cout << "Enter your favarite number: ";
    std::cin >> number; 
    bool result = is_prime(number);
    std::cout << "prime number: " << std::boolalpha << result << std::endl;

    return 0;
}