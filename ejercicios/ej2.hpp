
namespace containers {

    class Element {
private:
    int data;
    Element* next;

public:
    Element(int data);

    int getData() const;
    void setNext(Element* e);
    Element* getNext() const;

    void toString() const;

    };

    class Stack {

public:
    Element* first;
    unsigned int size;

public:
    Stack();
    ~Stack();

    void push(int data);
    int pop();
    int poll();
    void clear();
    unsigned int getSize();


    };


}
