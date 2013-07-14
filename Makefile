CC = clang
CCFLAGS= -g -Wall -I include
OBJDIR = out

all: objects 
	$(CC) $(CCFLAGS) main.c $(OBJDIR)/sort_utils.o $(OBJDIR)/selection_sort.o $(OBJDIR)/merge_sort.o $(OBJDIR)/insertion_sort.o -o main

objects:
	$(CC) $(CCFLAGS) -c sort_utils.c -o $(OBJDIR)/sort_utils.o
	$(CC) $(CCFLAGS) -c selection_sort.c -o $(OBJDIR)/selection_sort.o
	$(CC) $(CCFLAGS) -c merge_sort.c -o $(OBJDIR)/merge_sort.o
	$(CC) $(CCFLAGS) -c insertion_sort.c -o $(OBJDIR)/insertion_sort.o

clean:
	rm $(OBJDIR)/merge_sort.o $(OBJDIR)/sort_utils.o $(OBJDIR)/selection_sort.o $(OBJDIR)/insertion_sort.o