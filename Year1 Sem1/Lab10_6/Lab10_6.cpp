#include <iostream>

using namespace std;

int main()
{
	char* c[4];
	char msg1[] = "I wanted to save the world.";
	char msg2[] = "Control can sometimes be an illusion. But sometimes you need illusions to gain control. Fantasy is an easy way to give meaning to the world.";
	char msg3[]="I do see the beauty in the rules, the invisible code of chaos hiding behind the menacing face of order.";
	char msg4[] = "We're all living in each other's paranoia.";
	c[0] = msg1, c[1] = msg2, c[2] = msg3, c[3] = msg4;
	
	printf("\n");//quote picker
	for (int i = 0; i < 4; i++) {
		printf("%s\n", c[i]);
	}
}

