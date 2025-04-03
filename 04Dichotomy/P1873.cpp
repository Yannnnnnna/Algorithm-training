#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
ll n,m;
ll ans;
ll maxt;
ll tree[1000005];
int check(ll x){
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		if(tree[i] > x){
			sum += tree[i] - x;
		}
	}
	if(sum >= m){
		return 1;
	}
	return 0;
}
int main(){
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i<= n; i++){
		scanf("%lld", &tree[i]);
		maxt = max(maxt, tree[i]);
	}
	ll l = 1, r = maxt;
	while(l <= r){
		ll mid = (l + r) >> 1;
        //可以满足木材需求，抬高锯子
		if(check(mid)){
			l = mid + 1;
			ans = max(ans, mid);
		}else{
			r = mid - 1;
		}
		
	} 
	cout << ans <<endl;
	return 0;
} 
