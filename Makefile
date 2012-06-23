all:
	g++ main.cpp json.cpp Adapter.cpp -o main
	g++ TwitterFunc1.cpp json.cpp Adapter.cpp -o TWFunc1
FBrun:
	./main AAAE7gNCgCZAcBAEjMVuECOBYQvQVgfiyibwrxvdZBzLc3718z1hZAyW1cpkKkZB5mSsKYKdnRh8mO3Gz0hTwhZAaAIMPGOdBVitbS2gNOiwZDZD
TWrun1:
	./TWFunc1 608052658-rvLLXpJBVxD9hI6Rq7fPsMj0L5tNd0aGaTiWaO55 i6TXxY9HoVGKZaR4BOf9hkve88RR43Cy3fO8UPScU 
