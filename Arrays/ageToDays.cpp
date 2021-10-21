#include<iostream>
using namespace std;
class Age
{
private:
    int age;
public:
    Age(int a)
    {
        age=a;
    }
    int ageToDays()
    {
        return age*365;
    }
};
int main()
{
    int age, days;
    cout<<"Enter the age:";
    cin>>age;
    Age obj(age);
    days=obj.ageToDays();
    cout<<"\nThe age in days is "<<days;
}

