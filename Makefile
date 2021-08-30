CC = gcc
CFLAGS = -Wall
DEPS = driver.c log.c log.h
OBJ = driver.o log.o
OUT = driver

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(OUT) $(OBJ)

	
