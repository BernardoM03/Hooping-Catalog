EXE = run_catalog
CC = g++

$(EXE)run_catalog: run_catalog.o catalog.o catalog.h
	$(CC) run_catalog.o catalog.o -o $(EXE)

run_catalog.o: run_catalog.cpp
	$(CC) -c run_catalog.cpp

catalog.o: catalog.cpp
	$(CC) -c  catalog.cpp
