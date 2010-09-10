
# We keep debugging info around, for fun, but most users don't need it
CFLAGS = -g
#CFLAGS = -O
LINKFLAGS = -g
#LINKFLAGS = -s # for smaller (stripped) executables on many UNIX systems

# What C compiler are you using?
CC = cc

# uncomment the second line if you use pdftex to bypass .dvi files
#PDFTEX = dvipdfm
PDFTEX = pdftex

##########  You shouldn't have to change anything after this point #######

CWEAVE = cweave
CTANGLE = ctangle

SOURCES = utils.w

.SUFFIXES: .dvi .tex .w .pdf

.w.tex:
	$(CWEAVE) $*

.tex.dvi:	
	tex $<

.w.dvi:
	make $*.tex
	make $*.dvi

.w.c:
	$(CTANGLE) $*

.w.o:
	make $*.c
	make $*.o

.w.pdf:
	make $*.tex
	case "$(PDFTEX)" in \
	 dvipdfm ) tex "\let\pdf+ \input $*"; dvipdfm $* ;; \
	 pdftex ) pdftex $* ;; \
	esac

all: utils.pdf utils.c

install: ../src/utils.c

../src/utils.c: utils.c
	cp utils.c ../src/utils.c
