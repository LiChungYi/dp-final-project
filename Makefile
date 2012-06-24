all:	main_FB main_TW main_dumpFriendToFile main_searchEngine

main_FB:	 allLibrary main_FB.cpp
	g++ -Wall -O3 main_FB.cpp json.o Adapter.o -o main_FB
main_TW: 	 allLibrary main_TW.cpp 
	g++ -Wall -O3 main_TW.cpp json.o Adapter.o -o main_TW
main_dumpFriendToFile: allLibrary main_dumpFriendToFile.cpp
	g++ -Wall -O3 main_dumpFriendToFile.cpp json.o Adapter.o -o main_dumpFriendToFile

main_searchEngine: allLibrary main_searchEngine.cpp
	g++ -Wall -O3 main_searchEngine.cpp json.o Adapter.o -o main_searchEngine


allLibrary: json.o Adapter.o json/json.h Adapter.hpp Database.hpp Data.hpp SearchEngine.hpp Filter.hpp 

json.o: json.cpp json/json.h
	g++ -c -Wall -O3 json.cpp
Adapter.o: Adapter.cpp Adapter.hpp 
	g++ -c -Wall -O3 Adapter.cpp

clean:
	rm -rf main_FB main_TW main_dumpFriendToFile *.json *.o 
FBrun:
	./main_FB AAADXdx63mRQBAFnoBCvrideHcNlkZCEYcLpm0I5sFWGRi4VGumjoGIB0kP0xKxYNeKUrbeOz2gOo8dw5PuJiNy321fZARHFh8dFAKQTwZDZD
TWrun:
	./main_TW 608052658-rvLLXpJBVxD9hI6Rq7fPsMj0L5tNd0aGaTiWaO55 i6TXxY9HoVGKZaR4BOf9hkve88RR43Cy3fO8UPScU 
