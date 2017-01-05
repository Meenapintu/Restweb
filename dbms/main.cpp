
#include "include/Dbms.h"
#include <string>
int main(int argc, char* argv[])
{
   Dbms* d = new Dbms();
   d->connect();
   cout<<"HTDT  1"<<endl;
   //string ha = "okay";
   d->create("okay");
   d->disconnect();
   cout<<"disconnected"<<endl;
    d->create("okay");

       d->connect();
   cout<<"HTDT  1"<<endl;
   //string ha = "okay";
   d->create("okay");
}
