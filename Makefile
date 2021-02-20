# compiler settings
CC = gcc
CFLAGS = -Wall -std=c17

# projext files
OBJDIR = obj
SRCS   = main.c stack.c fileUtils.c
OBJS   = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
EXE    = bfi

# debug stuff
DBGFLAGS = -g -O0

# release stuff
RELFLAGS = -O3

# wondows stuff
CCWIN   = x86_64-w64-mingw32-gcc
WINEXE  = $(EXE).exe
WINOBJDIR  = obj/win
WINOBJS = $(addprefix $(WINOBJDIR)/, $(SRCS:.c=.o))


.PHONY: all prep clean linux win

# default build
all: prep linux

linux: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(DBGFLAGS) -o $(EXE) $^

$(OBJDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(DBGFLAGS) -o $@ $<

win: prep $(WINEXE)

$(WINEXE): $(WINOBJS)
	$(CCWIN) $(CFLAGS) $(DBGFLAGS) -o $(WINEXE) $(CFLAGS) $^

$(WINOBJDIR)/%.o: %.c
	$(CCWIN) -c $(CFLAGS) $(DBGFLAGS) -o $@ $<


clean:
	rm -f $(OBJS) $(WINOBJS) $(EXE) $(WINEXE) 

prep:
	@mkdir -p $(OBJDIR) $(WINOBJDIR)