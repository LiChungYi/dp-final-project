#include <stdio.h>
#include <stdlib.h>


#include<iostream>
#include<string>

using namespace std;

class Adaptor{
	public:
		virtual void getFriendList() = 0;
		virtual void getJason(string s) = 0;
};

class FacebookAdaptor :public Adaptor{
	public:
		virtual void getFriendList(){
			system("php ./fetch_data.php friends");
		}
		virtual void getJason(string s){}

};
class TwitterAdaptor:public Adaptor{
	public:
		virtual void getFriendList(){}
		virtual void getJason(string s){}

};
