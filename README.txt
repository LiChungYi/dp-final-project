//Document------------------------------------------------------------------------------------------------------------------------------------------
Makefile		  //make cpp code
main_searchEnging.cpp     //our main function
Adapter.hpp, Adapter.cpp  //adaptor to call fetch_FBData.php and fetch_TWData.php to get microblogging data, return a json file
Data.hpp, Data.cpp        //Define our object, including user and post
Database.hpp		  //call json.cpp to parse json and provide function to get data such as friendlist
Filter.hpp		  //each filter provides a function should keep to deterimine wheather the post/user should be filtered out or not
SearchEngine.hpp	  //Search Engine contain a Database Object and get a filter object to get relevant result

index.php		  //main page to select microbloging
interface.php		  //search interface

./facebook/*		  //contain some library to call facebook api
./twitter/*		  //contain some library to call twitter api


//How to exec-----------------------------------------------------------------------------------------------------------------------------------------
Method 1: 
	Under Linux system 
	(Note: the directory contain index.html and ./facebook and ./twitter should open write permission )
	1. Regist api key and api secret, and a website.
	2. Modify these attribute in fetch_FBData.php and fetch_TWData.php
	3. type "make" to create exectable file
	4. use browser to open indext.html
	5. select the microbloging and redirect to interface.php
	6. key in query, since FB API is quite slow, it need some time to create result.
Method 2:
	you can direct exec in this url http://mslab.csie.ntu.edu.tw/~chungyi/DP/dp-final-project/
