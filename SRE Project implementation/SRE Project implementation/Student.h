#include<string>
using namespace std;
struct Inventory
{
    string name;
    int quantity;
    long price;
};

class Student
{
private:
    string name,
        roll_no,
        room_no,
        degree,
        email_id,
        session;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};