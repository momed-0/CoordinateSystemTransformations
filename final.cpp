#include <iostream>


#include <cmath>
#define PI 3.14159265


//methods to convert a cartesian vector then to cylindrical then to spherical


class Vector_
{
public:
    double X = 0.0;
    double Y = 0.0;
    double Z = 0.0;
    Vector_(double a ,double b,double c)
    {
        X = a;
        Y=b;
        Z=c;
    }
    Vector_()
    {
        X = 0;
        Y=0;
        Z=0;
    }
    void print()
    {
        std::cout<<"<"<<X<<","<<Y<<","<<Z<<">"<<std::endl;
    }
    

};


//vector transformations


Vector_ cartesian_cylindrical(Vector_ vec,Vector_ point)
{
    
    Vector_ final;
    
    //finding the terms in the equation one by one
    
    double rho = sqrt(point.X*point.X + point.Y*point.Y);
    double cosphi = point.X / rho;
    double sinphi = point.Y/rho;
    
    final.X = (vec.X * cosphi ) + (vec.Y *sinphi) ;
    final.Y = (-1*vec.X*sinphi) + ((vec.Y) * cosphi);
    final.Z = vec.Z;
    return final;
}

Vector_ cartesian_spherical(Vector_ vec,Vector_ point)
{
    Vector_ final;
      //finding the terms in the equation one by one
      
    double rho = sqrt(point.X*point.X + point.Y*point.Y);
    double cosphi = point.X / rho;
    double sinphi = point.Y/rho;
    double r = sqrt(point.X*point.X + point.Y*point.Y + point.Z*point.Z);
    double costheta = point.Z/r;
    double sintheta = rho/r;
    
    final.X = (vec.X*sintheta*cosphi) + (vec.Y*sintheta*sinphi) + (vec.Z * costheta);
    final.Y = (vec.X*costheta*cosphi) + (vec.Y*costheta*sinphi) + (vec.Z * sintheta * -1);
    final.Z = (-1*vec.X*sinphi) + ((vec.Y) * cosphi);
    return  final;
}


int main()
{
    
    std::cout<<"Enter the coefficients of cartesian vector"<<std::endl;
    Vector_ vector1;
    
    std::cin>> vector1.X>>vector1.Y>>vector1.Z;
    
    std::cout<<"Enter the point where the vector is at"<<std::endl;
    Vector_ point;
    std::cin>> point.X>>point.Y>>point.Z;
    
    //transforming the vector
    Vector_ cylin = cartesian_cylindrical(vector1,point);
    std::cout<<"The Cylindrical system vector is:- "<<std::endl;
    cylin.print();
    
    Vector_ sph = cartesian_spherical(vector1,point);
    std::cout<<"The Spherical system vector is:- "<<std::endl;
    sph.print();
    
    
}
