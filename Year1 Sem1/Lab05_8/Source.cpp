#define  _CRT_SECURE_NO_WARNINGS
#include  <cstdio>
#include  <conio.h>

int  main() {
	int hourDeparture,hourArrival,minuteDeparture,minuteArrival,hourDifference,minuteDifference;
	printf("Enter the departure time of the train: \n");
	scanf_s("%d%d", &hourDeparture,&minuteDeparture);
	printf("Enter the arrival time of the train: \n");
	scanf_s("%d%d", &hourArrival, &minuteArrival);
	hourDifference = hourArrival - hourDeparture;
	minuteDifference = minuteArrival - minuteDeparture;
	if (minuteDifference < 0) {
		minuteDifference += 60;
		hourDifference--;
	}
	printf("The difference is: %d:%d",hourDifference,minuteDifference);

	return  0;
}

