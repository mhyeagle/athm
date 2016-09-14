#-----------------------------------------
CC = gcc
CXX = g++
CFLAGS = -Wall -D_REENTRANT -D_GNU_SOURCE -g -fPIC
INCFLAGS = -I/home/w/include
LDFLAGS = -L/home/w/lib64 -lredis3m -lhiredis -lprotobuf

CFLAGS += $(INCFLAGS)
LINKER = $(CXX)
RM = /bin/rm -f

#-----------------------------------------
LIBOBJS = creative.o creativeinfo.pb.o

TARGET = creative

#-----------------------------------------

all: $(TARGET)

creative: $(LIBOBJS)
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