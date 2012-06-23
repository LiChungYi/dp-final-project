#ifndef TIMEPARSER_HPP
#define TIMEPARSER_HPP

#include <iostream>
#include <stdlib.h>
#include<stdlib.h>
#include<string>
using namespace std;


class TimeParser{
	protected:
		map<string,int> Month;
	public:
		TimeParser(){
			setMonth();
		}
		virtual string Parser(string time)=0;
		void setMonth(){
			Month["Jan"]=1;
			Month["Feb"]=2;
			Month["Mar"]=3;
			Month["Apr"]=4;
			Month["May"]=5;
			Month["Jun"]=6;
			Month["Jul"]=7;
			Month["Aug"]=8;
			Month["Sep"]=9;
			Month["Oct"]=10;
			Month["Nov"]=11;
			Month["Dec"]=12;
			return;
		}
};

class TwitterTimeParser : public TimeParser{
	public:
		virtual string Parser(string in_time){
			char time[6][30];
			sscanf(in_time.c_str(),"%s %s %s %s %s %s ",time[0],time[1],time[2],time[3],time[4],time[5]);	
			char newTime[100];
			string m(time[1]);
			sprintf(newTime,"%s-%02d-%sT%s%s",time[5],Month[m],time[2],time[3],time[4]);
			string newString(newTime);
			return newString;
		}
};
class FacebookTimeParser : public TimeParser{
	public:
		virtual string Parser(string in_time){
			return in_time;
		}
};

#endif
