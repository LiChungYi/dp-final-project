//ifndef .......

#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include<iostream>
#include<string>

#include "json/json.h"

using namespace std;

class Adaptor{
	public:
		virtual void getFriendList(Json::Value& friendJson) = 0;
		virtual void getJson(string s) = 0;
};

class FacebookAdaptor :public Adaptor{
	public:
		virtual void getFriendList(Json::Value& friendJson){
			system("php ./fetch_data.php friends tmp.json");
			std::ifstream file("tmp.json");
			file >> friendJson;
		}
		virtual void getJson(string s){
			int i = 0;
		}

};
/*
class TwitterAdaptor:public Adaptor{
	public:
		virtual void getFriendList(){}
		virtual void getJson(string s){}

};
*/
