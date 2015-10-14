#include <iostream>
#include<string>
#include<map>
using namespace std;

class Solution{
public:
	bool isIsomorphic(string s, string t){
		if (s.size() != t.size())
			return false;
		map<char, char> mymap;
		for (int i = 0; i < s.size(); i++){
			if (mymap.find(s[i]) == mymap.end()){
				for (auto it : mymap)
					if (it.second == t[i])
						return false;
				mymap[s[i]] = t[i];
			}
			else if (mymap[s[i]] != t[i])
				return false;
		}
		return true;
	}
};