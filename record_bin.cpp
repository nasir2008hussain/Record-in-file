#include<iostream>
#include<fstream>
using namespace std;
struct  Person
{
    char name[20];
    int age;
    void input()
    {
        cout<<"Name : ";
        cin>>name;
        cout<<"Age : ";
        cin>>age;
    }
    void display()
    {
        cout<<name<<"\t"<<age<<endl;
    }
};
int main()
{
    Person p;
    ofstream f;
    f.open("record.bin",ios::binary);
    cout<<sizeof(Person)<<endl;
    for(int i=0;i<3;i++)
    {
        p.input();
        f.write((const char *)&p,sizeof(Person));
    }
    f.close();
    cout<<sizeof(Person)<<endl;
    ifstream ff; // **********duplication solution method********
    ff.open("record.bin",ios::binary);
    while(!ff.eof())
    {
     ff.read((char *)&p,sizeof(Person)); 
     //cout<< ff.gcount()<<endl;
     if(ff.gcount()>0)  //solution for duplicate
           p.display(); 
    }
    ff.close();
   /* ifstream ff;
    ff.open("record.bin",ios::binary|ios::ate);
    int nbytes= ff.tellg();
    int n=nbytes/sizeof(Person);
    Person *p_array=new Person[n];
      
   ff.seekg(0,ios::beg);
   ff.read((char *)p_array,nbytes);
   ff.close();
  
    for(int i=0;i<n;i++)
    {
        p_array[i].display();
    }
    delete[] p_array;*/
    return 0;
}
