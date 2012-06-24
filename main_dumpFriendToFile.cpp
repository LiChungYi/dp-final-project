#include <assert.h>
#include <string.h>
#include "Database.hpp"
int main(int argc, char* argv[]){
	string outFile("friendList.txt");
	Database *d;
	if(strcmp("FB", argv[1]) == 0){
		assert(argc == 3);	
		d = new FacebookDatabase(argv[2]);
	}
	else if(strcmp("TW", argv[1]) == 0){
		assert(argc == 4);
		d = new TwitterDatabase(argv[2], argv[3]);
	}
	else
		assert(0);
	d->dumpMyFriendData(outFile);
	return 0;
}
