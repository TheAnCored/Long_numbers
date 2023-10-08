#include "autotests.h"

int SummTest(){

    int arr1[N];
    int arr2[N];

    for(int i=0; i<N; i++){
        arr1[i] = 0;

        if(i==N-1){
            arr1[i] = 1;
        }
    }

    for(int i=0; i<N; i++){
        arr2[i] = 0;

        if(i==N-1){
            arr2[i] = 2;
        }
    }

    CIntN digit1(arr1);
    CIntN digit2(arr2);

    CIntN resInt;

    resInt = digit2.operator+(digit1);

    if(resInt.digit_[N-1] == 3){
        return 0;
    }else{ return 1;}
}

int DerivTest(){

    int arr1[N];
    int arr2[N];

    for(int i=0;i<N; i++){
        arr1[i] = 0;

        if(i==N-1){
            arr1[i] = 2;
        }
    }

    for(int i=0;i<N; i++){
        arr2[i] = 0;

        if(i==N-1){
            arr2[i] = 1;
        }
    }

    CIntN digit1(arr1);
    CIntN digit2(arr2);

    CIntN resInt;

    resInt = digit1.operator-(digit2);

    if(resInt.digit_[N-1] == 1){return 0;}
    else{ return 1; }
}

int ConstructorTest(){

    int arr[N];

    for(int i=0;i<N; i++){
        arr[i] = 1;

        if(i==N-1){
            arr[i] = 4;
        }
    }

    CIntN resInt(arr);

    if((( resInt.digit_[0] != 1 ) || (resInt.digit_[N-1]!=4)) && ( N>1 )){
        return 1;
    }
    else if(resInt.digit_[N-1] != 4 && N == 1){
        return 1;
    }else{ return 0; }
}


int MainTest(){
    int index=0;

    if(SummTest()){
        std::cout<<"Error in SummTest()!"<<std::endl;
        index++;

        return index;
    }
    else if(DerivTest()){
        std::cout<<"Error in DerivTest()!"<<std::endl;
        index++;

        return index;
    }
    else if(ConstructorTest()){
        std::cout<<"Error in ConstructorTest()!"<<std::endl;
        index++;

        return index;
    }

    return index;
}