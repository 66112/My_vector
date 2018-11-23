my:main.cc 
	g++ -o $@ $^ -g -std=c++11 -fpermissive 
.PHONY:clean
clean:
	rm -f my 

