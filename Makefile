default:
	echo ===============
	g++ -std=c++2a Forward_list.cpp
	./a.out
a:
	clear
	./a.out
g: 
	git add .
	git commit -m "fast pushed for makefile =)"
	git push