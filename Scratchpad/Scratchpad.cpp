#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define PI 3.14159265

int GetValidIntegerInput()
{
    int return_value = 0;
    bool is_valid_input = false;
    string input_string;
    int negative_multiplier;
    
    do
    {
        negative_multiplier = 1;
        cout << "Please enter an Integer number:";
        cin >> input_string;
        if(input_string.empty() == 1)
        {
            cout << "No text detected." << endl;
            continue;
        }
        if(input_string[0] == '-' && input_string.length() >= 2)
        {
            input_string.erase(0, 1);
            cout << "String started with a '-' result after removal: " << input_string << endl;
            negative_multiplier = -1;
        }
        for (char c : input_string) {
            // Checking if the element is number
            if (c >= '0' && c <= '9') {
                return_value = return_value * 10 + (c - '0');
                is_valid_input = true;
            }
            // Otherwise print bad output
            else {
                is_valid_input = false;
                cout << "Bad Input." << endl;
                break;
            }
        }
    }
    while (is_valid_input == false);

    return_value = return_value * negative_multiplier;
    return return_value;
}

int GetIntegerBetweenBounds(int boundary_one, int boundary_two)
{
    int upper_boundary;
    int lower_boundary;
    int input_value;

    if(boundary_one >= boundary_two)
    {
        upper_boundary = boundary_one;
        lower_boundary = boundary_two;
    }
    else
    {
        upper_boundary = boundary_two;
        lower_boundary = boundary_one;
    }
    
    bool is_valid_input = false;
    do
    {
        input_value = GetValidIntegerInput();
        if(upper_boundary > input_value > lower_boundary)
        {
           is_valid_input = true; 
        }
        else
        {
            cout << "Input is out of bounds, please enter a number between: " << lower_boundary << " and " << upper_boundary << "." << endl;
        }
    }
    while(is_valid_input == false);

    return input_value;
}

struct Vector2
{
    float x;
    float y;
};

float GetTriangleOppositeSide(float angle_in_radians)
{
    // soh, sin(x) = opposite/hypotenuse
    // assuming the hypotenuse is 1, adjacent = sin(x)
    return sin(angle_in_radians);
}

float GetTriangleAdjacentSide(float angle_in_radians)
{
    // cah, cosine(x) = adjacent/hypotenuse
    // assuming the hypotenuse is 1, adjacent = cos(x)
    return cos(angle_in_radians);
}

Vector2 GetVectorFromDegrees(float degrees)
{
    Vector2 return_value;
    Vector2 quadrant_vector2;

    cout << "Input degrees: " << degrees << endl;
    while (degrees > 360)
    {
        degrees -= 360;
    }
    cout << "Adjusted to within 360: " << degrees << endl;

    int quadrant = 0;
    while(degrees > 90)
    {
        degrees -= 90;
        quadrant ++;
    }
    
    bool quadrant_swap;

    cout << "Quadrant number: " << quadrant << endl << "Degrees in quadrant: " << degrees << endl;
    switch (quadrant)
    {
    case 0:
        quadrant_vector2.x = 1;
        quadrant_vector2.y = 1;
        quadrant_swap = false;
        break;
    case 1:
        quadrant_vector2.x = 1;
        quadrant_vector2.y = -1;
        quadrant_swap = true;
        break;
    case 2:
        quadrant_vector2.x = -1;
        quadrant_vector2.y = -1;
        quadrant_swap = false;
        break;
    case 3:
        quadrant_vector2.x = -1;
        quadrant_vector2.y = 1;
        quadrant_swap = true;
        break;
    default: // TODO: this should throw an error here as we've somehow broken out of our conditions
        quadrant_vector2.x = 1;
        quadrant_vector2.y = 1;
        quadrant_swap = false;
    }
    
    float radians = degrees * (PI / 180);
    
    cout << "Radians value: " << radians << endl;

    if(quadrant_swap == false)
    {
        return_value.x = GetTriangleOppositeSide(radians);
        return_value.y = GetTriangleAdjacentSide(radians);
    }
    else //if(quadrant_swap == true)
    {
        return_value.y = GetTriangleOppositeSide(radians);
        return_value.x = GetTriangleAdjacentSide(radians);
    }

    return_value.x = return_value.x * quadrant_vector2.x;
    return_value.y = return_value.y * quadrant_vector2.y;
    
    return return_value;
}

int main(int argc, char* argv[])
{
    Vector2 vector_two;

    cout << "Enter an angle as an integer between 0, and 360." << endl;
    int integer_Value = GetIntegerBetweenBounds(0, 360);
    cout << "Value accepted: " << integer_Value << endl;
    vector_two = GetVectorFromDegrees(integer_Value);
    cout << "Vector generated. X:" << vector_two.x << ". and Y:" << vector_two.y << "." << endl;
    return 0;
}