.PHONY: sudoku

sudoku:
	rm ./sudoku.o
	g++ -std=c++11   -c -o sudoku.o sudoku.cpp
	g++ -std=c++11 sudoku.o -o sudoku
	./sudoku
