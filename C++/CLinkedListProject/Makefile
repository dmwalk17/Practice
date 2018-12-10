#Makefile for Lab 2 - Linked List Lab
# CISP1020
# Donna Walker
#Compiler
CC = gcc

#Compiler Flags
CFLAGS=-c -Wextra

all: project

project: main.o stock.o linkedList.o node.o 
	$(CC) main.o stock.o linkedList.o node.o -o stock

main: main.o
	$(CC) $(CFLAGS) main.c 

stock: stock.o
	$(CC) $(CFLAGS) stock.c

linkedList: linkedList.o
	$(CC) $(CFLAGS) linkedList.c

node: node.o
	$(CC) $(CFLAGS) node.c

clean: 
	rm -rf *.o *.gch stock 
