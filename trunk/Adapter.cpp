#include "Adapter.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <iostream>

FacebookAdapter::FacebookAdapter(string in_accessToken){
	accessToken = in_accessToken;
	sprintf(tmpFileName, "FBtmp_%s.json", accessToken.c_str());
}

void FacebookAdapter::getMyJson(string type, Json::Value& theJson){
	getHisJson(type, "me", theJson);
}

void FacebookAdapter::getHisJson(string type, string hisID, Json::Value& theJson){
	char cmd[500];
	sprintf(cmd, "rm -rf %s", tmpFileName);
	system(cmd);
	sprintf(cmd, "php ./fetch_FBdata.php %s %s %s %s", accessToken.c_str(), type.c_str(), hisID.c_str(), tmpFileName);
	system(cmd);

	ifstream tmpFile(tmpFileName);
	tmpFile>> theJson;
}
void FacebookAdapter::getNextJson(string url, Json::Value& theJson){//move up to static and resued by twitter?
	ofstream output(tmpFileName, ios_base::out | ios_base::trunc);
	output << url;
	output.close();

	//php
	char cmd[500];
	sprintf(cmd, "php ./myWget.php %s %s", tmpFileName, tmpFileName);
	system(cmd);

	ifstream tmpFile(tmpFileName);
	tmpFile >> theJson;
}

TwitterAdapter::TwitterAdapter(string in_accessToken, string in_accessTokenSecret){
	accessToken = in_accessToken;
	accessTokenSecret = in_accessTokenSecret;
	sprintf(tmpFileName, "TWtmp_%s.json", accessToken.c_str());
}
void TwitterAdapter::getMyJson(string type, Json::Value& theJson){
	char cmd[500];
	sprintf(cmd, "rm -rf %s", tmpFileName);
	system(cmd);
	sprintf(cmd, "php ./fetch_TWdata.php %s %s %s -1 %s", accessToken.c_str(), accessTokenSecret.c_str(),type.c_str(),  tmpFileName);
	system(cmd);
	ifstream tmpFile(tmpFileName);
	tmpFile>> theJson;
}
void TwitterAdapter::getHisJson(string type, string hisID, Json::Value& theJson){
	char cmd[500];
	sprintf(cmd, "rm -rf %s", tmpFileName);
	system(cmd);
	sprintf(cmd, "php ./fetch_TWdata.php %s %s %s %s %s", accessToken.c_str(), accessTokenSecret.c_str(),type.c_str(), hisID.c_str(), tmpFileName);
	system(cmd);
	ifstream tmpFile(tmpFileName);
	tmpFile>> theJson;
}

