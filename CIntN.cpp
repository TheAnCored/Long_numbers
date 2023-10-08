#include "CIntN.h"
//----------------------------

// Конструкторы
CIntN::CIntN(){
    length_ = N;

    for(int i=0; i<N; i++){
        this->digit_[i] = 0;
    }
}

CIntN::CIntN(const int n){
    length_ = n;

            // ----------- Построение числа из N знаков
            char digit;
            //size_t tmp=0;
            size_t amt=0;

            std::cout << "Input your positive digit("<< N <<" symbol/s): "<<std::endl;

            while(std::cin.get(digit) || amt<N){
                if(digit == '\n') break;
                digit_[amt] = digit - '0';

                amt++;
            }

            if(amt != N){
                std::cout<<"\n\n";
                for(int i=amt, j=0; j<=N; j++){
                    if(i>=0) {
                        digit_[N - j] = digit_[i];
                        i--;
                    }
            else{
                digit_[N-j] = 0;
            }
        }
    }
}

CIntN::CIntN(int array[N]){
    this->length_ = N;

    for(int i=0; i<N; i++){
        this->digit_[i] = array[i];
    }
}


//----------------------------
// Оператор сложения
CIntN CIntN::operator+(const CIntN& second){

    if(this->length_ != second.length_) {
        throw std::runtime_error("Error! In Vector::operator+\n Different size!\n\n");
    }

    CIntN resInt;

    for(int i=N; i>=0; i--){
        resInt.digit_[i] = this->digit_[i] + second.digit_[i];

        if(resInt.digit_[i]>=10 && i != 0){

            resInt.digit_[i] -= 10;
            resInt.digit_[i]++;

        }
        else if(resInt.digit_[i]>=10 && i == 0){
            throw std::runtime_error(" Error! Exceeding the permissible limit of values!\n\n");
        }
    }

    return resInt;
}

// Оператор вычитания
CIntN CIntN::operator-(const CIntN& second){

    CIntN resInt;

    if(this->length_ != second.length_) {
        throw std::runtime_error("Error! In Vector::operator-\n Different size!\n\n");
    }


    for(int i=0; i<N; i++) {
        if (this->digit_[i] > second.digit_[i]) {
            //flag = 1;
            break;
        } else if (this->digit_[i] == second.digit_[i]) {
            //flag = 0;
        } else {
            //flag = -1;
            throw std::runtime_error(" Error! Exceeding the permissible limit of values!\n\n");
        }
    }

    for(int i=N-1, tmp=0; i>=0; i--){

        resInt.digit_[i] = this->digit_[i] - second.digit_[i];
        if(tmp==-1){ resInt.digit_[i]--;}

        if(resInt.digit_[i] < 0){
            resInt.digit_[i] = 10+resInt.digit_[i];
            tmp=-1;
        }
        else{
            tmp=0;
        }
    }

    return resInt;
}
