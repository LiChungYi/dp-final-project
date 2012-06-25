#include<assert.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<list>

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
	assert(argc == 2);
	ifstream input(argv[1]);
	
	char outputFileName[LINE_SIZE];
	input.getline(outputFileName, LINE_SIZE);
	ofstream output(outputFileName,ios_base::out|ios_base::trunc);

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
		database = new TwitterDatabase(a, b);
	}
	else
		assert(0);
	char c;
	c = input.get();
	assert(c == '\n');

	SearchEngine searchEngine(database);
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
			getline(ss, arg);
		
			filterList.push_back(Filter<Post>::newFilter(className, arg)); 

			getline(input, line);
			if(!input.good())
				break;
			combineMethod.push_back(line);
		}

		list<Filter<Post>*>::iterator i1t = filterList.begin();
		list<string>::iterator i2t = combineMethod.begin();
		while(i2t != combineMethod.end()){
			if(i2t->compare("and") == 0){
				Filter<Post>* tmp = *i1t;
				i1t = filterList.erase(i1t);
				i2t = combineMethod.erase(i2t);
				*i1t = new AndFilter<Post>(tmp, *i1t); 
			}
			else{
				i1t++;
				i2t++;
			}
		}
		i1t = filterList.begin();
		i2t = combineMethod.begin();
		while(i2t != combineMethod.end()){
			if(i2t->compare("or") == 0){
				Filter<Post>* tmp = *i1t;
				i1t = filterList.erase(i1t);
				i2t = combineMethod.erase(i2t);
				*i1t = new OrFilter<Post>(tmp, *i1t); 
			}
			else{
				i1t++;
				i2t++;
			}
		}
		
		assert(combineMethod.size() == 0);
		assert(filterList.size() == 1);


		vector<Post> ret = searchEngine.searchAllPostsOfUser(uid, filterList.front());
		output<< "<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" /></head>";
		for(unsigned i = 0; i < ret.size(); ++i){
			output << ret.at(i);
		}
		output<<"</html>\n";

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
			getline(ss, arg);
		
			filterList.push_back(Filter<User>::newFilter(className, arg)); 

			getline(input, line);
			if(!input.good())
				break;
			combineMethod.push_back(line);
		}

		list<Filter<User>*>::iterator i1t = filterList.begin();
		list<string>::iterator i2t = combineMethod.begin();
		while(i2t != combineMethod.end()){
			if(i2t->compare("and") == 0){
				Filter<User>* tmp = *i1t;
				i1t = filterList.erase(i1t);
				i2t = combineMethod.erase(i2t);
				*i1t = new AndFilter<User>(tmp, *i1t); 
			}
			else{
				i1t++;
				i2t++;
			}
		}
		i1t = filterList.begin();
		i2t = combineMethod.begin();
		while(i2t != combineMethod.end()){
			if(i2t->compare("or") == 0){
				Filter<User>* tmp = *i1t;
				i1t = filterList.erase(i1t);
				i2t = combineMethod.erase(i2t);
				*i1t = new OrFilter<User>(tmp, *i1t); 
			}
			else{
				i1t++;
				i2t++;
			}
		}
		
		assert(combineMethod.size() == 0);
		assert(filterList.size() == 1);


		output<< "<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" /></head>";
		vector<User> ret = searchEngine.searchAllMyFriends(filterList.front());
		for(unsigned i = 0; i < ret.size(); ++i)
			output << ret.at(i);
		output<<"</html>";
	}
	else
		assert(0);
	
	input.close();
	output.close();
}
