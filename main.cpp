#include <iostream>
#include "object.h"


int main()
{
    
    //for point transformation
    /*
   char input,output;
   std::cout<<"Use inputs a b c to enter a Cartesian,Cylindrical Or Spherical Coordinate respectively"<<std::endl;
   std::cout<<"Use inputs 1,2,3 to convert it to Cartesian,Cylindrical Or Spherical Coordinates respectively"<<std::endl;
   std::cin>>input;
   std::cin>>output;
   switch (input)
   {
   case 'a': //Cartesian coordinate is entered
   {
    std::cout<<"Enter the cartesian coordinates"<<std::endl;
    Vector_ coordinate1;
    std::cin>> coordinate1.X>>coordinate1.Y>>coordinate1.Z;
    if(output == '1') 
    {
        coordinate1.print();
        return 0;
    }
    else if(output == '2')
    {
        Cylindrical coordinate1cyl = coordinate1.tocylindrical();
        coordinate1cyl.print();
        return 0;
    }
    else if(output == '3')
    {
        Spherical coordinate1sph = coordinate1.tospherical();
        coordinate1sph.print();
        return 0;
    }
    else 
    {
        std::cout<<"Enter an Valid output!!!!!"<<std::endl;
        return 0;
    }
    break;
   }
    case 'b': //Cylindrical Coordinate is entered
    {
    std::cout<<"Enter the Cylindrical coordinates"<<std::endl;
    Cylindrical coordinate2;
    std::cin>> coordinate2.rho>>coordinate2.psi>>coordinate2.z;
    if(output == '1') 
    {
        Vector_ coordinate2vec = CylindricaltoCartesian(coordinate2);
        coordinate2vec.print();
        return 0;
    }
    else if(output == '2')
    {
        coordinate2.print();
        return 0;
    }
    else if(output == '3')
    {
        Spherical coordinate2sph = CylindricaltoSpherical(coordinate2);
        coordinate2sph.print();
        return 0;
    }
    else 
    {
        std::cout<<"Enter an Valid output!!!!!"<<std::endl;
        return 0;
    }
    }
    case 'c': //Spherical Coordinates
    {
    std::cout<<"Enter the Spherical coordinates"<<std::endl;
    Spherical coordinate3;
    std::cin>> coordinate3.r>>coordinate3.theta>>coordinate3.psi;
    if(output == '1') 
    {
        Vector_ coordinate3vec = SphericaltoCartesian(coordinate3);
        coordinate3vec.print();
        return 0;
    }
    else if(output == '2')
    {
        Cylindrical coordinate3cyl = SphericaltoCylindrical(coordinate3);
        coordinate3cyl.print();
        return 0;
    }
    else if(output == '3')
    {
        coordinate3.print();
        return 0;
    }
    else 
    {
        std::cout<<"Enter an Valid output!!!!!"<<std::endl;
        return 0;
    }
    }
   default:
    std::cout<<"Enter an Valid Input!!!!!"<<std::endl;
    break;
   }
   */
   
    //taking the input
    //a vector and a point
    
    std::cout<<"Enter the coefficients of cartesian vector"<<std::endl;
    Vector_ vector1;
    
    std::cin>> vector1.X>>vector1.Y>>vector1.Z;
    
    std::cout<<"Enter the point where the vector is at"<<std::endl;
    Vector_ point;
    std::cin>> point.X>>point.Y>>point.Z;\
    
     //using the point calculating rho, psi, theta ..etc
        
    Spherical sphericalpoints = point.tospherical();
    Cylindrical cylindricalpoints = point.tocylindrical();\
        
        
    //transforming the vector
    Vector_ cylin = cartesian_cylindrical(vector1,cylindricalpoints);
    std::cout<<"The Cylindrical system vector is:- "<<std::endl;
    cylin.print();
    
    Vector_ sph = cartesian_spherical(vector1,sphericalpoints);
    std::cout<<"The Spherical system vector is:- "<<std::endl;
    sph.print();
    
}
