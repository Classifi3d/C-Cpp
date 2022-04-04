#include <iostream>

using namespace std;

const int Max1 = 10;
const int Max2 = 10;

class Matrix{
private:
    //atribute
    int matrix[Max1][Max2], dim1, dim2;
    //declararea metodei de afisare a unui element
    int returnElement(int row, int column);
public:
    //constructor explicit cu parametri – recomandat a folosi o metoda diferita a citi valorile
    Matrix(int dim1, int dim2){
        //variabile locale
        int i, j;
        this->dim1 = dim1;
        this->dim2 = dim2;
        cout << "\nIntroduceti elementele matricii: ";
        for (i = 0; i < dim1; i++){
            for (j = 0; j < dim2; j++){
                cout << "\nmatrix[" << i << "][" << j << "] = ";
                cin >> matrix[i][j];
            }
        }
    }
    //metoda de afisare a matricii din clasa; implementare in cadrul clasei
    void displayMatrix(){
        //variabile locale
        int i, j;
        cout << "\nElementele matricii: ";
        for (i = 0; i < dim1; i++){
            cout << "\n";
            for (j = 0; j < dim2; j++){
                //apelul metodei private care returneaza valoarea unui element din matrice
                cout << returnElement(i, j) << " ";
            }
        }
        cout << endl;
    }
   
    void MainDiag(){
        if(this->dim1==this->dim2){
            for(int i=0;i<this->dim1;i++){
                for(int j=0;j<this->dim2;j++){
                    if(i==j){
                        cout << returnElement(i, j) << " ";
                    }
                }
            }
        }else{
            cout<<"this is not a square matix"<<endl;
        }
    }

    void BelowSecoundDiag(){
        if(this->dim1==this->dim2){
            for(int i=0;i<this->dim1;i++){
                for(int j=0;j<this->dim2;j++){
                    if(i+j>this->dim1-1){
                        cout << returnElement(i, j) << " ";
                    }
                }
            }
        }else{
            cout<<"this is not a square matix"<<endl;
        }
        
    }

    void HeatMap(int treshold){
        if(this->dim1==this->dim2){
            for(int i=0;i<this->dim1;i++){
                for(int j=0;j<this->dim2;j++){
                    if(returnElement(i, j)>treshold){
                        cout<<'1'<<" ";
                    }else cout<<'0'<<" ";
                }
                cout<<endl;
            }
        }else{
            cout<<"this is not a square matix"<<endl;
        }
    }

    

    void displayColumn(int col);
};

//implementarea externa a metodelor (publice sau private) declarate in clasa
void Matrix::displayColumn(int col){
    if (col < 0 || col >= dim2){
        cout << "\nColoana cu numarul " << col << " nu exista in matricea din clasa!\n";
    }
    else{
        cout << "\nElementele coloanei " << col << ": ";
        for (int i = 0; i < dim1; i++){
            cout << returnElement(i, col) << " ";
        }
    }
}

int Matrix::returnElement(int row, int column){
    return matrix[row][column];
}

int main()
{
    int dim1, dim2;
    cout << "Introduceti dimensiunile 1 si 2 ale matricii: (<=10):\n";
    cin >> dim1;
    cin >> dim2;
    Matrix m1(dim1, dim2); //instantiere cu citire valori
    Matrix* p = &m1;
    p->displayMatrix();
    int c;
    cout << "Insert a number to compare it the matrix's elements: ";
    cin>>c;
    p->MainDiag();
    cout<<endl<<"========================="<<endl;
    p->BelowSecoundDiag();
    cout<<endl<<"========================="<<endl;
    p->HeatMap(c);
}
