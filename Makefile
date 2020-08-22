# Files
ENCODER= ceasar
DECODER= unceasar
TARGETS=$(ENCODER) $(DECODER)
SRC= main.c encode.c decode.c
OBJS= $(SRC:.c=.o)

# CFLAGS
CC= gcc
OPT=
WARN= -Wall -Wextra
CFLAGS= $(OPT) $(WARN) -pipe -g

# Operations
all: $(TARGETS)

$(ENCODER): $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

$(DECODER): $(ENCODER)
	ln -f $< $@

clean:
	rm -f *.o $(TARGETS)
