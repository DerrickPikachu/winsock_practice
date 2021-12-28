all:
	g++ winclient.cpp -o winclient -lws2_32
	g++ client.cpp -o client -lws2_32
clean:
	all