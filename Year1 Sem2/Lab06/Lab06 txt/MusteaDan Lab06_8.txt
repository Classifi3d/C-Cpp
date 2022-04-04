#include <iostream>
#include <cstring>
#include <time.h>

using namespace std;

class Person
{
    // membri private
    char nume[16];
    char prenume[24];
    char cnp[14];
    // structura CNP: S AN LU ZI 6cifre; total 13 cifre
public:
    // membri publici
    void setNume(char *n);
    void setPrenume(char *p);
    int setCnp(char *c); //ret. valori functie tip CNP
    int setValidCnp(char *C);
    char *getNume(void)
    {
        return nume;
    }
    char *getPrenume(void)
    {
        return prenume;
    }
    char *getCnp(void)
    {
        return cnp;
    }
    char get_gender(void);
    int get_an_nast(void);
    int get_luna_nast(void);
    int get_zi_nast(void);
    int get_varsta(void);
};
void Person::setNume(char *n)
{
    if (n != 0)
        strncpy(nume, n, 15);
    else
        strcpy(nume, "Necunoscut");
}
void Person::setPrenume(char *p)
{
    if (p != 0)
        strncpy(prenume, p, 23);
    else
        strcpy(prenume, "Necunoscut");
}
int Person::setCnp(char *c)
{
    char buf[3];
    int n;
    if (c != 0)
    {
        // validare CNP: numai pentru cifra sex, cifrele pentru AN, LU, ZI
        cnp[13] = '\0';
        if (strlen(c) != 13)
            return 1;
        if (c[0] != '1' && c[0] != '2')
            return 2;
        strncpy(buf, c + 1, 2);
        buf[2] = '\0';
        n = atoi(buf);
        if (n > 99)
            return 3; //inconsistent
        strncpy(buf, c + 3, 2);
        buf[2] = '\0';
        n = atoi(buf);
        if (n == 0 || n > 12)
            return 4;
        strncpy(buf, c + 5, 2);
        buf[2] = '\0';
        n = atoi(buf);
        if (n == 0 || n > 31)
            return 5;
        strcpy(cnp, c);
        return 0;
    }
}
char Person::get_gender(void)
{
    if (cnp[0] == '1')
        return 'M';
    if (cnp[0] == '2')
        return 'F';
    return 'X';
}
int Person::get_an_nast(void)
{
    char buf[3];
    strncpy(buf, cnp + 1, 2);
    buf[2] = '\0';
    return (1900 + atoi(buf));
}
int Person::get_luna_nast(void)
{
    char buf[3];
    strncpy(buf, cnp + 3, 2);
    buf[2] = '\0';
    return (atoi(buf));
}
int Person::get_zi_nast(void)
{
    return ((cnp[5] - '0') * 10 + (cnp[6] - '0'));
}
int Person::get_varsta(void)
{
    struct tm *newTime;
    time_t szClock;
    time(&szClock);
    newTime = localtime(&szClock);
    int an_c = 1900 + newTime->tm_year;
    int an_n = get_an_nast();
    int n = an_c - an_n;
    int lu_c = newTime->tm_mon + 1;
    int lu_n = get_luna_nast();
    if (lu_c < lu_n)
        n--;
    else
    {
        if (lu_c == lu_n)
        {
            int zi_c = newTime->tm_mday;
            int zi_n = get_zi_nast();
            if (zi_c < zi_n)
                n--;
        }
    }
    return n;
}

int Person::setValidCnp(char *C){
    /* S|AA|LL|ZZ|JJ|NNN|C
    S-Sex; A-year; L-Month; Z-Day; J-County; N-Person diferentiator; C-control number
    */
    if(strlen(C)!=13){
        return false;
    }
    int c[13];
    for(int i=0;i<13;i++){
        c[i]=C[i]-48;
    }
    
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    bool flag=true;
    int day = aTime->tm_mday;
    int month = aTime->tm_mon + 1;
    int year = aTime->tm_year + 1900;
    int cnp=0;
    
    if(c[0]>=1 && c[0]<=8){// S | valid sex integers
        cnp=c[0];
    }else{
        return false;
    }
    //  valid year (so that the cnp of ppl that will be born in the future are no availabe now)
    //               (the situation in which is inserted is before 1800 is eliminiated by the sex\centuary digit)
    if(c[0]==5 || c[0]==6){//A
        int yr1=c[1]*10+c[2];
        int yr2=year%100;
        if(yr1>yr2){
            return false;
        }
        int l1=c[3]*10+c[4];
        if(l1>=0 && l1<=12){//L
            if(l1>month){
                return false;
            }else{
                int d1=c[5]*10+c[6];
                if(d1>=1&&d1<=31){//Z
                    if(d1>day){
                        return false;
                    }
                }else{
                    false;
                }
            }
        }else{
            false;
        }
    }
    int l1=c[3]*10+c[4];
    if(!(l1>=0 && l1<=12)){//L
        return false;
    }
    int d1=c[5]*10+c[6];//Z
    if(!(d1>=1&&d1<=31)){
        return false;
    }
    int county=c[7]*10+c[8];
    if(!(county>=1&&county<=52)){
        return false;
    }
    //N - there's no way to validate this because it's the persons own id
    //C - control digit
    int sum=0,d=0;
    for(int i=0;i<12;i++){
        sum+=c[i];
    }
    d=sum%11;
    if(d==10){
        d=0;
    }
    if(c[12]!=d){
        return false;
    }
    strcpy(this->cnp, C);
}


int main()
{
    Person p1;
    char aux_string[30];
    cout << "\nEnter Name: ";
    cin >> aux_string; //Popescu
    p1.setNume(aux_string);
    cout << "\nEnter SurName: ";
    cin >> aux_string; //Bitanescu
    p1.setPrenume(aux_string);
    cout << "\nEnter CNP: ";
    cin >> aux_string; //1890403120671
    p1.setValidCnp(aux_string);
    cout << "Date despre obiect: " << endl;
    cout << "\tNume: " << p1.getNume() << ", Prenume: " << p1.getPrenume() << ", CNP: " << p1.getCnp() << endl;
    cout << "\tSex: " << p1.get_gender() << endl;
    cout << "\tData nasterii: " << p1.get_an_nast() << "/" << p1.get_luna_nast() << "/" << p1.get_zi_nast() << endl;
    cout << "\tVarsta: " << p1.get_varsta() << endl;
}