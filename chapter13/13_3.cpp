#include <iostream>
#include <array>
#include <cassert>

/*
a) Write a simple class named Point3d. The class should contain:

Three private member variables of type int named m_x, m_y, and m_z;
A public member function named setValues() that allows you to set values for m_x, m_y, and m_z.
A public member function named print() that prints the Point in the following format: <m_x, m_y, m_z>
*/

class Point3d {
private:
    int m_x{};
    int m_y{};
    int m_z{};
public:
    void setValues(const int x, const int y, const int z) {
        m_x = x;
        m_y = y;
        m_z = z;
    }
    void print() {
        std::cout << '<' << m_x << ", " << m_y << ", " << m_z << '>';
    }
    bool isEqual(const Point3d& point) {
        return (m_x == point.m_x && m_y == point.m_y && m_z == point.m_z);
    }
};

void testPoint3dClass() {

    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(1, 2, 3);

    if (point1.isEqual(point2))
    {
        std::cout << "point1 and point2 are equal\n";
    }
    else
    {
        std::cout << "point1 and point2 are not equal\n";
    }

    Point3d point3;
    point3.setValues(3, 4, 5);

    if (point1.isEqual(point3))
    {
        std::cout << "point1 and point3 are equal\n";
    }
    else
    {
        std::cout << "point1 and point3 are not equal\n";
    }
}

/*
The class should be named Stack, and should contain:

- A private array of integers of length 10.
- A private integer to keep track of the size of the stack.
- A public member function named reset() that sets the size to 0.
- A public member function named push() that pushes a value on the stack.
push() should return false if the array is already full, and true otherwise.
- A public member function named pop() that pops a value off the stack and returns it.
If there are no values on the stack, the code should exit via an assert.
- A public member function named print() that prints all the values in the stack.
*/

class Stack {
private:
    static constexpr size_t maxSize{ 10 };
    using Array = std::array<int, maxSize>;

    Array m_array{};
    int m_size{};

public:
    void reset() {
        m_size = 0;
    }
    bool push(int x) {
        if (m_size < maxSize) {
            m_array[m_size++] = x;
            return true;
        }
        else return false;
    }
    int pop() {
        assert(m_size > 0);
        return m_array[m_size--];
    }
    void print() {
        std::cout << "( ";
        for (int i{ 0 }; i < m_size; ++i) {
            std::cout << m_array[i] << ' ';
        }
        std::cout << ")\n";
    }
};

void testStackClass()
{
    Stack stack;
    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();
}