#ifndef ADAPTER_HPP
#define ADAPTER_HPP

#include<string>

#include "json/json.h"

using namespace std;


class Adapter{
	protected:
		char tmpFileName[500];
	public:
		virtual void cleanTmpFile();
		virtual void getMyJson(string type, Json::Value& theJson) = 0;
		virtual void getHisJson(string type, string hisID, Json::Value& theJson) = 0;
};

class FacebookAdapter :public Adapter{
	//type = "profile", "friends", "feed";
	private:
		string accessToken;
	public:
		FacebookAdapter(string in_accessToken);
		void getMyJson(string type, Json::Value& theJson);
		void getHisJson(string type, string hisID, Json::Value& theJson);
		void getNextJson(string url, Json::Value& theJson);
};

class TwitterAdapter:public Adapter{
	//type = statuses/user_timeline, statuses/update, users/show
	private:
		string accessToken;
		string accessTokenSecret;
	public:
		TwitterAdapter(string in_accessToken, string in_accessTokenSecret);
		void getMyJson(string type, Json::Value& theJson);
		void getHisJson(string type, string hisID, Json::Value& theJson);
};


#endif //ADAPTER_HPP
