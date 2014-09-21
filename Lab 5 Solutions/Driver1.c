#include "OffenceOps.h"

int main(int agrc, char *argv[]){
	FILE *ownerSource = fopen("10000owners.txt", "r");
	owner o = populateVehicles(ownerSource);
	FILE *fp = fopen("Vehicle.txt", "w");
	printVehicleListP(fp, o);
	fclose(fp);
	FILE *driverSource = fopen("40000drivers.txt", "r");
	driver d = populateDrivers(driverSource);
	fp = fopen("Driver.txt", "w");
	printDriversListP(fp, d);
	fclose(fp);
	return 0;
}



