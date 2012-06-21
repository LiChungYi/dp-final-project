#include"Adaptor.hpp"
#include<iostream>
#include<fstream>

int main(){
	FacebookAdaptor* fa = new FacebookAdaptor ;
	Json::Value friendList;
	fa->getFriendList(friendList);
	for(unsigned i = 0; i < friendList["data"].size(); ++i){
		cout << "id = " << friendList["data"][i]["id"] << endl;
	}
//	ofstream outfile ("test.txt");
//	outfile.close();
}
