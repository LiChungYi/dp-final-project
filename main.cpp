#include<iostream>
#include<fstream>

#include"Adapter.hpp"
#include"Data.hpp"

int main(int argc, char* argv[]){


	FacebookData facebookData(argv[1]);
	cout <<	"myID is: " << facebookData.getMyID() << endl; 
	vector<string> idList = facebookData.getMyFriendIDList();
	cout << "number of friends = " << idList.size() << endl;

	vector<string> post = facebookData.getHisPostList("1422131686");
	cout << "number of posts = " <<  post.size() << endl;


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
