#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vehicle {
    char ownerName[50];
    char dateOfRegistration[20];
    char vehicleModel[20];
    int numberOfWheels;
};

struct TollRecord {
    int id;
    struct Vehicle vehicle;
    char date[20];
    char direction[10];
    float fare;
};
void displayFareDetails() {
    printf("\nFare Details\n");
    printf("============\n");

    FILE *fp;
    fp = fopen("fare.txt", "r");
    if(fp == NULL) {
        printf("File could not be opened!");
        return;
    }

    printf("1. Two Wheeler - Rs. ");
    float fare;
    fscanf(fp, "%f", &fare);
    printf("%.2f\n", fare);

    printf("2. Three Wheeler - Rs. ");
    fscanf(fp, "%f", &fare);
    printf("%.2f\n", fare);

    printf("3. Four Wheeler - Rs. ");
    fscanf(fp, "%f", &fare);
    printf("%.2f\n", fare);

    printf("4. Six Wheeler - Rs. ");
    fscanf(fp, "%f", &fare);
    printf("%.2f\n", fare);

    printf("5. Eight Wheeler - Rs. ");
    fscanf(fp, "%f", &fare);
    printf("%.2f\n", fare);

    fclose(fp);
}


void updateFareDetails() {
    int choice;
    float fare;
    FILE *fp;
    fp = fopen("fare.txt", "w");
    if(fp == NULL) {
        printf("File could not be opened!");
        return;
    }
    printf("\nEnter Fare Details\n");
    printf("==================\n");
    printf("1. Two Wheeler - Rs. ");
    scanf("%f", &fare);
    fprintf(fp, "%.2f\n", fare);
    printf("2. Three Wheeler - Rs. ");
    scanf("%f", &fare);
    fprintf(fp, "%.2f\n", fare);
    printf("3. Four Wheeler - Rs. ");
    scanf("%f", &fare);
    fprintf(fp, "%.2f\n", fare);
    printf("4. Six Wheeler - Rs. ");
    scanf("%f", &fare);
    fprintf(fp, "%.2f\n", fare);
    printf("5. Eight Wheeler - Rs. ");
    scanf("%f", &fare);
    fprintf(fp, "%.2f\n", fare);
    fclose(fp);
    printf("\nFare Details updated successfully!");
}


void recordTrafficDetails() {
	int id, numberOfWheels;
    char direction[10];
    float fare;
    struct TollRecord record;
    FILE *fp;
    fp = fopen("traffic.txt", "a");
    if(fp == NULL) {
        printf("File could not be opened!");
        return;
    }
    printf("\nEnter Traffic Details\n");
    printf("======================\n");
    printf("Vehicle ID: ");
    scanf("%d", &id);
    record.id = id;
    printf("Owner's Name: ");
    scanf("%s", record.vehicle.ownerName);
    printf("Date of Registration: ");
    scanf("%s", record.vehicle.dateOfRegistration);
    printf("Vehicle Model: ");
    scanf("%s", record.vehicle.vehicleModel);
    printf("Number of Wheels: ");
    scanf("%d", &numberOfWheels);
    record.vehicle.numberOfWheels = numberOfWheels;
    printf("Direction (entry/exit): ");
    scanf("%s", direction);
    strcpy(record.direction, direction);
    printf("Fare: ");
    scanf("%f", &fare);
    record.fare = fare;
    fprintf(fp, "%d|%s|%s|%s|%d|%s|%.2f\n", record.id, record.vehicle.ownerName, record.vehicle.dateOfRegistration, record.vehicle.vehicleModel, record.vehicle.numberOfWheels, record.direction, record.fare);
    fclose(fp);
    printf("\nTraffic Details recorded successfully!");
}

void deleteVehicleRecord() {
    int id;
    char temp;
    struct TollRecord record;
    FILE *fp, *fpTemp;
    fp = fopen("traffic.txt", "r");
    fpTemp= fopen("temp.txt", "w");
if(fp == NULL || fpTemp == NULL) {
printf("File could not be opened!");
return;
}
printf("\nEnter Vehicle ID to delete record: ");
scanf("%d", &id);
while(fscanf(fp, "%d|%[^|]|%[^|]|%[^|]|%d|%[^|]|%f%c", &record.id, record.vehicle.ownerName, record.vehicle.dateOfRegistration, record.vehicle.vehicleModel, &record.vehicle.numberOfWheels, record.direction, &record.fare, &temp) != EOF) {
if(record.id != id) {
fprintf(fpTemp, "%d|%s|%s|%s|%d|%s|%.2f\n", record.id, record.vehicle.ownerName, record.vehicle.dateOfRegistration, record.vehicle.vehicleModel, record.vehicle.numberOfWheels, record.direction, record.fare);
}
}
fclose(fp);
fclose(fpTemp);
remove("traffic.txt");
rename("temp.txt", "traffic.txt");
printf("\nVehicle record deleted successfully!");
}

void searchVehicleRecord() {
int id;
char temp;
struct TollRecord record;
FILE *fp;
fp = fopen("traffic.txt", "r");
if(fp == NULL) {
printf("File could not be opened!");
return;
}
printf("\nEnter Vehicle ID to search record: ");
scanf("%d", &id);
while(fscanf(fp, "%d|%[^|]|%[^|]|%[^|]|%d|%[^|]|%f%c", &record.id, record.vehicle.ownerName, record.vehicle.dateOfRegistration, record.vehicle.vehicleModel, &record.vehicle.numberOfWheels, record.direction, &record.fare, &temp) != EOF) {
if(record.id == id) {
printf("\nVehicle Record Found\n");
printf("=====================\n");
printf("ID: %d\n", record.id);
printf("Owner's Name: %s\n", record.vehicle.ownerName);
printf("Date of Registration: %s\n", record.vehicle.dateOfRegistration);
printf("Vehicle Model: %s\n", record.vehicle.vehicleModel);
printf("Number of Wheels: %d\n", record.vehicle.numberOfWheels);
printf("Direction: %s\n", record.direction);
printf("Fare: %.2f\n", record.fare);
fclose(fp);
return;
}
}
printf("\nVehicle Record not Found!");
fclose(fp);
}

int main() {
int choice;
while(1) {
printf("\nToll Plaza Record System\n");
printf("========================\n");
printf("1. Display Fare Details\n");
printf("2. Update Fare Details\n");
printf("3. Record Traffic Details\n");
printf("4. Delete Vehicle Record\n");
printf("5. Search Vehicle Record\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch(choice) {
case 1:
displayFareDetails();
break;
case 2:
updateFareDetails();
break;
case 3:
recordTrafficDetails();
break;
case 4:
deleteVehicleRecord();
break;
case 5:
searchVehicleRecord();
break;
case 6:
exit(0);
default:
printf("\nInvalid Choice!");
}
}
return 0;
}






