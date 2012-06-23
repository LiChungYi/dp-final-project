#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP
#include "Data.hpp"
class SearchEngine{
	private:
		Data *data;	//BRIDGE PATTERN!
	public:
		SearchEngine(Data *in_data): data(in_data){}

		vector<Post> searchAllPostsOfUser(string userID){
			vector<Post> postList = data->getHisPostList(userID);
			vector<Post> result;
			for(vector<Post>::iterator it = postList.begin(); it != postList.end(); it++){
				if( (it->content).find("生日快樂") != string::npos )
					result.push_back(*it);
			}
			return result;
		}
};
#endif //SEARCH_ENGINE_HPP
