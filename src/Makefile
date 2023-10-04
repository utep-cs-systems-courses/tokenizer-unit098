
CFLAGS=-g -O3

OBJS= UI.o tokenizer.o history.o

all: tokenmoment

$(OBJS):tokenizer.h history.h


tokenmoment: $(OBJS)
	cc -o tokenmoment $(CFLAGS) $(OBJS)

clean:
	rm -f *.o tokenmoment
run:tokenmoment
	./tokenmoment
