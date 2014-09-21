.c.o:
	gcc -c -o $@ $<

driver:driver.c iterate.c print.c recur.c stack.c stops.c *.h
	gcc -o driver.exe -g driver.c -g iterate.c -g print.c -g recur.c -g stack.c -g stops.c

clean:
	rm -vf Output1.txt Output2.txt *.exe *.o
