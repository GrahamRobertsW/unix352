objects = warmuptest.o tokenizer.o

warmup : $(objects)
	gcc -Wall -o warmuptest $(objects)
	
%.o : %.c
	gcc -Wall -c -g $<
	
clean : 
	rm -f warmuptest
	rm -f $(objects)
	
