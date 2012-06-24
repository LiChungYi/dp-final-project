#ifndef FILTER_HPP
#define FILTER_HPP


#include "Data.hpp"

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

class PostTimeFilter:public Filter<Post>{
	private:
		string fromTime, toTime;
	public:
		PostTimeFilter(string in_fromTime, string in_toTime):fromTime(in_fromTime), toTime(in_toTime){}
		virtual bool shouldKeep(Post p){
			if(fromTime.compare(p.createdTime) <= 0 && p.createdTime.compare(toTime) <= 0 )
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

template <class T>
class AndFilter: public Filter<T>{//Composite Pattern!
	private:
		Filter<T> *a, *b;
	public:
		AndFilter(Filter<T> *in_a, Filter<T> *in_b):a(in_a), b(in_b){}
		virtual bool shouldKeep(T t){
			if(a->shouldKeep(t) && b->shouldKeep(t))
				return true;
			return false;
		}
		~AndFilter(){
			delete a;
			delete b;
		}
};

template <class T>
class OrFilter: public Filter<T>{//Composite Pattern!
	private:
		Filter<T> *a, *b;
	public:
		OrFilter(Filter<T> *in_a, Filter<T> *in_b):a(in_a), b(in_b){}
		virtual bool shouldKeep(T t){
			if(a->shouldKeep(t) || b->shouldKeep(t))
				return true;
			return false;
		}
		~OrFilter(){
			delete a;
			delete b;
		}
};


#endif //FILTER_HPP
