all:
	g++ test.cpp client.cpp -o test -lws2_32
clean:
	all