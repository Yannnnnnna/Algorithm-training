//
// Created by WYR on 2025/3/11.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define N 5005
#define INF 0x7ffffff
using namespace std;
double dist[N];     //距离数组
bool visit[N]; //是否加入数组
int n;
int p[N][2];  //存储坐标点
double calcDist(int u, int v) {
    int x1 = p[u][0], x2 = p[v][0];
    int y1 = p[u][1], y2 = p[v][1];
    // 将整数算术与 double 计算混合在一起，这可能会导致精度问题。
    return sqrt((double)(x1 - x2)*(x1 - x2) + (double)(y1 - y2)*(y1 - y2));
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &p[i][0], &p[i][1]);
    }
    //初始化距离数组
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;
    visit[1] = true;
    double minDist;
    //起点到其他点的最短距离
    for (int i = 2; i <= n ; ++i) {
        minDist = calcDist(i, 1);
        if(dist[i] > minDist){
            dist[i] = minDist;
        }
    }
    //min 是最短距离，ans答案
    double  min, ans = 0;
    int minNode = -1;   /*选中的节点*/
    //至少找n - 1次
    for (int i = 1; i <= n - 1; ++i) {
        min = INF;
        //找到距离最短的节点
        for (int j = 1; j <= n ; ++j) {
            if(visit[j] == 0 && dist[j] < min){
                minNode = j;
                min = dist[j];
            }
        }
        ans += min;
        visit[minNode] = 1;
        //寻找下一个最短距离，计算与其他点的距离
        for (int j = 1; j <= n ; ++j) {
            if(visit[j] == 0 && dist[j] > calcDist(j,minNode)){
                dist[j] = calcDist(j, minNode);
            }
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}
/*下面为简洁版答案*/

//#include <iostream>
//#include <cstdio>
//#include <cmath>
//#define N 5005
//#define INF 1e9
//using namespace std;
//
//double dist[N];     // 距离数组
//bool visit[N];      // 是否加入MST的标记
//int n;
//int p[N][2];        // 存储坐标点
//
//double calcDist(int u, int v) {
//    int x1 = p[u][0], x2 = p[v][0];
//    int y1 = p[u][1], y2 = p[v][1];
//    // Cast to double before multiplication to avoid overflow
//    return sqrt((double)(x1 - x2)*(x1 - x2) + (double)(y1 - y2)*(y1 - y2));
//}
//
//int main() {
//    scanf("%d", &n);
//    for(int i = 1; i <= n; i++) {
//        scanf("%d %d", &p[i][0], &p[i][1]);
//    }
//
//    // 初始化距离数组 - 只设置第一个点的距离为0，其他为INF
//    for (int i = 1; i <= n; i++) {
//        dist[i] = INF;
//        visit[i] = false;
//    }
//    dist[1] = 0;  // 选择1号点为起始点
//
//    double ans = 0;
//    int minNode;
//
//    // 对每个点执行Prim算法
//    for (int i = 1; i <= n; i++) {
//        double minDist = INF;
//
//        // 找到距离最短的未访问节点
//        for (int j = 1; j <= n; j++) {
//            if (!visit[j] && dist[j] < minDist) {
//                minNode = j;
//                minDist = dist[j];
//            }
//        }
//
//        visit[minNode] = true;
//        ans += minDist;
//
//        // 更新所有点到MST的距离
//        for (int j = 1; j <= n; j++) {
//            double newDist = calcDist(minNode, j);
//            if (newDist < dist[j]) {
//                dist[j] = newDist;
//            }
//        }
//    }
//
//    printf("%.2lf\n", ans);
//    return 0;
//}