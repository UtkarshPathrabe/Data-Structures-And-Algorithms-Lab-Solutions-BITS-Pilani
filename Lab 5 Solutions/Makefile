.c.o:
	gcc -c -o $@ $<

clean:
	rm -vf *.exe *.o

revoke:	Driver.c MyHash.c *.h
	gcc -o revoke.exe -g Driver.c -g MyHash.c

dvlist: Driver1.c PopulateDrivers.c PopulateVehicles.c *.h
	gcc -o dvlist.exe -g Driver1.c -g PopulateDrivers.c -g PopulateVehicles.c


