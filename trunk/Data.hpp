#ifndef DATA_HPP
#define DATA_HPP

#include<string>
#include<iostream>
using namespace std;

class Data{
	protected:
		Data(){}
};

class User:public Data{
	public:
		string userName;
		string ID;
		string gender;
		string language;
		string relationshipStatus;
		string birthday;
		string location;
		string pictureUrl;
		User(string name = "", string id = "", string gen = "", string lan = "", string rela = "", string birth = "", string loc = "", string picU = ""):
		userName(name),ID(id),gender(gen),language(lan),relationshipStatus(rela),birthday(birth),location(loc), pictureUrl(picU){}
		friend ostream& operator<<(ostream&, const User&);

};



class Post:public Data{
	public:
		string postID;
		string fromID;
		string content;
		string createdTime;
		int nLike;
		string place;
		Post(string in_postID = "", string in_fromID = "", string in_content = "", string in_createdTime = "", int in_nLike= -1, string in_place = ""):
			postID(in_postID), fromID(in_fromID), content(in_content), createdTime(in_createdTime), nLike(in_nLike), place(in_place){}
		friend ostream& operator<<(ostream&, const Post&);

};

#endif //DATA_HPP
