CC = gcc
CFLAGS = -Wall -g

DRIVER = driver
DRIVER_LIB = log
DRIVER_DEP = log.h msggen.h
DRIVER_SRC = driver.c msggen.c
DRIVER_OBJ = driver.o msggen.o

LIBLOG = liblog
LIBLOG_ARC = liblog.a
LIBLOG_SRC = log.c addmsg.c clearlog.c getlog.c savelog.c
LIBLOG_OBJ = log.o addmsg.o clearlog.o getlog.o savelog.o

CLEAN = $(LIBLOG_ARC) $(LIBLOG_OBJ) $(DRIVER) $(DRIVER_OBJ)

# Build liblog static archive and build driver
all: $(LIBLOG_ARC) $(DRIVER)

# Compile driver executable
$(DRIVER): $(DRIVER_OBJ) $(DRIVER_DEP) $(LIBLOG_ARC)
	$(CC) $(CFLAGS) -o $@ $(DRIVER_OBJ) -L. -l$(DRIVER_LIB)

# build liblog static archive 
$(LIBLOG_ARC): $(LIBLOG_OBJ)
	ar -rcs $@ $^

# Compile object files from src
%.o: %.c 
	$(CC) $(CFLAGS) -o $@ -c $<

# Clean target
.PHONY: clean
clean:
	rm -f $(CLEAN)

	
