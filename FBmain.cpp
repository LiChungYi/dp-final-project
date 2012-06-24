#include<iostream>
#include<fstream>

#include"Adapter.hpp"
#include"Database.hpp"
#include"SearchEngine.hpp"

int main(int argc, char* argv[]){

	FacebookDatabase facebookDatabase(argv[1]);
/*
	cerr <<	"myID is: " << facebookDatabase.getMyID() << endl; 
	vector<string> idList = facebookDatabase.getMyFriendIDList();
	cerr << "number of friends = " << idList.size() << endl;
	vector<string> nameList = facebookDatabase.getMyFriendNameList();
	for(unsigned i =0 ; i < nameList.size(); ++i)
		cerr << nameList.at(i)<<endl;
	cerr << "number of friends = " << nameList.size() << endl;
*/

	facebookDatabase.getUserInfo("1422131686");
	facebookDatabase.getUserInfo("1744451859");
	facebookDatabase.getUserInfo("224171");

	//vector<Post> post = facebookDatabase.getHisPostList("1422131686");
	//vector<Post> post = facebookDatabase.getHisPostList("1744451859");
	//vector<Post> post = facebookDatabase.getHisPostList("224171");
	//cerr << "number of posts = " <<  post.size() << endl;
	//cerr << post.at(0);


//	ofstream file("posts.txt");
//	for(unsigned i =0 ; i < post.size(); ++i)
//		file<<post.at(i)<<endl;

	SearchEngine se(&facebookDatabase);
/*	vector<Post> result = se.searchAllPostsOfUser("1422131686", "STORY");
	for(unsigned i = 0; i < result.size(); ++i)
		cout << result.at(i);

	*/

	vector<User> result2 = se.searchAllMyFriendsByRelationshipStatus("Single");
//	for(unsigned i = 0; i < result2.size(); ++i)
//		cout << result2.at(i).relationshipStatus;
	

	//TODO:
	//speedup
	//map function?? <= pattern?
	//search ? <= bridge??

/*	for(unsigned i = 0; i < idList.size(); ++i){
		cout << idList.at(i) << endl;
	}
*/

	return 0;
}
