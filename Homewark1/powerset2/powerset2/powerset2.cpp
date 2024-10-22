#include <iostream>
#include <string>
#include <chrono>//用於計算運行時間的函式庫

using namespace std;
using namespace chrono;

const int MAX = 20;//預設集合最大元素數量

// A[]:A集合的元素陣列
// n:A集合的元素數量
// x:用來當目前處理到A集合中哪個元素的所引值
// B[]:用來存放當前子集合的陣列
// size: 當前子集合的大小
void powerset(string A[], int n, int x, string B[], int size)//使用遞迴的方法
{
    //輸出一項子集合
    cout << "(";
    for (int i = 0; i < size; i++) 
    {
        cout << B[i];//輸出子集合的每個元素
        if (i < size - 1) 
            cout << ",";
    }
    cout << ")";//結束子集合輸出 
    for (int i = x; i < n; i++)//生成新的子集合 
    {
        B[size] = A[i];  // 將當前元素加入子集合
        powerset(A, n, i + 1, B, size + 1);//遞迴呼叫，處理一輪新的子集合
    }
}

int main() {
    string A[MAX];//用來儲存輸入的集合
    int n = 0;  //輸入集合的元素個數
    cout << "輸入集合A：";
    string all;//用來存整串字的
    getline(cin, all);//讀取整行輸入
    size_t such = 0;//such用於追蹤空格的位置
    while ((such = all.find(' ')) != string::npos && n < MAX) {
        A[n++] = all.substr(0, such);//從取空格前一個元素並加入集合中
        all.erase(0, such + 1);//刪除已經取過的元素
    }
    if (n < MAX)
        A[n++] = all;//如果還有剩餘的元素則加入最後一個
    auto start = high_resolution_clock::now();  // 記錄程式運行的起始時間
    //生成子集合的起點
    cout << "(S)={";//開始輸出集合的所有子集合
    string B[MAX];//暫存子集合的陣列
    powerset(A, n, 0, B, 0);//呼叫powerset函式來生成所有子集合
    cout << "}" << endl;
    auto end = high_resolution_clock::now();  // 記錄程式運行的結束時間
    auto duration = duration_cast<milliseconds>(end - start);  // 計算總運行時間
    cout << "\n運行時間：" << duration.count() << " 毫秒" << endl;  // 輸出運行時間
    return 0;
}