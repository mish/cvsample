

CC := gcc

cvline-sample: cvline-sample.o
	g++ -o $@ $< `pkg-config --libs opencv`

cvcpp-sample: cvcpp-sample.o
	g++ -o $@ $< `pkg-config --libs opencv`

#.cpp.o:
#	g++ -o $@ -c $< `pkg-config --cflags opencv`

clean:
	${RM} *.o


