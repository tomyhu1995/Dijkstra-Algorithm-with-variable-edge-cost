CC = gcc

EXE_NAME = DJ_Algorithm_EXE

CFLAGS = 

LIB = 

INC = 
INC += -I./

SRC = 
SRC += ./main
SRC += ./path_cal

SRC_FILES = ${addsuffix .c, ${SRC}}
OBJ_FILES = ${addsuffix .o, ${SRC}}

all: ${EXE_NAME}

$(EXE_NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ_FILES) -o $@ 
$(OBJ_FILES): %.o: %.c
	$(CC) $(CFLAGS) $(INC) -c  $< -o $@ 
clean:
	rm -f ${OBJ_FILES} ${EXE_NAME}
