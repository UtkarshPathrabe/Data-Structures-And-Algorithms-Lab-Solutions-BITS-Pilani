.c.o:
	gcc -c -o $@ $<

clean:
	rm -vf *.exe *.o

insertion-sort:method1.c evaluate.c Input.c makeArray.c print.c *.h
	gcc -o insertionsort.exe -g evaluate.c -g Input.c -g method1.c -g print.c -g makeArray.c

merge-sort:method2.c evaluate.c Input.c makeArray.c print.c *.h
	gcc -o mergesort.exe -g evaluate.c -g Input.c -g method2.c -g print.c -g makeArray.c -lm

quick-sort:method3.c evaluate.c Input.c makeArray.c print.c *.h
	gcc -o quicksort.exe -g evaluate.c -g Input.c -g method3.c -g print.c -g makeArray.c

bubble-sort:method4.c evaluate.c Input.c makeArray.c print.c *.h
	gcc -o bubblesort.exe -g evaluate.c -g Input.c -g method4.c -g print.c -g makeArray.c

selection-sort:method5.c evaluate.c Input.c makeArray.c print.c *.h
	gcc -o selectionsort.exe -g evaluate.c -g Input.c -g method5.c -g print.c -g makeArray.c

count-sort:method6.c evaluate.c Input.c makeArray.c print.c *.h
	gcc -o countsort.exe -g evaluate.c -g Input.c -g method6.c -g print.c -g makeArray.c

sort-time:driver.c Input.c makeArray.c print.c method1.c method2.c method3.c method4.c method5.c *.h
	gcc -o sorttime.exe -g driver.c -g Input.c -g print.c -g method1.c -g method2.c -g method3.c -g method4.c -g method5.c -g makeArray.c -lm
