CC = clang
CCFLAGS= -g -O3 -Wall -I include
OBJDIR = out

all: objects 
	$(CC) $(CCFLAGS) main.c $(OBJDIR)/sort_utils.o $(OBJDIR)/selection_sort.o $(OBJDIR)/merge_sort.o \
		$(OBJDIR)/insertion_sort.o $(OBJDIR)/bubble_sort.o $(OBJDIR)/quick_sort.o -o main

objects:
	$(CC) $(CCFLAGS) -c sort_utils.c -o $(OBJDIR)/sort_utils.o
	$(CC) $(CCFLAGS) -c selection_sort.c -o $(OBJDIR)/selection_sort.o
	$(CC) $(CCFLAGS) -c merge_sort.c -o $(OBJDIR)/merge_sort.o
	$(CC) $(CCFLAGS) -c insertion_sort.c -o $(OBJDIR)/insertion_sort.o
	$(CC) $(CCFLAGS) -c bubble_sort.c -o $(OBJDIR)/bubble_sort.o
	$(CC) $(CCFLAGS) -c quick_sort.c -o $(OBJDIR)/quick_sort.o

clean:
	rm main $(OBJDIR)/merge_sort.o $(OBJDIR)/sort_utils.o $(OBJDIR)/selection_sort.o \
	$(OBJDIR)/insertion_sort.o $(OBJDIR)/bubble_sort.o $(OBJDIR)/quick_sort.o