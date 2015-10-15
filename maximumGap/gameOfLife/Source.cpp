#include<iostream>
#include<string>
using namespace std;

int main(){
	int n;
	cin >> n;
	while (n-- > 0){
		int nums[256] = { 0 };
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++){
			if (nums[str[i]] == 0){
				cout << str[i];
				nums[str[i]]++;
			}
		}
		cout << endl;
	}
	return 0;
}