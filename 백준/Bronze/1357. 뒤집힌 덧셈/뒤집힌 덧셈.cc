#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int ten[4]={1000, 100, 10, 1};
	int n, m;
	cin >> n >> m;
	int arr[4]={0,};
	string ns=to_string(n), ms=to_string(m);
	int nslen=ns.length(), mslen=ms.length(), nindex=nslen-1, mindex=mslen-1;
	for(int i=4-nslen;i<=3;i++) arr[i]+=(ns[nindex--]-'0');	
	for(int i=4-mslen;i<=3;i++) arr[i]+=(ms[mindex--]-'0');
	for(int i=3;i>0;i--) {
		if (arr[i]>=10) {
			arr[i]-=10;
			arr[i-1]++;
		} 
	}
	int ans=0;
	for(int i=3;i>=0;i--) ans+=ten[i]*arr[i];
	string sans=to_string(ans);
	int index=sans.length()-1;
	while (sans[index]=='0') index--;
	for(int i=index;i>=0;i--) cout << sans[i];
} 