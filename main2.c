#include <iostream>
#include <cmath>

class Electric_Field{
private:
    double *E;

public:
    //constructors, destructor, setters and getters
    Electric_Field(){
        E =new double[3]{0.0,0.0,0.0};
    }
    
    Electric_Field(double x,double y,double z){
        E=new double [3]{x,y,z};
    }
    //'~' = NOT Unary complement (bit inversion)
    ~Electric_Field(){
        delete[]E;
    }
    
    void set_component(int index, double value){
        if (index >=0 && index <3) {
            E[index] = value;
        }
    }

    double get_component(int index) const{
        if (index >=0 && index <3) {
            return E[index];
        }
        return 0;
    }

    //calculate magnitude
    double calculate_magnitude() const {
        return std::sqrt(E[0]*E[0]+E[1]*E[1]+E[2]*E[2]);
    }

    //calculate inner product of the vector
    double calculate_inner_product() const {
        return E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
    }
};

class Magnetic_Field {
private:
    double *B;

public:
    //constructors, destructor, setters and getters
    Magnetic_Field(){
        B=new double[3]{0.0,0.0,0.0};
    }

    Magnetic_Field(double x,double y,double z) {
        B=new double[3]{x,y,z};
    }
    ~Magnetic_Field(){
        delete[]B;
    }

    void set_component(int index, double value){
        if (index >=0 && index <3) {
            B[index] = value;
        }
    }

    double get_component(int index) const{
        if (index >= 0 && index < 3){
            return B[index];
        }
        return 0; 
    }

    //calculate magnitude
    double calculate_magnitude() const{
        return std::sqrt(B[0]*B[0]+B[1]*B[1]+B[2]*B[2]);
    }

    //calculate unit vector
    void calculate_unit_vector() const{
        double magnitude = calculate_magnitude();
        if (magnitude == 0) {
            std::cout<<"Unit vector is undefined for zero magnitude.\n";
            return;
        }
        std::cout<<"Unit vector: ["<<B[0]/magnitude<<", "<<B[1]/magnitude<<", "<<B[2]/magnitude<<"]\n";
    }
};

int main() {
    Electric_Field E_default;
    Magnetic_Field B_default;

    Electric_Field E_components(1e5, 10.9, 1.7e2);
    Magnetic_Field B_components(5.0, 3.0, 2.0);

    std::cout<<"Electric field magnitude(default): "<<E_default.calculate_magnitude()<<"\n";
    std::cout<<"Electric field magnitude(components): "<<E_components.calculate_magnitude()<<"\n";

    std::cout<<"Magnetic field magnitude(default): "<<B_default.calculate_magnitude()<<"\n";
    std::cout<<"Magnetic field magnitude(components): "<<B_components.calculate_magnitude()<<"\n";

    std::cout<<"Inner product of electric field(components): "<< E_components.calculate_inner_product()<<"\n";
    std::cout<<"Magnetic field unit vector(components): ";
    B_components.calculate_unit_vector();

    return 0;
}


