#include <iostream>
using namespace std;
int main(){
	int tCase(0);
	cin>>tCase;
	while(tCase--){
		int n;
		cin>>n;
		int arr[n];
		for(int i = 0;i<n;i++)
			cin>>arr[i];
		int fineCount(0);
		for(int i = 0;i<n;i++){
			if(arr[i] == 0){
				fineCount = n-i;
				break;
			}
		}
		int monthCount = 0;
		for(int i = 0; i<n; i++)
			if(arr[i] == 0)
				monthCount+=1;
		int dues = monthCount*1000 + fineCount*100;
		cout<<dues<<endl;
	}
	return 0;
}