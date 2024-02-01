CC=gcc
CFLAGS=-g
BUILD_DIR=build/
BIN_DIR=bin/
BUILD_DIRS=dir
OBJS= 	$(BUILD_DIR)glue_list.o		\
		${BUILD_DIR}test_app.o		\


all: $(BUILD_DIRS) test_app

test_app:$(BUILD_DIR)test_app.o ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $(BIN_DIR)test_app 
	@echo
	@echo BUILD COMPLETE!!
	@echo USE: ./bin/test_app COMMAND TO RUN THE PROGRAM

${BUILD_DIR}test_app.o:test_app.c
	${CC} ${CFLAGS} -c test_app.c -o ${BUILD_DIR}test_app.o

${BUILD_DIR}glue_list.o:glue_list/glue_list.c
	${CC} ${CFLAGS} -c glue_list/glue_list.c -o ${BUILD_DIR}glue_list.o

$(BUILD_DIRS):
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)
clean:
	rm -rf build bin