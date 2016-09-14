#-----------------------------------------
CC = gcc
CXX = g++
CFLAGS = -Wall -D_REENTRANT -D_GNU_SOURCE -g -fPIC `mysql_config --cflags`
INCFLAGS = -I/home/w/include 
LDFLAGS = `mysql_config --libs`

CFLAGS += $(INCFLAGS)
LINKER = $(CXX)
RM = /bin/rm -f

#-----------------------------------------
LIBOBJS = group_mysql.o

TARGET = groupinfo

#-----------------------------------------

all: $(TARGET)

groupinfo: $(LIBOBJS)
	$(LINKER) $(LDFLAGS) $^ -o $@

clean:
	$(RM) $(TARGET) $(LIBOBJS)
#-----------------------------------------

#make rule
%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@
	
%.o : %.cpp
	$(CXX) $(CFLAGS) -c $^ -o $@

%.o : %.cc
	$(CXX) $(CFLAGS) -c $^ -o $@