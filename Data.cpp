#include"Data.hpp"

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
ostream& operator<<(ostream& os, const Post& p){
	os<<"postID : "<<p.postID<<endl;
	os<<"fromID : "<<p.fromID<<endl;
	os<<"content : "<<p.content<<endl;
	os<<"createdTime : "<<p.createdTime<<endl;
	os<<"nLIke : "<<p.nLike<<endl;
	os<<"place : "<<p.place<<endl;
	return os;
}
