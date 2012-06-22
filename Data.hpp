#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include "Adapter.hpp"

#include<stdlib.h>

using namespace std;

class FacebookData{
	private:
		string accessToken;
		FacebookAdapter faceboookAdapter;
	public:
		FacebookData(string in_accessToken):accessToken(in_accessToken), faceboookAdapter(in_accessToken){}
		string getMyID(){
			Json::Value theJson;
			faceboookAdapter.getMyJson("profile", theJson);
			return theJson["id"].asString();
		}

		vector<string> getMyFriendIDList(){
			Json::Value theJson;
			faceboookAdapter.getMyJson("friends", theJson);
			
			vector<string> ret;
			for(unsigned i = 0; i < theJson["data"].size(); ++i){
				ret.push_back(theJson["data"][i]["id"].asString());
			}
			return ret;
		}

		
		vector<string> getMyFriendNameList(){
			Json::Value theJson;
			faceboookAdapter.getMyJson("friends", theJson);
			
			vector<string> ret;
			for(unsigned i = 0; i < theJson["data"].size(); ++i){
				ret.push_back(theJson["data"][i]["name"].asString());
			}
			return ret;
		}


		vector<string> getHisPostList(string id){
			Json::Value theJson;
			faceboookAdapter.getHisJson("feed", id, theJson);
		
			for(unsigned i = 0; i < theJson["data"].size(); ++i)
				cout << theJson["data"][i]["message"]<<endl;

			vector<string> ret;
			return ret;
		}

};


#endif //DATA_HPP
