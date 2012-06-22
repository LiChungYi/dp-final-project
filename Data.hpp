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
			while(1){
				for(unsigned i = 0; i < theJson["data"].size(); ++i){
					ret.push_back(theJson["data"][i]["id"].asString());
				}
				theJson = theJson["paging"]["next"];
				if(theJson.isNull())
					break;
				string url = theJson.asString();
				faceboookAdapter.getNextJson(url, theJson);
			}
			return ret;
		}

		
		vector<string> getMyFriendNameList(){
			Json::Value theJson;
			faceboookAdapter.getMyJson("friends", theJson);
			
			vector<string> ret;
			while(1){
				for(unsigned i = 0; i < theJson["data"].size(); ++i){
					ret.push_back(theJson["data"][i]["name"].asString());
				}
				theJson = theJson["paging"]["next"];
				if(theJson.isNull())
					break;
				string url = theJson.asString();
				faceboookAdapter.getNextJson(url, theJson);
			}
			return ret;
		}


		vector<string> getHisPostList(string id){
			Json::Value theJson;
			faceboookAdapter.getHisJson("feed", id, theJson);
		
			vector<string> ret;
			while(1){
				for(unsigned i = 0; i < theJson["data"].size(); ++i){
					ret.push_back(theJson["data"][i]["message"].asString());
				}
				theJson = theJson["paging"]["next"];
				if(theJson.isNull())
					break;
				string url = theJson.asString();
				faceboookAdapter.getNextJson(url, theJson);
			}
			return ret;
		}

};


#endif //DATA_HPP
