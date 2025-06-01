CC = gcc
CFLAGS = -Wall

TARGET = daemon_monitor
OBJS = main.o sl_daemon.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c sl_daemon.h
	$(CC) $(CFLAGS) -c main.c

sl_daemon.o: sl_daemon.c sl_daemon.h
	$(CC) $(CFLAGS) -c sl_daemon.c

clean:
	rm -f *.o $(TARGET)

.PHONY: all clean

