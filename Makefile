CC = gcc
CFLAGS = -W -Wall
TARGET = itaxi
OBJECTS = main.c libtaxi.a
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
libtaxi.a : CRUD.o
	ar rcv $@ $^
	rm *.o
clean :
	rm *.o *.a itaxi
