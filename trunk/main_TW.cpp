#include<iostream>
#include<fstream>


#include"Adapter.hpp"
#include"Database.hpp"

int main(int argc, char* argv[]){


	TwitterDatabase twitterDatabase(argv[1],argv[2]);
//	string id = twitterDatabase.getMyID();
//	cout<<id<<endl;


//	vector<string> userList = twitterDatabase.getMyFriendIDList();
//	cerr << "number of friends = " << userList.size() << endl;
	
	
	vector<Post> post = twitterDatabase.getHisPostList("71026122");
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
