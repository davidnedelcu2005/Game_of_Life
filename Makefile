build:
	gcc task.c algoritmi.c algoritmi.h -o a.out

run:
	./checker-linux-amd64 -i

clean:
	rm -rf a.out		