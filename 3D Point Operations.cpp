#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

//defined 3d class
class Point_3D {
    public:
        Point_3D(float x, float y, float z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }
        Point_3D() {
            x = 0;
            y = 0;
            z = 0;
        }
        ~Point_3D() {
            cout << "point deleted" << endl;
        }
        void display() {
            cout << "coordinates of the point" << endl;
            cout << x << endl;
            cout << y << endl;
            cout << z << endl;
        }
        void move(int choice, float shift);
        void cast(float ax, float by, float cz, float d);
        void rotate(int choice, float angle);
    private:
        float x, y, z;
};

//expand casting method of the point
void Point_3D::cast(float ax, float by, float cz, float d) {
    
    float t, pom, coeff;
    t = (ax * ax) + (by * by) + (cz * cz);
    pom = (x * ax) + (y * by) + (z * cz) + d;
    coeff = -pom / t;

    x = coeff * ax + x;
    y = coeff * by + y;
    z = coeff * cz + z;

}

//expand rotation method of the point
void Point_3D::rotate(int choice, float angle) {
    float coeffs[3][1] = { {x},{y},{z} };
    float pom[3][1];
    float sum=0;
    float rad_angle = angle * (M_PI/180);

    switch (choice){
        case 1:{
            //x-axis rotation matrix as a two-dimensional array
            float rot_x_axis[3][3] = { {1,0,0},{0,cos(rad_angle),-sin(rad_angle)},{0,sin(rad_angle),cos(rad_angle)} };
    
            //loops performing matrix multiplication to get the new rotated point
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    sum += (rot_x_axis[i][j] * coeffs[j][0]);
                }
                pom[i][0] = sum;
                sum = 0;
            }
            x = pom[0][0];
            y = pom[1][0];
            z = pom[2][0];
            break;
        }
        case 2:{
            //y-axis rotation matrix as a two-dimensional array
            float rot_y_axis[3][3] = { {cos(rad_angle),0,sin(rad_angle)},{0,1,0},{-sin(rad_angle),0,cos(rad_angle)} };
    
            //loops performing matrix multiplication to get the new rotated point
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    sum += (rot_y_axis[i][j] * coeffs[j][0]);
                }
                pom[i][0] = sum;
                sum = 0;
            }
            x = pom[0][0];
            y = pom[1][0];
            z = pom[2][0];
            break;
        }
               case 3:{
            //z-axis rotation matrix as a two-dimensional array
            float rot_z_axis[3][3] = { {cos(rad_angle),-sin(rad_angle),0},{sin(rad_angle),cos(rad_angle),0},{0,0,1} };
    
            //loops performing matrix multiplication to get the new rotated point
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    sum += (rot_z_axis[i][j] * coeffs[j][0]);
                }
                pom[i][0] = sum;
                sum = 0;
            }
            x = pom[0][0];
            y = pom[1][0];
            z = pom[2][0];
            break;
        }
    }


}

void Point_3D::move(int choice, float shift) {
    switch (choice) {
        case 1:{
            x += shift;
            break;
        }
        case 2:{
            y += shift;
            break;
        }
        case 3:{
            z += shift;
            break;
        }
    }
}

int main() {
    
    int x_coord, y_coord, z_coord, nav, temp, temp_coord;
    cout << "3D Point Operations" << endl;
    cout << "=============" << endl;
    cout << "<<MAIN MENU>>" << endl;
    cout << "=============" << endl;
    cout << "Enter 3D point x coordinate:" << endl;
    cin >> x_coord;
    cout << "Enter 3D point y coordinate:" << endl;
    cin >> y_coord;
    cout << "Enter 3D point z coordinate:" << endl;
    cin >> z_coord;


    Point_3D* p1 = new Point_3D(x_coord,y_coord,z_coord);

    cout << "1. Rotation" << endl;
    cout << "2. Move point in space" << endl;
    cout << "Enter: ";
    cin >> nav;

    switch (nav){
        case 1:
                cout << "Choose axis: (1-x, 2-y, 3-z)" << endl;
                cin >> temp_coord;
                cout << "What angle?" << endl;
                cin >> temp;
                p1->rotate(temp_coord, temp);
                p1->display();
                break;
        case 2:
                cout << "Choose axis: (1-x, 2-y, 3-z)" << endl;
                cin >> temp_coord;
                cout << "How much?" << endl;
                cin >> temp;
                p1->move(temp_coord, temp);
                p1->display();
                break;
        
        default:
            cout << "you chose something that does not exist" << endl;
        }
    return 0;
}