#ifndef ADAPTER_HPP
#define ADAPTER_HPP

#include<string>


#include "json/json.h"

using namespace std;

/*
 *profile ("")
 friends
 feed
 * */


class Adapter{
	public:
		virtual void getMyJson(string type, Json::Value& theJson) = 0;
		virtual void getHisJson(string type, string hisID, Json::Value& theJson) = 0;
};

class FacebookAdapter :public Adapter{
	//type...
	private:
		string accessToken;
		char tmpFileName[500];
	public:
		FacebookAdapter(string in_accessToken);
		void getMyJson(string type, Json::Value& theJson);
		void getHisJson(string type, string hisID, Json::Value& theJson);
		void getNextJson(string url, Json::Value& theJson);
};
/*
class TwitterAdapter:public Adapter{
	public:

};

*/
#endif //ADAPTER_HPP
