#
# Makefile template for CSE 30 -- PA2
#

#
# You need to change these next lines for each assignment
#

HEADERS		= pa2.h pa2_strings.h

C_SRCS		= main.c parseKey.c parseInput.c parsePassPhrase.c pa2_globals.c

ASM_SRCS	= createMask.s mycrypt.s parseRotateValue.s rotate.s 

C_OBJS		= main.o parseKey.o parseInput.o parsePassPhrase.o pa2_globals.o

ASM_OBJS	= createMask.o mycrypt.o parseRotateValue.o rotate.o 

OBJS		= ${C_OBJS} ${ASM_OBJS}

EXE		= pa2

#
# You should not need to change anything below this line
#

GCC		= gcc
ASM		= $(GCC)
LINT		= lint

GCC_FLAGS	= -c -g -W -Wall -D__EXTENSIONS__
LINT_FLAGS1	= -c -err=warn
LINT_FLAGS2	= -u -err=warn
ASM_FLAGS	= -c -g
LD_FLAGS	= -g -W -Wall

#
# Standard rules
#

.s.o:
	@echo "Assembling each assembly source file separately ..."
	$(ASM) $(ASM_FLAGS) $<
	@echo ""

.c.o:
	@echo "Linting each C source file separately ..."
	$(LINT) $(LINT_FLAGS1) $<
	@echo ""
	@echo "Compiling each C source file separately ..."
	$(GCC) $(GCC_FLAGS) $<
	@echo ""

#
# Simply have our project target be a single default $(EXE) executable.
#

$(EXE):	$(OBJS)
	@echo "2nd phase lint on all C source files ..."
	$(LINT) $(LINT_FLAGS2) *.ln
	@echo ""
	@echo "Linking all object modules ..."
	$(GCC) -o $(EXE) $(LD_FLAGS) $(OBJS)
	@echo ""
	@echo "Done."

${C_OBJS}:      ${HEADERS}


clean:
	@echo "Cleaning up project directory ..."
	/usr/bin/rm -f *.o $(EXE) *.ln core a.out testrotate
	@echo ""
	@echo "Clean."
# --- Test for createMask ---
testcreateMask: test.h ${HEADERS} createMask.s testcreateMask.c
	@echo "Compiling testcreateMask.c"
	gcc -g -o testcreateMask testcreateMask.c createMask.s 
	@echo "Done."

runtestcreateMask: testcreateMask
	@echo "Running testcreateMask"
	@./testcreateMask

# --- Test for myCrypt ---
testmycrypt: test.h ${HEADERS} mycrypt.s testmycrypt.c rotate.s
	@echo "Compiling testmycrypt.c"
	gcc -g -o testmycrypt testmycrypt.c mycrypt.s rotate.s
	@echo "Done."

runtestmycrypt: testmycrypt
	@echo "Running testmycrypt"
	@./testmycrypt

# --- Test for parseInput ---
testparseInput: test.h ${HEADERS} parseInput.c testparseInput.c
	@echo "Compiling testparseInput.c"
	gcc -g -o testparseInput testparseInput.c parseInput.c 
	@echo "Done."

runtestparseInput: testparseInput
	@echo "Running testparseInput"
	@./testparseInput

# --- Test for parseKey ---
testparseKey: test.h ${HEADERS} parseKey.c testparseKey.c
	@echo "Compiling testparseKey.c"
	gcc -g -o testparseKey testparseKey.c parseKey.c 
	@echo "Done."

runtestparseKey: testparseKey
	@echo "Running testparseKey"
	@./testparseKey

# --- Test for parsePassPhrase ---
testparsePassPhrase: test.h ${HEADERS} parsePassPhrase.c testparsePassPhrase.c
	@echo "Compiling testparsePassPhrase.c"
	gcc -g -o testparsePassPhrase testparsePassPhrase.c parsePassPhrase.c 
	@echo "Done."

runtestparsePassPhrase: testparsePassPhrase
	@echo "Running testparsePassPhrase"
	@./testparsePassPhrase

# --- Test for parseRotateValue ---
testparseRotateValue: test.h ${HEADERS} parseRotateValue.s \
		      testparseRotateValue.c 
	@echo "Compiling testrotate.c"
	gcc -g -o testparseRotateValue testparseRotateValue.c \
	parseRotateValue.s pa2_globals.c
	@echo "Done."

runtestparseRotateValue: testparseRotateValue
	@echo "Running testparseRotateValue"
	@./testparseRotateValue

# --- Test for rotate ---
testrotate: test.h ${HEADERS} rotate.s testrotate.c
	@echo "Compiling testrotate.c"
	gcc -g -o testrotate testrotate.c rotate.s
	@echo "Done."

runtestrotate: testrotate
	@echo "Running testrotate"
	@./testrotate

new:
	make --no-print-directory clean
	make --no-print-directory

