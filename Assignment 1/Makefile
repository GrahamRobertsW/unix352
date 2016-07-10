objects = product.o price.o tokenizer.o hashfile.o

all : prodtest dotrans

prodtest :  prodtest.o $(objects)
	gcc -Wall -o $@ $< $(objects)
	
dotrans : dotrans.o $(objects) 
	gcc -Wall -o $@ $< $(objects)
	
%.o : %.c
	gcc -Wall -c -g $<
	
clean : 
	rm -f prodtest dotrans
	rm -f $(objects)
	
