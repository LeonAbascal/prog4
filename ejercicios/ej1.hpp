#ifndef EJ1_HPP
#define EJ1_HPP

namespace containers
{
    class ArrayInt
    {
    private:
        unsigned int capacity;
        int* array;

    public:
        ArrayInt();
        ArrayInt(unsigned int capacity);
        ~ArrayInt();

        void setValue(unsigned int index, int data);
        int getValue(unsigned int index);
        void setCapacity(unsigned int capacity);
        unsigned int getCapacity();
    };
}

#endif // EJ1_HPP
