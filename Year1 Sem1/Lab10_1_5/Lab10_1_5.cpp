
#define  _CRT_SECURE_NO_WARNINGS
#include  <iostream>
using  namespace  std;

#define  MAX  20

int  dimension(char  v[]);

int  main()  {
        char  a[MAX],b[MAX];
        printf("Read  from  the  keyboard  two  arrays  of  characters  representing  the  name  and  surename  of  a  person.  The  program  will  display  them  with  capital  letters,  separated  by  a  <Tab>  space\n");
        scanf("%s  %s",  a,b);
		char* firstName = a, * lastName = b;
        for  (int  i  =  0;  i  <  dimension(firstName);  i++)  {
                printf("%c",  firstName[i]-32);
        }printf("\t");
        for  (int  i  =  0;  i  <  dimension(lastName);  i++)  {
                printf("%c",  lastName[i]  -  32);
        }

        return    0;
}

int  dimension(char  v[])  {
        for  (int  i  =  0;  i  <  MAX;  i++)  {
                if  (v[i]  ==  '\0')  {
                        return  i;
                }
        }
        return  0;
}