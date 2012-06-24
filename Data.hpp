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
		User(string name = "", string id = "", string gen = "", string lan = "", string rela = "", string birth = "", string loc = ""):
		userName(name),ID(id),gender(gen),language(lan),relationshipStatus(rela),birthday(birth),location(loc){}
		friend ostream& operator<<(ostream&, const User&);

};

ostream& operator<<(ostream& os, const User& u){
	os<<"userName : "<<u.userName<<endl;
	os<<"ID : "<<u.ID<<endl;
	os<<"gender : "<<u.gender<<endl;
	os<<"language : "<<u.language<<endl;
	os<<"relationshipStatus : "<<u.relationshipStatus<<endl;
	os<<"birthday : "<<u.birthday<<endl;
	os<<"location : "<<u.location<<endl;
	return os;
}


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
ostream& operator<<(ostream& os, const Post& p){
	os<<"postID : "<<p.postID<<endl;
	os<<"fromID : "<<p.fromID<<endl;
	os<<"content : "<<p.content<<endl;
	os<<"createdTime : "<<p.createdTime<<endl;
	os<<"nLIke : "<<p.nLike<<endl;
	os<<"place : "<<p.place<<endl;
	return os;
}

#endif //DATA_HPP
