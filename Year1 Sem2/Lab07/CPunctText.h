const int dim_sir = 20;
class CPunctText
{
    int x;
    int y;
    int lungime_sir;
    char *sNume;

public:
    //constructor explicit vid
    CPunctText();
    //constructor cu parametri
    CPunctText(int ix, int iy, const char *sText = "Punct");
    //constructor de copiere
    CPunctText(const CPunctText &pct);
    //destructor:
    ~CPunctText();
    void Afis()
    {
        cout << "\nObiectul are x= " << x;
        cout << "\nObiectul are y= " << y;
        cout << "\nObiectul are sirul = " << sNume;
    } //afis
    CPunctText(const CPunctText &num1,const CPunctText &num2);
};
CPunctText::CPunctText()
{
    cout << "\n constructor explicit vid";
    lungime_sir = dim_sir;
    sNume = new char[lungime_sir];
}
CPunctText::CPunctText(int ix, int iy, const char *sText)
{
    cout << "\n constructor cu parametri";
    lungime_sir = strlen(sText) + 1;
    sNume = new char[lungime_sir];
    x = ix;
    y = iy;
    strcpy(sNume, sText);
}
CPunctText::CPunctText(const CPunctText &pct)
{
    cout << "\n constructor de copiere";
    sNume = new char[pct.lungime_sir];
    x = pct.x;
    y = pct.y;
    lungime_sir = pct.lungime_sir;
    strcpy(sNume, pct.sNume);
}
CPunctText::~CPunctText()
{
    cout << "\n destructor";
    delete[] sNume;
}

CPunctText::CPunctText(const CPunctText &num1,const CPunctText &num2){
    cout<<endl<<"constructor prin imbinare de puncte";
    this->sNume = new char[num1.lungime_sir+num2.lungime_sir];
    this->x = num1.x+num2.x;
    this->y = num1.y+num2.y;
    this->lungime_sir = num1.lungime_sir+num2.lungime_sir;
    strcpy(sNume, strcat(num1.sNume,num2.sNume));

}