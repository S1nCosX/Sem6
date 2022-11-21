LD=ld                                                                                                                                                                                                                                           
GCC=gcc                                                                                                                 
CC= gcc                                                                                           
CFLAGS= -g -O2 -Wall -Werror -std=c17 -Wdiscarded-qualifiers -Wincompatible-pointer-types -Wint-conversion -I./3/include

main_1: 1.o                                                                    
	$(GCC) $^ -o $@

main_2: 2.o                                                                    
	$(GCC) $^ -o $@
	
main_3: ./3/src/vector.o ./3/src/main.o                                                                    
	$(GCC) $^ -o $@

%.o: %.c   	
	$(GCC) -c $(CFLAGS) -o $@ $<

	
.PHONY: clean main_1 main_2 main_3 main_4

clean:      
	rm *.o