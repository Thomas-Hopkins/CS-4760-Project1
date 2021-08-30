CC = gcc
CFLAGS = -Wall
DEPS = driver.c log.c log.h
OBJ = driver.o log.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

driver: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^


