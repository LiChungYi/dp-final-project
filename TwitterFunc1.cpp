#include<iostream>
#include<fstream>


#include"Adapter.hpp"
#include"Data.hpp"
#include"User.hpp"

int main(int argc, char* argv[]){


	TwitterData twitterData(argv[1],argv[2]);
	vector<string> idList = twitterData.getMyFriendIDList();
	cerr << "number of friends = " << idList.size() << endl;
	
//	cerr << "number of friends = " << idList.size() << endl;
	
	vector<string> post = twitterData.getHisPostList("71026122");
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
