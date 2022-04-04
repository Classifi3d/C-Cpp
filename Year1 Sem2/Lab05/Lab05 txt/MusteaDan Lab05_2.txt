class String{
    private:
        char* array;
        char arrayCp[];
    public:
        String(){
            array="";
        };//no parameters passed
        String(char* array){
            this->array=array;
        };

       void setString(char* array){
            this->array=array;
        }
        char* getString(){
            return array;
        }
        int getLength(){
            int i=0,maxFailsafe=10000;
            while(array[i]!='\0'&&i<maxFailsafe){
                i++;
            }
            return i;
        }
        int getLastOccurance(char a){
            int dim=getLength(),lastOccuranceIndex=-1;
            for(int i=0;i<dim;i++){
                if(array[i]==a){
                    lastOccuranceIndex=i;
                }
            }
            return lastOccuranceIndex;
        }
        char* getStringUpper(){
            int dim=getLength();
            for(int i=0;i<dim;i++){
               if(array[i]>='a' && array[i]<='z'){
                    this->arrayCp[i]=array[i]-32;
                }else{
                    this->arrayCp[i]=array[i];
                }
            }this->arrayCp[dim]='\0';
            return arrayCp;
        };
        int getLastOccuranceUpper(char a){
            getStringUpper();
            int dim=getLength(),lastOccuranceIndex=-1;
            for(int i=0;i<dim;i++){
                if(this->arrayCp[i]==a){
                    lastOccuranceIndex=i;
                }
            }
            return lastOccuranceIndex;
        }

};