#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Ackermann 函數的遞迴版本實作
int Ackermann(int m, int n)
{
    if (m == 0)
        return n + 1;  // A(0, n) = n + 1
    else if (m > 0 && n == 0)
        return Ackermann(m - 1, 1);  // A(m, 0) = A(m-1, 1)
    else
        return Ackermann(m - 1, Ackermann(m, n - 1));  // A(m, n) = A(m-1, A(m, n-1))
}

int main() {
    int m, n;
    cout << "請輸入 A(m,n): ";
    cin >> m >> n;
    auto start = high_resolution_clock::now();// 計時開始
    int flnal = Ackermann(m, n); 
    auto stop = high_resolution_clock::now();// 計時結束
    auto duration = duration_cast<microseconds>(stop - start); // 計算以微秒為單位的時間
  
    cout << flnal << endl; // 輸出計算結果
    cout << "運行時間: " << duration.count() << " 微秒" << endl; // 輸出運行時間
    return 0;
}