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



class UserRelationshipStatusFilter:public Filter<User>{
	private:
		string relationshipStatus;
	public:
		UserRelationshipStatusFilter(string in_relationshipStatus):relationshipStatus(in_relationshipStatus){}
		virtual bool shouldKeep(User u){
			if(u.relationshipStatus.compare(relationshipStatus) == 0)
				return true;
			return false;
		}
};

class UserGenderFilter:public Filter<User>{
	private:
		string gender;
	public:
		UserGenderFilter(string in_gender):gender(in_gender){}
		virtual bool shouldKeep(User u){
			if(u.gender.compare(gender) == 0)
				return true;
			return false;
		}
};
#endif //FILTER_HPP
