#include<iostream>
#include<fstream>

#include"Adapter.hpp"
#include"Data.hpp"
#include"SearchEngine.hpp"

int main(int argc, char* argv[]){

	FacebookData facebookData(argv[1]);
/*
	cerr <<	"myID is: " << facebookData.getMyID() << endl; 
	vector<string> idList = facebookData.getMyFriendIDList();
	cerr << "number of friends = " << idList.size() << endl;
	vector<string> nameList = facebookData.getMyFriendNameList();
	for(unsigned i =0 ; i < nameList.size(); ++i)
		cerr << nameList.at(i)<<endl;
	cerr << "number of friends = " << nameList.size() << endl;
*/

	facebookData.getUserInfo("1422131686");
	facebookData.getUserInfo("1744451859");
	facebookData.getUserInfo("224171");

	//vector<Post> post = facebookData.getHisPostList("1422131686");
	//vector<Post> post = facebookData.getHisPostList("1744451859");
	//vector<Post> post = facebookData.getHisPostList("224171");
	//cerr << "number of posts = " <<  post.size() << endl;
	//cerr << post.at(0);


//	ofstream file("posts.txt");
//	for(unsigned i =0 ; i < post.size(); ++i)
//		file<<post.at(i)<<endl;

	SearchEngine se(&facebookData);
	vector<Post> result = se.searchAllPostsOfUser("1422131686", "STORY");
	for(unsigned i = 0; i < result.size(); ++i)
		cout << result.at(i);


	vector<User> result2 = se.searchAllMyFriendsByRelationshipStatus("Single");
	for(unsigned i = 0; i < result2.size(); ++i)
		cout << result2.at(i);
	

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
