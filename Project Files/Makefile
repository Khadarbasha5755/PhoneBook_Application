CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = phonebook

OBJ = main.o create.o print.o delete.o find.o edit.o file.o helper.o

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c phonebook.h
	$(CC) $(CFLAGS) -c main.c

create.o: create.c phonebook.h
	$(CC) $(CFLAGS) -c create.c

print.o: print.c phonebook.h
	$(CC) $(CFLAGS) -c print.c

delete.o: delete.c phonebook.h
	$(CC) $(CFLAGS) -c delete.c

find.o: find.c phonebook.h
	$(CC) $(CFLAGS) -c find.c

edit.o: edit.c phonebook.h
	$(CC) $(CFLAGS) -c edit.c

file.o: file.c phonebook.h
	$(CC) $(CFLAGS) -c file.c

helper.o: helper.c phonebook.h
	$(CC) $(CFLAGS) -c helper.c

clean:
	rm -f $(OBJ) $(TARGET) phonebook.dat
