CFLAGS=-g -O3

OBJS= UI.o tokenizer.o

all: tokenmoment

$(OBJS):tokenizer.h


tokenmoment: $(OBJS)
	cc -o tokenmoment $(CFLAGS) $(OBJS)

clean:
	rm -f *.o tokenmoment
run:tokenmoment
	./tokenmoment
