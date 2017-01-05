#include "../include/Dbms.h"

Dbms::Dbms()
{
    //ctor
}

Dbms::~Dbms()
{
    //dtor
}

bool Dbms::connect()
{
     try{
      this->C = new connection ("dbname=testdb user=Ndelwte password=ndelwte hostaddr=127.0.0.1 port=5432");
      if (this->C->is_open()) {
         cout << "Opened database successfully: " << C->dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }
      //C.disconnect ();
   }catch (const std::exception &e){
      cerr << e.what() << std::endl;
      return 1;
      }
}
void Dbms::disconnect()
{
    this->C->disconnect();
    delete this->C;
    //this->C=nullptr;
}

void Dbms::create(char* sql )
{
    try{
        if((this->C)->is_open()){
            cout<<"database is open ,now to things "<<endl;
        }
        else{
            cout<<"Can't open database" << endl;
        }
    }catch (const std::exception &e){
      cerr << e.what() << std::endl;

   }
}

void Dbms::insert(char* sql)
{
    try{
        if(this->C->is_open()){
            cout<<"database is open ,now to things "<<endl;
        }
        else{
            cout<<"Can't open database" << endl;
        }
    }catch (const std::exception &e){
      cerr << e.what() << std::endl;

   }
}
void Dbms::select(char* sql)
{
    try{
        if(this->C->is_open()){
            cout<<"database is open ,now to things "<<endl;
        }
        else{
            cout<<"Can't open database" << endl;
        }
    }catch (const std::exception &e){
      cerr << e.what() << std::endl;

   }
}
void Dbms::update(char* sql)
{
    try{
        if(this->C->is_open()){
            cout<<"database is open ,now to things "<<endl;
        }
        else{
            cout<<"Can't open database" << endl;
        }
    }catch (const std::exception &e){
      cerr << e.what() << std::endl;

   }
}
void Dbms::delete_handle(char* sql)
{
    try{
        if(this->C->is_open()){
            cout<<"database is open ,now to things "<<endl;
        }
        else{
            cout<<"Can't open database" << endl;
        }
    }catch (const std::exception &e){
      cerr << e.what() << std::endl;

   }
}

