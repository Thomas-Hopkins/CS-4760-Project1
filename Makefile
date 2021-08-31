CC = gcc
CFLAGS = -Wall

DRIVER = driver
DRIVER_LIB = liblog.a
DRIVER_DEP = log.h
DRIVER_SRC = driver.c
DRIVER_OBJ = driver.o

LIBLOG = liblog
LIBLOG_ARC = liblog.a
LIBLOG_SRC = addmsg.c clearlog.c getlog.c savelog.c
LIBLOG_OBJ = addmsg.o clearlog.o getlog.o savelog.o

CLEAN = $(LIBLOG_ARC) $(LIBLOG_OBJ) $(DRIVER) $(DRIVER_OBJ)

# Build liblog static archive from implicit rules and build driver
all: $(LIBLOG_ARC) $(DRIVER)

# Compile driver executable
$(DRIVER): $(DRIVER_OBJ) $(DRIVER_LIB) $(DRIVER_DEP)
	$(CC) $(CFLAGS) -o $@ $^

# Compile driver.o
$(DRIVER_OBJ): $(DRIVER_SRC)
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBLOG_ARC): $(LIBLOG_OBJ)
	ar -rcs $@ $^

$(LIBLOG_OBJ): $(LIBLOG_SRC)
	$(CC) $(CFLAGS) -o $@ -c $(subst .o,.c, $@)

# Clean target
.PHONY: clean
clean:
	rm -f $(CLEAN)

	
