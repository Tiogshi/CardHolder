# Wedit Makefile for project cardholder
SRCDIR=c:\users\tiogshi\kraken\cardholder
CFLAGS=-I"C:\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	cardholder.obj

LIBS=
EXE=card.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\card.exe $(OBJS) $(LIBS)

# Build cardholder.c
CARDHOLDER_C=\
	C:\lcc\include\stdio.h\
	C:\lcc\include\safelib.h\
	C:\lcc\include\stdlib.h\
	C:\lcc\include\stddef.h\
	C:\lcc\include\string.h\

cardholder.obj: $(CARDHOLDER_C) $(SRCDIR)\cardholder.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\cardholder.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\card.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) card.exe
