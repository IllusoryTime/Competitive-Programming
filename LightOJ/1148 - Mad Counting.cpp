//Source Code Written: 1/19/17

#include <bits/stdc++.h>
using namespace std;
int main(){
//    freopen("in.txt", "r", stdin);
	int t, n, x, cnt, tc = 0;
	map <int, int> m;
	cin >> t;
	while(t--){
		printf("Case %d: ", ++tc);
		m.clear();
		cnt = 0;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> x;
			m[x]++;
			if(m[x] % (x+1) == 1) cnt += (x + 1);
		}
		if(cnt < n) cnt = n;
		cout << cnt << endl;
	}
	return 0;
}
