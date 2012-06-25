#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <fstream>

#include "Adapter.hpp"
#include "Data.hpp"
#include "TimeParser.hpp"

using namespace std;
class Database{
	public:
		virtual string getMyID()=0;
		virtual vector<string> getMyFriendIDList()=0;
		virtual User getUserInfo(string id)=0;
		virtual vector<Post> getHisPostList(string id)=0;
		virtual void dumpMyFriendData(string fileName) = 0;
		virtual string getProfilePicture(string userID) = 0;
	
};

class FacebookDatabase:public Database{
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
		FacebookDatabase(string in_accessToken):accessToken(in_accessToken), faceboookAdapter(in_accessToken){}
		string getMyID(){
			Json::Value theJson;
			faceboookAdapter.getMyJson("profile", theJson);
			return theJson["id"].asString();
		}

		string getProfilePicture(string userID){
			return "https://graph.facebook.com/" + userID + "/picture/";
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
			faceboookAdapter.getHisJson("profile", userID, theJson);
			User user;
			user.userName = theJson["name"].asString();
			user.ID = theJson["id"].asString();
			user.gender = theJson["gender"].asString();
			user.language = theJson["locale"].asString();
			user.relationshipStatus = theJson["relationship_status"].asString();
			user.birthday = theJson["birthday"].asString();
			user.location = theJson["location"]["name"].asString();
			user.pictureUrl = getProfilePicture(userID);
			return user;
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
					if(tmp["message"].isNull() && !tmp["story"].isNull()){
						p.content = "STORY: " + tmp["story"].asString();
					}
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

		void dumpMyFriendData(string fileName){
			ofstream outFile(fileName.c_str());

			Json::Value theJson;
			faceboookAdapter.getMyJson("friends", theJson);

			while(1){
				for(unsigned  i =0; i < theJson["data"].size(); ++i){
					outFile << theJson["data"][i]["id"].asString() << "\t" << theJson["data"][i]["name"].asString() << endl;
				}
				theJson = theJson["paging"]["next"];
				if(theJson.isNull())
					break;
				string url = theJson.asString();
				faceboookAdapter.getNextJson(url, theJson);
			}

			outFile.close();
		}
};

class TwitterDatabase:public Database{
	private:
		string accessToken;
		string accessTokenSecret;
		TwitterAdapter twitterAdapter;
	public:
		string getMyID(){
			Json::Value theJson;
			twitterAdapter.getMyJson("account/verify_credentials", theJson);
			
			char cs[50];
			sprintf(cs,"%d",theJson["id"].asInt());
			string s(cs);
			return s;
		}
		TwitterDatabase(string in_accessToken, string in_accessTokenSecret):accessToken(in_accessToken), accessTokenSecret(in_accessTokenSecret),twitterAdapter(in_accessToken,in_accessTokenSecret){}

		
		vector<string> getMyFriendIDList(){
			Json::Value theJson;
			twitterAdapter.getMyJson("friends/ids", theJson);
			vector<string> ret;
			unsigned i;
			for(i=0;i<theJson["ids"].size();i++){
				int ID = theJson["ids"][i].asInt();
				char cs[50];
				sprintf(cs,"%d",ID);
				string s(cs);
		//		getUserInfo(s);
				ret.push_back(s);	
			}
			return 	ret;
		}
		User getUserInfo(string id){
			Json::Value theJson;
			twitterAdapter.getHisJson("users/show", id, theJson);
			User u(theJson["name"].asString(),id,"",theJson["lang"].asString(),"","",theJson["location"].asString());
			u.pictureUrl = getProfilePicture(id);

		//	cout<<u<<endl;
			return u;
		}
		vector<Post> getHisPostList(string id){
			Json::Value theJson;
			twitterAdapter.getHisJson("statuses/user_timeline",id, theJson);
			vector<Post> ret;
			unsigned i;
			for(i=0;i<theJson.size();i++){
				string s = theJson[i]["created_at"].asString();
				TwitterTimeParser ttp;
				Post p(theJson[i]["id_str"].asString(),theJson[i]["user"]["id_str"].asString(),theJson[i]["text"].asString(),ttp.Parser(theJson[i]["created_at"].asString()),-1,theJson[i]["place"].asString());
				
				//cout<<p<<endl;
				ret.push_back(p);	
			}
			return 	ret;
		}

		void dumpMyFriendData(string fileName){
			ofstream outFile(fileName.c_str());

			Json::Value theJson;
			twitterAdapter.getMyJson("friends/ids", theJson);

			unsigned i;
			for(i=0;i<theJson["ids"].size();i++){
				int ID = theJson["ids"][i].asInt();
				char cs[50];
				sprintf(cs,"%d",ID);
				string s(cs);
		//		getUserInfo(s);
				outFile << s << "\t" << s <<endl;	//twitter can't get name easily so here we put id as name
			}

			outFile.close();
		}
		
		
		string getProfilePicture(string userID){
			return "";
		}
};


#endif //DATABASE_HPP
