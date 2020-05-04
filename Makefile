all: queue_test fifo

queue_test: queue_test.c
	gcc -o queue_test queue_test.c queue.c node.c -Wall -Werror

fifo: fifo.c
	gcc -o fifo fifo.c queue.c node.c -Wall

clean:
	rm -f *.o fifo queue_test