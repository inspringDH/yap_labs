#include <iostream>
#include <cmath>

using namespace std;

double get_speed()
{
    double speed;

    while (true)
    {
        cout << "Please enter speed: " << endl;
        cin >> speed;

        if (cin.fail() || speed < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Incorrect value passed" << endl;
        }
        else
        {
            return speed;
        }
    }
}

double get_mass()
{
    return 9.1 * pow(10, -31);
}

double get_speed_of_light()
{
    return 2.998 * pow(10, 8);
}

double calculate_kinetic_energy(
    double speed,
    double speed_of_light,
    double mass)
{
    double numerator = mass * pow(speed_of_light, 2);
    double denominator = sqrt(1 - pow(speed / speed_of_light, 2));

    return (numerator / denominator) - numerator;
}

double non_relativistic(double speed, double mass)
{
    return mass * pow(speed, 2) / 2;
}

int main()
{
    double speed = get_speed();
    double speed_of_light = get_speed_of_light();
    double mass = get_mass();
    double kinetic_energy = calculate_kinetic_energy(speed, speed_of_light, mass);

    cout << "With speed = " << speed << " kinetic energy = " << kinetic_energy << endl;
    cout << "Kinetic energy by non_relativistic = " << kinetic_energy << endl;

    return 0;
}