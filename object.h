#include <cmath>
#define PI 3.14159265


class Cylindrical
{
public:
    double rho,psi,z;
    Cylindrical()
    {
        rho=0;
        psi=0;
        z=0;
    }
    Cylindrical(double a ,double b,double c)
    {
        rho=a;
        psi=b;
        z=c;
    }
    void print()
    {
        std::cout<<"Cylindrical Coordinates are "<<" <"<<rho<<", "<<psi<<", "<<z<<"> "<<std::endl;
    }
};


class Spherical
{
public:
    double r,psi,theta;
    Spherical()
    { 
        r=0;
        theta=0;
        psi=0;

    }
    Spherical(double a ,double b,double c)
    { 
        r=a;
        theta=b;
        psi=c;

    }
    void print()
    {
        std::cout<<"Spherical Coordinates are"<<" <"<<r<<", "<<theta<<", "<<psi<<" >"<<std::endl;
    }
};


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
    virtual void print()
    {
        std::cout<<"<"<<X<<","<<Y<<","<<Z<<">"<<std::endl;
    }
    Cylindrical  tocylindrical()
    {
        double rho = sqrt(X*X + Y*Y);
        double psi;
       
            psi = atan(Y/X) ;
            psi =  (psi * 180) / PI ;
        
        //if(psi<0) { psi+= 180;}
        //else { psi-=180;}
        Cylindrical values(rho,psi,Z);
        return values;
    }

    Spherical  tospherical()
    {
        double rho = sqrt(X*X + Y*Y + Z*Z);
        double psi;

        
           psi =  atan(Y/X) ;
            psi =(psi * 180) / PI;
        
        double theta =  atan(sqrt(X*X + Y*Y)/Z);
        theta = (theta * 180) / PI ;
        if(theta<0) { theta += 180 ; }
        Spherical values(rho,theta,psi);
        return values;
    }

};

//from here
Spherical CylindricaltoSpherical(Cylindrical& A)
{
    double r,theta;
    r = sqrt(A.rho*A.rho + A.z*A.z);
    theta = atan(A.rho/A.z);
    theta = (theta*180) / PI;
    if(theta<0) { theta += 180 ; }
    Spherical value(r,theta,A.psi);
    return value;
}

Cylindrical SphericaltoCylindrical(Spherical& A)//(scn)
{
    double rho,z;
    double angle1 = A.psi * (PI/180);
    rho = A.r*sin(angle1);
    z = A.r * cos(angle1);
    Cylindrical value(rho,A.psi,z);
    return value;
}
Vector_ CylindricaltoCartesian(Cylindrical& A)
{
    double x,y;
     double angle1 = A.psi * (PI/180);
    x = A.rho * cos(angle1);
    y = A.rho *sin(angle1);
    Vector_ value(x,y,A.z);
    return value;
} 
Vector_ SphericaltoCartesian(Spherical& A)
{
    double x,y,z;
     double angle1 = A.psi * (PI/180);
      double angle2 = A.theta * (PI/180);
    x = A.r * sin(angle2) * cos(angle1);
    y = A.r * sin(angle2) * sin(angle1) ;
    z = A.r * cos(angle2);
    Vector_ value(x,y,z);
    return value;
}

//vector transformations
Vector_ cartesian_cylindrical(Vector_ vec,Cylindrical point)
{
    //coefficients
    Vector_ final;

   
    double angle = point.psi * (PI/180);
    
    final.X = (vec.X * cos(angle) ) + (vec.Y * sin(angle)) ;
    final.Y = (-1*vec.X*sin(angle)) + ((vec.Y) * cos(angle));
    final.Z = vec.Z;
    return final;
}

Vector_ cartesian_spherical(Vector_ vec,Spherical point)
{
    Vector_ final;
    double anglepsi = point.psi * (PI/180) ;
    double angletheta = point.theta * (PI/180);
    final.X = (vec.X*sin(angletheta)*cos(anglepsi)) + (vec.Y*sin(angletheta)*sin(anglepsi)) + (vec.Z * cos(angletheta));
    final.Y = (vec.X*cos(angletheta)*cos(anglepsi)) + (vec.Y*cos(angletheta)*sin(anglepsi)) + (vec.Z * sin(angletheta) * -1);
    final.Z = (-1*vec.X*sin(anglepsi)) + ((vec.Y) * cos(anglepsi));
    return  final;
}
