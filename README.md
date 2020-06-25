My program has two files, Graph.hpp and main.cpp
To compile, you need an input file named input.txt (i will have one in my folder)
in the command line you can write 
	g++ -std=c++11 *.cpp -o buckets
	for linux
	   do ./buckets and it will give you the output file (when you do ./buckets it might say command not found but it will still produce the correct output file)

	for windows 
	   do .\buckets

	or you can just write g++ main.cpp
P.S) the example with 2 buckets of size 999 and 998 takes the longest to run at about 2 mins approximately in my computer but about 10 seconds in C4 lab computers
