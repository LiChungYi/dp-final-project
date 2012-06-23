#ifndef User_HPP
#define User_HPP

#include<string>
using namespace std;

class User{
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
#endif
