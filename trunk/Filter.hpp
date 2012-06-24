#ifndef FILTER_HPP
#define FILTER_HPP


#include <map>
#include<assert.h>
#include "Data.hpp"
#include <sstream>

using namespace std;

// functional object (Command Pattern)

template <class T>	//T can be Post or User
class Filter{
	private:
		static map<string, Filter<T>*> filterManager;
	public:
		Filter(string className){
			cerr<<className<<endl;
			filterManager.insert(make_pair(className,this));
			cerr<<filterManager.size()<<endl;
		}
		Filter(){}
		static Filter* newFilter(string className, string condition){
			Filter* f = (*filterManager.find(className)).second;
			return f->Clone(condition);	
		}
		virtual Filter* Clone(string s) =0;
		virtual bool shouldKeep(T) = 0;		
};


class PostContentFilter:public Filter<Post>{
	private:
		string shouldBeContained;
	public:
//		static PostContentFilter dummy;
		PostContentFilter(string in_shouldBeContained):shouldBeContained(in_shouldBeContained){}

		virtual bool shouldKeep(Post p){
			if(p.content.find(shouldBeContained) != string::npos)//found
				return true;
			return false;
		}
		PostContentFilter():Filter<Post>("PostContentFilter"){
		}
		Filter<Post>* Clone(string s){
			return new PostContentFilter(s);

		}
};

class PostFromIDFilter:public Filter<Post>{
	private:
		string theFromID;
	public: 
//		static PostFromIDFilter dummy;
		PostFromIDFilter(string in_theFromID):theFromID(in_theFromID){}
		virtual bool shouldKeep(Post p){
			if(p.fromID.compare(theFromID) == 0)
				return true;
			return false;
		}
		PostFromIDFilter():Filter<Post>("PostFromIDFilter"){
		}
		Filter<Post>* Clone(string s){
			return new PostFromIDFilter(s);
		}
};

class PostTimeFilter:public Filter<Post>{
	private:
		string fromTime, toTime;
	public:
//		static PostTimeFilter dummy;
		PostTimeFilter(string in_fromTime, string in_toTime):fromTime(in_fromTime), toTime(in_toTime){}
		virtual bool shouldKeep(Post p){
			if(fromTime.compare(p.createdTime) <= 0 && p.createdTime.compare(toTime) <= 0 )
				return true;
			return false;
		}
		
		PostTimeFilter():Filter<Post>("PostTimeFilter"){
		}
		Filter<Post>* Clone(string s){
			stringstream ss(s);
			string tmp1, tmp2;
			getline(ss,tmp1,'\t');
			getline(ss,tmp2,'\t');
			return new PostTimeFilter(tmp1, tmp2);
		}
};


class UserRelationshipStatusFilter:public Filter<User>{
	private:
		string relationshipStatus;
	public:
//		static UserRelationshipStatusFilter dummy;
		UserRelationshipStatusFilter(string in_relationshipStatus):relationshipStatus(in_relationshipStatus){}
		virtual bool shouldKeep(User u){
			if(u.relationshipStatus.compare(relationshipStatus) == 0)
				return true;
			return false;
		}
		UserRelationshipStatusFilter():Filter<User>("UserRelationshipStatusFilter"){
		}
		Filter<User>* Clone(string s){
			return new UserRelationshipStatusFilter(s);	
		}
};

class UserGenderFilter:public Filter<User>{
	private:
		string gender;
	public:
//		static UserGenderFilter dummy;
		UserGenderFilter(string in_gender):gender(in_gender){}
		virtual bool shouldKeep(User u){
			if(u.gender.compare(gender) == 0)
				return true;
			return false;
		}
		UserGenderFilter():Filter<User>("UserGenderFilter"){
		}
		Filter<User>* Clone(string s){
			return new UserGenderFilter(s);
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
		AndFilter():Filter<T>("AndFilter"){
		}
		Filter<T>* Clone(string s){
			assert(0);
			return NULL;
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
		OrFilter():Filter<T>("OrFilter"){
		}
		Filter<T>* Clone(string s){
			assert(0);
			return NULL;
		}
		~OrFilter(){
			delete a;
			delete b;
		}
};
/*
template<class T> 
map<string,Filter<T>*> Filter<T>::filterManager;

PostContentFilter PostContentFilter::dummy;
PostFromIDFilter PostFromIDFilter::dummy;
PostTimeFilter PostTimeFilter::dummy;
UserGenderFilter UserGenderFilter::dummy;
UserRelationshipStatusFilter UserRelationshipStatusFilter::dummy;
*/
#endif //FILTER_HPP
