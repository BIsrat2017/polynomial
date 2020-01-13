#include <iostream>
using namespace std;

#include "polynomial.h"

int main( )

{

    Polynomial p1;

    p1.changeCoefficient( 1, 1 );

    p1.changeCoefficient( 4, 4 );

    p1.changeCoefficient( 2.2, 2 );
//
    p1.changeCoefficient( -3.8, 3 );

    cout << "p1 = " << p1 << endl;

    Polynomial T (p1);

    cout << "T1 = " << T << endl;

    p1.changeCoefficient( 0, 2 );

    cout << "p1 = " << p1 << endl;
    cout << "T1 = " << T << endl;

    Polynomial p2 = p1;

    p2.changeCoefficient( 9.5, 2 );

    cout << "p1 = " << p1 << endl;

    cout << "p2 = " << p2 << endl;




    Polynomial p3 = p2 + p1;
//
//    cout << "p3 = " << p3 << endl;
//
//    Polynomial p4 =  p2 - p1 ;
//
//    cout << "p4 = " << p4 << endl;
//
//    Polynomial p5 =  p1 - p2 ;
//
//    cout << "p5 = " << p5 << endl;
//
//    p1.changeCoefficient(2.2,2);
//
//    //p1.changeCoefficient(2,0);
//    cout<<"p1 = "<<p1<<endl;
//
//    cout<< "testEquals = "<<testEquals<<endl;
//
//    bool x;
//    x= p1!=testEquals;
//    std::cout<< x;

}
