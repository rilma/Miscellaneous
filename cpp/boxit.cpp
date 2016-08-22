
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated,BoxesDestroyed;

class Box {
    public:
        Box() { l = 0; b = 0; h = 0; BoxesCreated++; }
        Box( int length, int breadth, int height ) { l = length; b = breadth; h = height; BoxesCreated++; }
        Box( Box& B ) { l = B.l; b = B.b; h = B.h; BoxesCreated++; }
        ~Box() { BoxesDestroyed++; }
        int getLength() { return l; }
        int getBreadth() { return b; }
        int getHeight() { return h; }
        long long CalculateVolume() { return ( ( long long ) l * ( long long ) b * ( long long ) h ); }
        friend bool operator<( Box &A, Box &B ) {
            if ( A.l < B.l )
                return true;
            else if ( A.b < B.b && A.l == B.l )
                return true;
            else if ( A.h < B.h && A.b == B.b && A.l == A.l )
                return true;
            else
                return false;
        }
        friend ostream& operator<<( ostream& out, Box B) {
            out << B.l << " " << B.b << " " << B.h;
            return out;
        }
    private:
        int l, b, h;
};


void check2()
{
int n;
cin>>n;
Box temp;
for(int i=0;i<n;i++)
    {
    int type;
    cin>>type;
    if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser"<<endl;
        }
            else
            {
                cout<<"Greater"<<endl;
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}
