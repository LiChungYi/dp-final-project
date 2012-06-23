#include<iostream>
#include<fstream>


#include"Adapter.hpp"
#include"Data.hpp"
#include"User.hpp"
#include"Post.hpp"

int main(int argc, char* argv[]){


	TwitterData twitterData(argv[1],argv[2]);
//	string id = twitterData.getMyID();
//	cout<<id<<endl;


//	vector<string> userList = twitterData.getMyFriendIDList();
//	cerr << "number of friends = " << userList.size() << endl;
	
	
	vector<Post> post = twitterData.getHisPostList("71026122");
	cerr << "number of posts = " <<  post.size() << endl;



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
