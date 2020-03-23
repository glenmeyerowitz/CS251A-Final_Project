all: main train test

main: 
	gcc -o mnist-3lnn -Iutil -lm main.c 3lnn.c util/screen.c util/mnist-utils.c util/mnist-stats.c

train:
	gcc -o mnist-train -Iutil -lm train.c 3lnn.c util/screen.c util/mnist-utils.c util/mnist-stats.c

test:
	gcc -o mnist-test -Iutil -lm test.c 3lnn.c util/screen.c util/mnist-utils.c util/mnist-stats.c

