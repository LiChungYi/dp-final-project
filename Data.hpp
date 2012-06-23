#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <sstream>
#include <stdlib.h>

#include "Adapter.hpp"
#include "User.hpp"
#include "Post.hpp"

using namespace std;

class FacebookData{
	private:
		string accessToken;
		FacebookAdapter faceboookAdapter;

		/*
		inline vector<string> getJsonFieldAsVector(Json::Value theJson, string fieldName){
			vector<string> ret;
			while(1){
				for(unsigned  i =0; i < theJson["data"].size(); ++i){
					ret.push_back(theJson["data"][i][fieldName].asString());
				}
				theJson = theJson["paging"]["next"];
				if(theJson.isNull())
					break;
				string url = theJson.asString();
				faceboookAdapter.getNextJson(url, theJson);
			}
			return ret;
		}*/
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
				for(unsigned  i =0; i < theJson["data"].size(); ++i){
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

		User getUserInfo(string userID){
			Json::Value theJson;
			faceboookAdapter.getHisJson("", userID, theJson);
			User user;
			user.userName = theJson["name"].asString();
			user.ID = theJson["id"].asString();
			
		}

		vector<Post> getHisPostList(string id){
			Json::Value theJson;
			faceboookAdapter.getHisJson("feed", id, theJson);

			vector<Post> ret;
			while(1){
				for(unsigned  i =0; i < theJson["data"].size(); ++i){
					Post p;
					Json::Value tmp = theJson["data"][i];
					p.postID = tmp["id"].asString();
					p.fromID = tmp["from"]["id"].asString();
					p.content = tmp["message"].asString();
					p.createdTime = tmp["created_time"].asString();
					p.nLike = tmp["likes"]["count"].asInt();
					p.place = tmp["place"]["location"]["city"].asString() + ", " + tmp["place"]["location"]["state"].asString() + ", " + tmp["place"]["location"]["country"].asString();
					ret.push_back(p);
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

class TwitterData{
	private:
		string accessToken;
		string accessTokenSecret;
		TwitterAdapter twitterAdapter;
	public:
		TwitterData(string in_accessToken, string in_accessTokenSecret):accessToken(in_accessToken), accessTokenSecret(in_accessTokenSecret),twitterAdapter(in_accessToken,in_accessTokenSecret){}
		vector<User> getFriendList(){
			Json::Value theJson;
			twitterAdapter.getMyJson("friends/ids", theJson);
			vector<User> ret;
			int i;
			for(i=0;i<theJson["ids"].size();i++){
				int ID = theJson["ids"][i].asInt();
				string s;
				stringstream ss(s);
				ss <<ID;
				User u("",s,"","","","","");
				ret.push_back(u);	
			}
			return 	ret;
		}
		vector<string> getHisPostList(string id){
			/*Json::Value theJson;
			twitterAdapter.getHisJson("statuses/user_timeline",id, theJson);
			vector<string> ret;
			int i;
			for(i=0;i<theJson.size();i++){
				//cout<<theJson[i]["text"]<<endl;
				ret.push_back(theJson[i]["text"].asString());
			}
			return 	ret;*/
		}

};


#endif //DATA_HPP
