#include <iostream>
#include <string>
#include <chrono>//用於計算運行時間的函示庫

using namespace std;
using namespace chrono;

const int MAX = 20;//預設集合最大元素數量

void powerset(string A[], int n)//使用非遞迴的方法 
{
    int all = 1 << n; //用位元運算計算2^n
    for (int i = 0; i < all; i++) //挑出所有可能的子集合
    {
        cout << "("; // 開始輸出一個子集合
        bool a = true; // 標記子集合中的第一個元素，用於格式控制
        for (int j = 0; j < n; j++) // 檢查元素加入當前子集合
        {
            if (i & (1 << j)) //如果為1，則表示 A[j]在子集合中
            {  
                if (!a) //如果不是第一個元素則隔開元素
                    cout << ",";
                cout << A[j];
                a = false;//用來表示之後的元素不是第一個元素
            }
        }
        cout << ")"; // 結束當前子集合的輸出
    }
}

int main() {
    string A[MAX];
    int n = 0;
    cout << "輸入集合A：";
    string all;
    getline(cin, all); //輸入整行
    size_t such = 0; // 用來存放找到空格的位置
    while ((such = all.find(" ")) != string::npos && n < MAX)//判斷空格分開每個元素 
    {
        A[n++] = all.substr(0, such); //將空格之前的字串儲存到陣列中
        all.erase(0, such + 1); // 刪除已儲存過的並處理剩餘的字串
    }
    if (n < MAX)
        A[n++] = all; //將最後一個元素加入陣列
    auto start = high_resolution_clock::now();//計算程式運行時間的起始點
    cout << "(S)={";
    powerset(A, n);//生成子集合
    cout << "}" << endl;
    auto end = high_resolution_clock::now();//計算程式運行時間的結束點
    auto duration = duration_cast<milliseconds>(end - start).count();//計算已消耗時間
    cout << "運行時間: " << duration << " 毫秒" << endl;
    return 0;
}