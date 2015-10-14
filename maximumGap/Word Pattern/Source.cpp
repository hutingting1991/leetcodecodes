#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution{
public:
	bool wordPattern(string pattern, string str){
		map<char, string> mymap;
		int i = 0, j = 0;
		for (int k = 0; k < pattern.size(); k++){
			if (j >= str.size())
				return false;
			char c = pattern[k];
			while (j<str.size() && str[j] != ' ')
				j++;
			string sub = str.substr(i, j - i);
			if (mymap[c] == ""){
				for (auto it : mymap)
					if (it.second == sub)
						return false;
				mymap[c] = sub;
			}
			else if (mymap[c] != sub)
				return false;
			j++;
			i = j;
		}
		if (j < str.size() + 1)
			return false;
		return true;
	}
};

int main(){
	string pattern = "jquery";
	string str = "jquery";
	Solution* s = new Solution();
	if (s->wordPattern(pattern, str))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}