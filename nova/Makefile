OBJ = dumprb.o rb.o radix50.o

dumprb : $(OBJ)
#	$(CC) -o $@ $>  ## uncomment this line if using BSD make

clean : 
	rm $(OBJ)

rb.o : rb.h
dumprb.o : rb.h
radix50.o : rb.h

divtest: divtest.c
	$(CC) $(CFLAGS) -o $@ $^
