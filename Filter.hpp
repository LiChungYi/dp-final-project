#ifndef FILTER_HPP
#define FILTER_HPP


#include "Post.hpp"

// functional object (Command Pattern)

template <class T>	//T can be Post or User
class Filter{
	public:
		virtual bool shouldKeep(T) = 0;		
};


class PostContentFilter:public Filter<Post>{
	private:
		string shouldBeContained;
	public:
		PostContentFilter(string in_shouldBeContained):shouldBeContained(in_shouldBeContained){}

		virtual bool shouldKeep(Post p){
			if(p.content.find(shouldBeContained) != string::npos)//found
				return true;
			return false;
		}
};

class PostFromIDFilter:public Filter<Post>{
	private:
		string theFromID;
	public: 
		PostFromIDFilter(string in_theFromID):theFromID(in_theFromID){}
		virtual bool shouldKeep(Post p){
			if(p.fromID.compare(theFromID) == 0)
				return true;
			return false;
		}
};
#endif //FILTER_HPP
