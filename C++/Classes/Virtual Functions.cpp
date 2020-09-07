class Person
{
    public:
        int age;
        char name[100];
    virtual void getdata()=0;
    virtual void putdata()=0;
    
};
class Professor:public Person
{
    public:
    int publications;
    static int cur_id;
    void getdata()
    {
        cin >> name >> age >> publications;
    }
    void putdata()
    {
         cout << name << " " << age << " " << publications << " " << ++cur_id << endl;   
    }
    
};
int Professor::cur_id=0;
class Student:public Person
{
    public:
    int marks[6];
    static int cur_id;
    void getdata()
    {
        cin >> name >> age;
        for(int i = 0; i < 6; i++)
        {
            cin >> marks[i];     
        }
    }
    void putdata()
    {
        int sum = 0;
        for(int i = 0; i < 6; i++)
        {
            sum = sum + marks[i];    
        }
        cout << name << " " << age << " " << sum << " " << ++cur_id << endl;   
    }
 
};
int Student::cur_id = 0;
