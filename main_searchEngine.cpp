#include<assert.h>
#include<iostream>
#include<fstream>
#include<string.h>

#include "Database.hpp"
#include "SearchEngine.hpp"

#define LINE_SIZE 50000
using namespace std;
int main(int argc, char* argv[]){
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
		database = new TwitterDatabase(a, b);
	}
	else
		assert(0);
	char c;
	input >> c;
	assert(c == '\n');

	SearchEngine searchEngine(database);
	string dataType;
	input >> dataType;
	if(dataType.compare("Post")){
		string uid;
		input >> uid;
		input >> c;
		assert(c == '\n');

		string line;
		getline(input, line);
		Filter<Post> *fa;
		{
			string tmp;
			stringstream ss(line);
			getline(ss, tmp, '\t');
			assert(tmp.compare("PostContentFilter") == 0);
			getline(ss, tmp, '\t');
			fa = new PostContentFilter(tmp);
		}


		getline(input, line);
		assert(line.compare("and") == 0);


		getline(input, line);
		Filter<Post> *fb;
		{
			string tmp1, tmp2;
			stringstream ss(line);
			getline(ss, tmp1, '\t');
			assert(tmp1.compare("PostTimeFilter") == 0);
			getline(ss, tmp1, '\t');
			getline(ss, tmp2, '\t');
			fb = new PostTimeFilter(tmp1, tmp2);
		}

		Filter<Post> *filter = new AndFilter<Post>(fa, fb);
		vector<Post> ret = searchEngine.searchAllPostsOfUser(uid, filter);
		for(unsigned i = 0; i < ret.size(); ++i)
			output << ret.at(i);

	}
	else if(dataType.compare("User")){
//		Filter<User> *filter;
//		input >> c;
//		assert(c == '\n');

		assert(0);
		
	}
	else
		assert(0);
	

	input.close();
	output.close();
}
