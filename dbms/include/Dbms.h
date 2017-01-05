#ifndef DBMS_H
#define DBMS_H
#include <iostream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

class Dbms
{
    public:
        Dbms();
        virtual ~Dbms();
        bool connect();
        void disconnect();
        void create(char* sql );
        void insert(char* sql);
        void select(char* sql);
        void update(char* sql);
        void delete_handle(char* sql);


    protected:
        void query_normal();
        void query_prepared();

    private:
        connection* C = nullptr;


};

#endif // DBMS_H
