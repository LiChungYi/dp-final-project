#ifndef POST_HPP
#define POST_HPP
#include<iostream>
using namespace std;

class Post{
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

#endif //POST_HPP
