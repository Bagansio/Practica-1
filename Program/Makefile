OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG  -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o cjt_especies.o especie.o cjt_clusters.o
	g++ -o program.exe program.o cjt_especies.o especie.o cjt_clusters.o
	rm *.o

especie.o:  especie.cc especie.hh 
	g++ -c especie.cc $(OPCIONS)

cjt_especies.o:  cjt_especies.cc cjt_especies.hh especie.hh 
	g++ -c cjt_especies.cc $(OPCIONS)

cjt_clusters.o: cjt_clusters.cc cjt_clusters.hh cjt_especies.hh especie.hh
	g++ -c cjt_clusters.cc $(OPCIONS)
	
program.o: program.cc cjt_especies.hh especie.hh 
	g++ -c program.cc $(OPCIONS)


test: 
	time ./program.exe < /mnt/f/alexm/Repositorios/Practica-1/Program/Sample/sample.inp > a.txt  
	diff a.txt /mnt/f/alexm/Repositorios/Practica-1/Program/Sample/sample.cor

tar: 
	tar -cvf practica.tar Makefile especie.hh especie.cc cjt_clusters.hh cjt_clusters.cc cjt_especies.hh cjt_especies.cc program.cc

borrar:
	rm a.txt
	rm *.o 
	rm *.exe


clean:
	rm *.o
	rm *.exe