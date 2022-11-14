BINDIR=bin
SRCDIR=src
INCDIR=include

MAINDIR=. tests

CC=gcc
OPT=-Og

LDFLAGS=-lm
DEPFLAGS=-MP -MD
CFLAGS=-Wall -Wextra -g $(foreach D,$(INCDIR),-I$(D)) $(OPT) $(DEPFLAGS)

SRC=$(foreach D,$(SRCDIR),$(wildcard $(D)/*.c))
MAIN=$(foreach D,$(MAINDIR),$(wildcard $(D)/*.c))

OBJ=$(patsubst %.c,%.o,$(SRC))
DEP=$(patsubst %.c,%.d,$(MAIN) $(SRC))

EXE=$(patsubst %.c,%,$(MAIN))
MAINOBJ=$(patsubst %.c,%.o,$(MAIN))

TEST=$(foreach D,$(BINDIR),$(wildcard $(D)/test*))

all: $(EXE)

$(EXE): %: %.o $(OBJ) | $(BINDIR)
	$(CC) -o $(addprefix $(BINDIR)/, $(notdir $@)) $^ $(LDFLAGS)

$(BINDIR):
	mkdir -p $(BINDIR)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

check: all
	$(MAKE) $(TEST)

PASS = \e[32;01m
NO_C = \e[0m

$(TEST): FORCE
	@printf ">>> $(notdir $@)\n"
	@$@ && printf "\t\e[32;01m[ PASSED ]\e[0m\n"

clean:
	rm -rf $(MAINOBJ) $(OBJ) $(DEP) $(BINDIR)

FORCE: ;

-include $(DEP)

.PHONY: all check clean
