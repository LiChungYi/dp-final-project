#include<assert.h>
#include<iostream>
#include<fstream>
#include<string.h>

#include "Database.hpp"
#include "SearchEngine.hpp"


#define LINE_SIZE 50000
using namespace std;
/*
 * parsing the input format of general search engine
 * */
int main(int argc, char* argv[]){

	PostContentFilter dummy1 ;
	PostFromIDFilter dummy2;
	PostTimeFilter dummy3;
	UserGenderFilter dummy4;
	UserRelationshipStatusFilter dummy5;
	
//	cout<<Filter<T>::filterManager.size()<<endl;

	assert(argc == 2);
	ifstream input(argv[1]);
	
	char outputFileName[LINE_SIZE];
	input.getline(outputFileName, LINE_SIZE);
	ofstream output(outputFileName);


	Database *database;
	string DBtype;
	input >> DBtype;
	if(DBtype.compare("FB") == 0){
		string a;
		input >> a;
		database = new FacebookDatabase(a);
	}
	else if(DBtype.compare("TW") == 0){
		string a, b;
		input >> a;
		input >> b;
	cerr<<"start searchi"<<endl;
		database = new TwitterDatabase(a, b);
	cerr<<"start searchj"<<endl;
	}
	else
		assert(0);
	char c;
	c = input.get();
	assert(c == '\n');

	cerr<<"start search"<<endl;
	SearchEngine searchEngine(database);
	cerr<<"start search1"<<endl;
	string dataType;
	input >> dataType;
	if(dataType.compare("Post")==0){
		string uid;
		input >> uid;

		c = input.get();//so we can do get line later
		assert(c == '\n');

		list<Filter<Post>* > filterList; 
		list<string> combineMethod;
		while(1){
			string line;
			getline(input, line);

			string className, arg;
			stringstream ss(line);
			getline(ss, className, '\t');
			getline(ss, arg, '\t');
		
			filterList.push_back(Filter<Post>::newFilter(className, arg)); 

			string line;
			getline(input, line);
			if(!input.good())
				break;
			combineMethod.push_back(line);
		}

		list<Filter<Post>*> i1t = filter.begin();
		list<string>::iterator i2t = combineMethod.begin();
		while(i2t != combineMethod.end()){
			if(i2t->compare("and") == 0){
				Filter<Post>* tmp = *i1t;
				i1t = filterList.erase(i1t);
				i2t = combineMethod.erase(i2t);
				i1t = new AndFilter(tmp, *i1t); 
			}
			else{
				i1t++;
				i2t++;
			}
		}
		i1t = filter.begin();
		i2t = combineMethod.begin();
		while(i2t != combineMethod.end()){
			if(i2t->compare("or") == 0){
				Filter<Post>* tmp = *i1t;
				i1t = filterList.erase(i1t);
				i2t = combineMethod.erase(i2t);
				i1t = new OrFilter(tmp, *i1t); 
			}
			else{
				i1t++;
				i2t++;
			}
		}
		
		assert(combineMethod.size() == 0);
		assert(filterList.size() == 1);


		Filter<Post> *filter = new AndFilter<Post>(fa, fb);
		cerr<<"start search"<<endl;
		vector<Post> ret = searchEngine.searchAllPostsOfUser(uid, filter);
		cerr<<"end search"<<endl;
		for(unsigned i = 0; i < ret.size(); ++i)
			output << ret.at(i);

	}
	else if(dataType.compare("User")==0){
		c = input.get();//so we can do get line later
		assert(c == '\n');

		list<Filter<User>* > filterList; 
		list<string> combineMethod;
		while(1){
			string line;
			getline(input, line);

			string className, arg;
			stringstream ss(line);
			getline(ss, className, '\t');
			getline(ss, arg, '\t');
		
			filterList.push_back(Filter<User>::newFilter(className, arg)); 

			string line;
			getline(input, line);
			if(!input.good())
				break;
			combineMethod.push_back(line);
		}

		list<Filter<User>*> i1t = filter.begin();
		list<string>::iterator i2t = combineMethod.begin();
		while(i2t != combineMethod.end()){
			if(i2t->compare("and") == 0){
				Filter<User>* tmp = *i1t;
				i1t = filterList.erase(i1t);
				i2t = combineMethod.erase(i2t);
				i1t = new AndFilter(tmp, *i1t); 
			}
			else{
				i1t++;
				i2t++;
			}
		}
		i1t = filter.begin();
		i2t = combineMethod.begin();
		while(i2t != combineMethod.end()){
			if(i2t->compare("or") == 0){
				Filter<User>* tmp = *i1t;
				i1t = filterList.erase(i1t);
				i2t = combineMethod.erase(i2t);
				i1t = new OrFilter(tmp, *i1t); 
			}
			else{
				i1t++;
				i2t++;
			}
		}
		
		assert(combineMethod.size() == 0);
		assert(filterList.size() == 1);


		vector<User> ret = searchEngine.searchAllMyFriends(filterList.at(0));
		for(unsigned i = 0; i < ret.size(); ++i)
			output << ret.at(i);
	}
	else
		assert(0);
	
	input.close();
	output.close();
}
