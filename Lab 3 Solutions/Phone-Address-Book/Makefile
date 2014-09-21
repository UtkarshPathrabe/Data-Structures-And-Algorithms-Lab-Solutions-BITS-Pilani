.c.o:
	gcc -c -o $@ $<

phone_book:phone_book.c *.h
	gcc -c phone_book.c

phone_book_driver:phone_book_driver.c *.h
	gcc -c phone_book_driver.c

phone-book:phone_book.c phone_book_driver.c phone_book_main.c *.h
	gcc -o phone-book.exe -g phone_book_driver.c -g phone_book_main.c -g phone_book.c

clean:
	rm -vf *.o *.exe
