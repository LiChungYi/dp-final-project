#include <assert.h>
#include <string.h>
#include "Database.hpp"

/*	
 *	a program so that php can quickly get my friend list
 *
 * */

int main(int argc, char* argv[]){
	string outFile(argv[1]);
	Database *d;
	if(strcmp("FB", argv[2]) == 0){
		assert(argc == 4);	
		d = new FacebookDatabase(argv[3]);
	}
	else if(strcmp("TW", argv[2]) == 0){
		assert(argc == 5);
		d = new TwitterDatabase(argv[3], argv[4]);
	}
	else
		assert(0);
	d->dumpMyFriendData(outFile);
	delete d;
	return 0;
}
