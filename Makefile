default:
	clear
	g++ -std=c++2a Forward_list.cpp
	./a.out
a:
	clear
	./a.out
g: 
	git add .
	git commit -m "is pushed for makefile because mne bilo len =)"
	git push
all:
	make cmp_rn
	make git
