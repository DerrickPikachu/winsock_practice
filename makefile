all:
	g++ winsock.cpp -o winsock -lws2_32
	g++ winclient.cpp -o winclient -lws2_32
clean:
	all