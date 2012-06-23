#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP
#include "Data.hpp"
#include "Filter.hpp"
class SearchEngine{
	private:
		Data *data;	//BRIDGE PATTERN!
	public:
		SearchEngine(Data *in_data): data(in_data){}

		vector<Post> searchAllPostsOfUser(string userID, Filter<Post> *filter){
			vector<Post> postList = data->getHisPostList(userID);
			vector<Post> result;
			for(vector<Post>::iterator it = postList.begin(); it != postList.end(); it++){
				if(filter->shouldKeep(*it))
					result.push_back(*it);
			}
			return result;
			
		}

		vector<Post> searchAllPostsOfUser(string userID, string userInput){
			Filter<Post> *f = new PostContentFilter(userInput);
			return searchAllPostsOfUser(userID, f);
		}
};
#endif //SEARCH_ENGINE_HPP
