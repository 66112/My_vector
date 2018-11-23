#include "myVector.h"
using namespace Cbx;
void Test1()
{
    int myints[]={12,23,34,45};
    Vector<int> v1(myints,myints+(sizeof(myints)/sizeof(myints[0])));
    Vector<int> v2(1,100);
    v2.PushBack(101);
    v2.PushBack(102);
    v2.PushBack(103);
    Vector<int> v3(v2);
    Vector<int> v4(v3.begin(),v3.end());
    Vector<int> v5 = v4;   
    Vector<int>::iterator pos = find(v1.begin(),v2.end(),23);
    pos = v1.Insert(pos,999);
    v1.PopBack();
    
    Vector<int>::iterator it = v1.begin();
    while(it != v1.end())
    {
        cout << *it <<" ";
        it++;
    }
    cout<<endl;
    for(const auto& x : v2)
    {
        cout << x << " ";
    }
    cout << endl;
}
void Test2()
{
    Vector<string> str1V;
    str1V.PushBack("曹博兴");
    str1V.PushBack("朱小裕");
    str1V.PushBack("猴哥");
    str1V.PushBack("八戒");
    Vector<string> str2V(str1V);
    Vector<string>::iterator it = str2V.begin();
    while(it != str2V.end())
    {
        cout << *it << endl;
        it++;
    }
    Vector<string> str3V(str1V.begin(),str1V.end());
    str1V = str3V;
    for(const auto& x : str1V)
    {
        cout << x <<" ";
    }
    cout <<endl;
}
void Test_resize()
{
    Vector<string> v1;
    v1.PushBack("111");
    v1.PushBack("222");
    v1.PushBack("333");
    v1.PushBack("444");
    v1.PushBack("555");
    for(auto x: v1)
    {
        cout << x <<" ";
    }
    cout <<endl;
    v1.Resize(3);
    v1.Resize(8,"123");
    v1.Resize(10);
    Vector<string>::iterator it = v1.begin();
    while(it != v1.end())
    {
        cout << *it <<" ";
        it++;
    }
    cout<<endl;
}
void Test3()
{
    Vector<string> v1;
    v1.PushBack("111");
    v1.PushBack("222");
    v1.PushBack("333");
    v1.PushBack("444");
    v1.PushBack("555");
    for(auto x: v1)
    {
        cout << x <<" ";
    }
    cout <<endl;
    Vector<string>::iterator pos = find(v1.begin(),v1.end(),"333");
    pos = v1.Insert(pos,"9999");
    v1.Erase(pos);
    for(auto x: v1)
    {
        cout << x <<" ";
    }
    cout <<endl;
}
void Test4()
{
    int a[]={1,5,2,3,4};
    Vector<int> v1(a,a+sizeof(a)/sizeof(int));
    Vector<int>:: iterator it =v1.begin();
    while(it != v1.end())
    {
        if(*it % 2 != 0)
            it = v1.Erase(it);
        else
            it++;
    }
    for(auto x : v1)
    {
        cout << x <<" ";
    }

    cout <<endl;
}
int main()
{
    //Test1();
    //Test2();
    //Test_resize();
    //Test3();
    Test4();
    return 0;
}
