#include"Data.hpp"

ostream& operator<<(ostream& os, const User& u){
	os<<"<hr/><ul>"<<endl;
	os<<"<li>userName : "<<u.userName<<endl;
	os<<"<li>ID : "<<u.ID<<endl;
	os<<"<li>gender : "<<u.gender<<endl;
	os<<"<li>language : "<<u.language<<endl;
	os<<"<li>relationshipStatus : "<<u.relationshipStatus<<endl;
	os<<"<li>birthday : "<<u.birthday<<endl;
	os<<"<li>location : "<<u.location<<endl;
	os<<"</ul>"<<endl;
	return os;
}
ostream& operator<<(ostream& os, const Post& p){
	os<<"<hr/><ul>"<<endl;
	os<<"<li>content : "<<p.content<<endl;
	os<<"<li>postID : "<<p.postID<<endl;
	os<<"<li>fromID : "<<p.fromID<<endl;
	os<<"<li>createdTime : "<<p.createdTime<<endl;
	os<<"<li>nLIke : "<<p.nLike<<endl;
	os<<"<li>place : "<<p.place<<endl;
	os<<"</ul>"<<endl;
	return os;
}
