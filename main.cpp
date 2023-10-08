#include <iostream>
#include "autotests.h"

int main(void) {
    try {
        if(MainTest() != 0){
            std::cout<< "Test not complete!"<<std::endl;
            return 1;
        }else{std::cout<<"\n\nTests complete!\n"<<std::endl;}

        const int n=N;

        CIntN digit1(n);
        CIntN digit2(n);

        CIntN res = digit1.operator+(digit2);

        std::cout<<'\n';
        for(int i=0; i<N; i++) {
            std::cout << res.digit_[i];
        }
        std::cout<<'\n';

        res = digit1.operator-(digit2);

        std::cout<<'\n';
        for(int i=0; i<N; i++) {
            std::cout << res.digit_[i];
        }
        std::cout<<std::endl;

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
