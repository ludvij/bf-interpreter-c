# compiler settings
CC = clang
CFLAGS = -Wall -Wextra -std=c17

# debug stuff
DBGFLAGS = -g -O0

# release stuff
RELFLAGS = -O3

DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS += $(DBGFLAGS)
else
	CFLAGS += $(RELFLAGS)
endif

# projext files
OBJDIR = obj
SRCS   = main.c fileUtils.c
OBJS   = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
EXE    = bfi

# windows stuff
CCWIN		= x86_64-w64-mingw32-gcc
WINOBJS 	= $(addprefix $(WINOBJDIR)/, $(SRCS:.c=.o))
WINOBJDIR	= obj/win
WINEXE		= $(EXE).exe



.PHONY: all prep clean linux win

# default build
all: DEBUG=1 prep linux
	

# linux build
linux: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $^

$(OBJDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

# windows build
win: prep $(WINEXE)

$(WINEXE): $(WINOBJS)
	$(CCWIN) $(CFLAGS) -o $(WINEXE) $^

$(WINOBJDIR)/%.o: %.c
	$(CCWIN) -c $(CFLAGS) -o $@ $<


clean:
	rm -f $(OBJS) $(WINOBJS) $(EXE) $(WINEXE) 

prep:
	@mkdir -p $(OBJDIR) $(WINOBJDIR)