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
	char cmd[1000];
	sprintf(cmd, "rm -rf %s", tmpFileName);
	system(cmd);
	sprintf(cmd, "php ./fetch_data.php %s %s me %s", accessToken.c_str(), type.c_str(), tmpFileName);
	system(cmd);

	ifstream file(tmpFileName);
	file>> theJson;
}

void FacebookAdapter::getHisJson(string type, string hisID, Json::Value& theJson){
	char cmd[500];
	sprintf(cmd, "rm -rf %s", tmpFileName);
	system(cmd);
	sprintf(cmd, "php ./fetch_data.php %s %s %s %s", accessToken.c_str(), type.c_str(), hisID.c_str(), tmpFileName);
	system(cmd);

	ifstream file(tmpFileName);
	file>> theJson;
}
