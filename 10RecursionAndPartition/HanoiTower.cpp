//
// Created by WYR on 2025/2/15.
//
#include <iostream>
#include <vector>
using namespace std;
void move(int n,vector<int>& A, vector<int>& B, vector<int>& C){
    /*递归出口*/
    if(n ==1 ){
        int x = A.back();
        A.pop_back();
        C.push_back(x);
        return;
    }
//    将A上的n-1个盘子通过C移到B
    move(n - 1, A, C, B);
//    将A上的最后一个盘子移到C
    move(1, A, B, C);
//    将B上的n-1个盘子通过A移到C
    move(n - 1, B, A, C);

}
void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
    int n = A.size();
    move(n, A, B, C);/*解决大问题*/
}
int main(){
    int n, x, k;
    vector<int> A, B, C;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        A.push_back(x);
    }
    hanota(A, B, C);
    for (int i = 0; i < n; ++i) {
        cout << C[i] << " ";
    }
    return 0;
}