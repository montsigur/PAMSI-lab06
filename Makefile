pomiar:	main.cpp graf_LK.cpp graf_MS.cpp graf.cpp kopiec.cpp ./timer/src/Timer.cpp
	g++ -std=c++11 -o pomiar main.cpp \
	graf_LK.cpp graf_MS.cpp graf.cpp kopiec.cpp ./timer/src/Timer.cpp

clean:
	rm -f pomiar
