#include<iostream>
#include<fstream>

#include"Adapter.hpp"
#include"Data.hpp"

int main(int argc, char* argv[]){


	FacebookData facebookData(argv[1]);
	cout <<	facebookData.getMyID() << endl; 
	vector<string> idList = facebookData.getMyFriendIDList();
	for(unsigned i = 0; i < idList.size(); ++i){
		cout << idList.at(i) << endl;
	}

	facebookData.getHisPostList("348900326");

/*
	FacebookAdapter* facebookAdapter = new FacebookAdapter(argv[1]);
	Json::Value friendList;
	facebookAdapter->getMyJson("friends", friendList);

	printf("# friends %d\n", friendList["data"].size());


	/**
	for(unsigned i = 0; i < friendList["data"].size(); ++i){
		cout << "id = " << friendList["data"][i]["id"] << endl;
	}**/

	Json::Value tmp;
	//facebookAdapter->getMyJson("feed", tmp);
	return 0;
}
