#include <iostream>
#include <vector>
#include <string>

using namespace std;

string postVisit(string& sp, string& sm){

	if(sp.size() <= 1 || sm.size() <= 1)
		return sp;

	char root = sp[0];
	int idx = 0;
	while(sm[idx] != root) idx++;
	string spl = "", spr = "", sml = "", smr = "";
	spl = sp.substr(1, idx);
	spr = sp.substr(1 + idx);
	sml = sm.substr(0, idx);
	smr = sm.substr(1 + idx);
	return postVisit(spl, sml) + postVisit(spr, smr) + root;
}

int main()
{
	string pref, mid;
	cin>>pref>>mid;

	string res = postVisit(pref, mid);
	cout<<res<<endl;
	return 0;
}