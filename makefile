CC := gcc

OPTIONS = -O2 -g -Wall # -g for debug, -O2 for optimise and -Wall


OBJS = controller.o model.o view.o

SRC = controller.c model.c view.c

HEADERS = controller.h model.h shapes.h

Game:${OBJS}
	${CC} ${OPTIONS} ${OBJS} -o asteroids

${OBJS}: ${SRC} ${HEADERS}
	${CC} ${OPTIONS} -c ${SRC}

clean:
	rm *.o 