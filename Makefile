CC = gcc
CFLAGS = -W -Wall
TARGET = itaxi
OBJECTS = main.o CRUD.o extra.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
clean :
	rm *.o itaxi
