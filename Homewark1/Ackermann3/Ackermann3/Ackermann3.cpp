#include <iostream>
#include <chrono>  // 用來計算時間

using namespace std;

int Ackermann(int m, int n) // 自己製作一個遞迴的函示
{
    const long max = 100000;
    long x[max];  // 遞迴m的儲存值
    long y[max];  // 遞迴n的儲存值
    long top = 0;  // 遞迴存放數值的位置的初始值

    // 模擬遞迴，將初始的數值放入第0項
    x[top] = m;
    y[top] = n;
    top++; // 每一輪都+1使下一輪可以存放到下一項

    for (; top > 0;) // top大於0時，確保放在第0項以後
    {
        top--;  // top-1後取出最頂端的 m 和 n
        m = x[top];
        n = y[top];
        if (m == 0)
            n = n + 1; // A(0, n) = n + 1
        else if (n == 0)
        {
            // 若 m > 0 且 n = 0，則 A(m, 0) = A(m-1, 1)
            x[top] = m - 1;  // 將 A(m-1, 1) 放入遞迴
            y[top] = 1;
            top++; // 遞迴層數+1
        }
        else // 若 m > 0 且 n > 0，需計算 A(m-1, A(m, n-1))
        {
            // 先計算 A(m-1, -1)
            x[top] = m - 1;
            y[top] = -1;
            top++;
            // 接著計算內層 A(m, n-1)
            x[top] = m;
            y[top] = n - 1;
            top++;
        }
        if (top > 0 && y[top - 1] == -1) //如果遞迴頂端出現-1則結束，處理外層A(m-1, A(m, n-1))
        {
            top--;  // 將遞迴回到上一格
            y[top - 1] = n;  //用計算出的n值放入A(m-1, A(m, n-1))
        }
    }
    return n;
}

int main()
{
    int m, n;
    cout << "請輸入A(m,n): ";
    cin >> m >> n; // 輸入A(m,n)
    auto start = chrono::high_resolution_clock::now();// 計時開始
    int a = Ackermann(m, n);
    auto end = chrono::high_resolution_clock::now();// 計時結束
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();// 計算耗時

    cout << a << endl;
    cout << "程式運行時間: " << duration << " 微秒" << endl;

    return 0;
}