#include"Adaptor.hpp"
#include<iostream>
#include<fstream>

int main(){
	FacebookAdaptor* fa = new FacebookAdaptor ;
	fa->getFriendList();
	ofstream outfile ("test.txt");
	outfile.close();
}
