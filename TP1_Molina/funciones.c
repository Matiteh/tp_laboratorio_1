double suma (double numA, double numB){
    return (numA+numB);
}

double resta (double numA, double numB){
    return (numA-numB);
}

double division (double numA, double numB){
    return (numA/numB);
}

double multiplicacion (double numA, double numB){
    return (numA*numB);
}

double factorial (double num){
    double result = 1;
    if (num<=0){
        result =0;
    }else if(num==1){
        result=1;
    }else{
       for(double i=1; i<=num; i++)
        {
            result=result*i;
        }
    }
    return result;
}

