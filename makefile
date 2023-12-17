test_list: test_list.o
	g++ -o test_list -std=c++11 test_list.o 
test_list.o: test_list.cpp
	g++ -c -std=c++11 test_list.cpp

clean:
	-rm *.o
	-rm *.h.gch
