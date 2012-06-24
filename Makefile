all:	main_FB TWFunc1 main_dumpFriendToFile

main_FB:	 allLibrary main_FB.cpp
	g++ -Wall -O3 main_FB.cpp json.o Adapter.o -o main_FB
TWFunc1: allLibrary TwitterFunc1.cpp 
	g++ -Wall -O3 TwitterFunc1.cpp json.o Adapter.o -o TWFunc1
main_dumpFriendToFile: allLibrary main_dumpFriendToFile.cpp
	g++ -Wall -O3 main_dumpFriendToFile.cpp json.o Adapter.o -o main_dumpFriendToFile

allLibrary: json.o Adapter.o json/json.h Adapter.hpp Database.hpp User.hpp Post.hpp SearchEngine.hpp Filter.hpp 

json.o: json.cpp json/json.h
	g++ -c -Wall -O3 json.cpp
Adapter.o: Adapter.cpp Adapter.hpp 
	g++ -c -Wall -O3 Adapter.cpp

clean:
	rm -rf FBmain TWFunc1 *.json *.o 
FBrun:
	./FBmain AAADXdx63mRQBAFnoBCvrideHcNlkZCEYcLpm0I5sFWGRi4VGumjoGIB0kP0xKxYNeKUrbeOz2gOo8dw5PuJiNy321fZARHFh8dFAKQTwZDZD
TWrun1:
	./TWFunc1 608052658-rvLLXpJBVxD9hI6Rq7fPsMj0L5tNd0aGaTiWaO55 i6TXxY9HoVGKZaR4BOf9hkve88RR43Cy3fO8UPScU 
