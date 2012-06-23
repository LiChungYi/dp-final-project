all:	FBmain TWFunc1

FBmain:	 json.o Adapter.o json/json.h Data.hpp User.hpp Post.hpp SearchEngine.hpp Filter.hpp FBmain.cpp
	g++ -Wall -O3 FBmain.cpp json.o Adapter.o -o FBmain 
TWFunc1: json.o Adapter.o json/json.h Data.hpp User.hpp Post.hpp SearchEngine.hpp Filter.hpp TwitterFunc1.cpp 
	g++ -Wall -O3 TwitterFunc1.cpp json.o Adapter.o -o TWFunc1
json.o:
	g++ -c json.cpp
Adapter.o:
	g++ -c Adapter.cpp

clean:
	rm -rf FBmain TWFunc1 *.json *.o 
FBrun:
	./FBmain AAADXdx63mRQBAFnoBCvrideHcNlkZCEYcLpm0I5sFWGRi4VGumjoGIB0kP0xKxYNeKUrbeOz2gOo8dw5PuJiNy321fZARHFh8dFAKQTwZDZD
TWrun1:
	./TWFunc1 608052658-rvLLXpJBVxD9hI6Rq7fPsMj0L5tNd0aGaTiWaO55 i6TXxY9HoVGKZaR4BOf9hkve88RR43Cy3fO8UPScU 
