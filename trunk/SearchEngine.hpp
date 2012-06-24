#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP
#include "Database.hpp"
#include "Filter.hpp"
class SearchEngine{
	private:
		Database *data;	//BRIDGE PATTERN!
	public:
		SearchEngine(Database *in_data): data(in_data){}

		vector<Post> searchAllPostsOfUser(string userID, Filter<Post> *filter){
			vector<Post> postList = data->getHisPostList(userID);
			vector<Post> result;
			for(vector<Post>::iterator it = postList.begin(); it != postList.end(); it++){
				if(filter->shouldKeep(*it))
					result.push_back(*it);
			}
			return result;
			
		}

		//should be modify, here just a simple default method
		vector<Post> searchAllPostsOfUser(string userID, string userInput){
			Filter<Post> *f = new PostContentFilter(userInput);
			return searchAllPostsOfUser(userID, f);
		}



		vector<User> searchAllMyFriends(Filter<User> *filter){
			vector<string> userIDList = data->getMyFriendIDList();
			vector<User> result;
			for(vector<string>::iterator it = userIDList.begin(); it != userIDList.end(); it++){
				User u = data->getUserInfo(*it);
				if(filter->shouldKeep(u)){
					result.push_back(u);
					cout << u;
				}
			}
			return result;
		}


		//may be deleted, here just a simple testing method
		vector<User> searchAllMyFriendsByRelationshipStatus(string status){
			Filter<User> *f = new UserRelationshipStatusFilter(status);
			return searchAllMyFriends(f);
		}
};
#endif //SEARCH_ENGINE_HPP
