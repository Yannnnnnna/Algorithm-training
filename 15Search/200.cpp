//
// Created by WYR on 2025/3/3.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void dfs(vector<vector<char>>& grid, int i, int j){
    int n = grid.size();
    int m = grid[0].size();
    grid[i][j] = '0';

    if(i - 1 >= 0 && grid[i - 1][j] == '1') dfs(grid, i - 1,j);
    if(i + 1 < n && grid[i + 1][j] == '1') dfs(grid, i + 1,j);
    if(j - 1 >= 0 && grid[i][j - 1] == '1') dfs(grid, i,j - 1);
    if(j + 1 < m && grid[i][j + 1] == '1') dfs(grid, i,j + 1);
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(grid[i][j] == '1'){
                res++;
                dfs(grid, i, j);
            }
        }
    }
    return res;
}

int main(){
    int n,m;
    scanf("%d%d", &n, &m);
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            getchar();
            scanf("%c", &g[i][j]);
        }
    }
    int res = numIslands(g);
    printf("%d\n", res);
    return 0;
}