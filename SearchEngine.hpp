#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP
#include "Database.hpp"
#include "Filter.hpp"
class SearchEngine{
	private:
		Database* database;	//BRIDGE PATTERN!
	public:
		SearchEngine(Database *in_database): database(in_database){} //Users are responsible for freeing the database!

		vector<Post> searchAllPostsOfUser(string userID, Filter<Post> *filter){
			vector<Post> postList = database->getHisPostList(userID);
			vector<Post> result;
			for(vector<Post>::iterator it = postList.begin(); it != postList.end(); it++){
				if(filter->shouldKeep(*it)){
					result.push_back(*it);
				}
			}
			return result;
			
		}

		//should be modify, here just a simple default method
		vector<Post> searchAllPostsOfUser(string userID, string userInput){
			Filter<Post> *f = new PostContentFilter(userInput);
			return searchAllPostsOfUser(userID, f);
		}



		vector<User> searchAllMyFriends(Filter<User> *filter){
			vector<string> userIDList = database->getMyFriendIDList();
			vector<User> result;
			for(vector<string>::iterator it = userIDList.begin(); it != userIDList.end(); it++){
				User u = database->getUserInfo(*it);
				if(filter->shouldKeep(u)){
					result.push_back(u);
				}
			}
			return result;
		}


		//may be deleted, here just a simple testing method
		vector<User> searchAllMyFriendsByRelationshipStatus(string status, string gender){
			Filter<User> *f1 = new UserRelationshipStatusFilter(status);
			Filter<User> *f2 = new UserGenderFilter(gender);
			Filter<User> *f = new AndFilter<User>(f1, f2);
			return searchAllMyFriends(f);
		}
};
#endif //SEARCH_ENGINE_HPP
