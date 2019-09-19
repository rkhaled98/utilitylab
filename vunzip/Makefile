# specify target here (name of executable)
TARG = vunzip

# specify all source files here
SRCS = $(TARG).c 

# specify compiler, compile flags, and needed libs
CC = gcc
CFLAGS = -Wall -Werror -Og

# this translates .c files in src list to .o’s
OBJS = $(SRCS:.c=.o)

all: $(TARG)

# this generates the target executable
$(TARG): $(OBJS)
	$(CC) -o $(TARG) $(OBJS)

clean:
	rm -rf *.o $(TARG) tests-out *~

test: $(TARG)
	./test-$(TARG).sh
