#include<iostream>
#include<fstream>

#include"Adapter.hpp"
#include"Data.hpp"

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

	//vector<string> post = facebookData.getHisPostList("1422131686");
	//vector<Post> post = facebookData.getHisPostList("1744451859");
	vector<Post> post = facebookData.getHisPostList("224171");
	cerr << "number of posts = " <<  post.size() << endl;
	cerr << post.at(0);
	cerr << post.at(1);
	cerr << post.at(2);
	cerr << post.at(3);
	cerr << post.at(4);
	cerr << post.at(5);
	cerr << post.at(6);
	cerr << post.at(7);
	cerr << post.at(8);


	ofstream file("posts.txt");
	for(unsigned i =0 ; i < post.size(); ++i)
		file<<post.at(i)<<endl;


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
