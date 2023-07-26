#include<bits/stdc++.h>
using namespace std;

// If left unresolved, anything in C++ is implicitly declared as private. 

class AbstractEmployee
{
	virtual void askForPromotion()=0;
};

public class Employee:public AbstractEmployee
{
private:
	string Name;
	string Company;
	int Age;
	
public:
	// Invoking constructor object
	Employee(string name, string company, int age)
	{
		Name=name;
		Company=company;
		Age=age;
	}
	
	void askForPromotion()
	{
		if(Age>=30)
			cout<<"You are eligible for promotion"<<endl;
		else
			cout<<"You are not eligible for promotion"<<endl;
	}
	
	// Accessing private members through setter-getter methods. An example of encapsulation. Primarily useful for overwriting the existing values. 
	void setName(string name)
	{
		Name=name;
	}
	
	string getName()
	{
		return Name;
	}
	
	void setCompany(string company)
	{
		Company=company;
	}
	
	string getCompany()
	{
		return Company;
	}
	
	void setAge(int age)
	{
		if(age>=18)
			Age=age;
	}
	
	int getAge()
	{
		return Age;
	}
	
	
	void introduceYourself()
	{
		cout<<"Name:"<<Name<<endl;
		cout<<"Comany:"<<Company<<endl;
		cout<<"Age:"<<Age<<endl;
	}

};

class Developer:Employee
{
	public:
		string FavProgrammingLanguage;
		Developer(string name, string company, int age, string favProgrammingLanguage)
			:Employee(name, company, age)
			{
				FavProgrammingLanguage=favProgrammingLanguage;
			}
			
		void fixBugs()
		{
			cout<<getName()<<" loves programming in "<<FavProgrammingLanguage<<endl;
		}
};

int main()
{	
	Employee e1=Employee("Sagar", "ABC", 22);	
	Employee e2=Employee("Akshat", "DEF", 35);
	
	e1.introduceYourself();
	cout<<endl;
	e2.introduceYourself();
		
	cout<<endl;
	
	e1.askForPromotion();
	e2.askForPromotion();
	
	cout<<endl;
	
	Developer d=Developer("Sagar", "ABC", 25, "C++");
	d.fixBugs();
	return 0;
}


// Usage of protected modifier
// You can even make the inheritance public, if you wish to use the child's class methods in the main method
// The most common use of polymorphism is when a parent class reference is used to refer to a child object
// For eg., Employee* e1 =&d and Employee* e2=&t, etc.
// Set the parent version of Work to virtual. So base class's work function will be executed
