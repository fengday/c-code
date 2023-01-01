#include<bits/stdc++.h> 
using namespace std;

int main(){
	int sum=0;
	for(int i=1;i<=2020;i++){
		stringstream ss;
		ss << i;
		string s;
		ss >> s;
		for(int j=0;j<s.length();j++) {
			if(s[j]=='2') sum++;
		}
	}
	cout << sum;
}

