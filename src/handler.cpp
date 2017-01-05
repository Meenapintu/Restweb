#include "../include/handler.h"

handler::handler()
{
    //ctor
}
handler::handler(utility::string_t url):m_listener(url)
{
    m_listener.support(methods::GET, std::bind(&handler::handle_get, this, std::placeholders::_1));
    m_listener.support(methods::PUT, std::bind(&handler::handle_put, this, std::placeholders::_1));
    m_listener.support(methods::POST, std::bind(&handler::handle_post, this, std::placeholders::_1));
    m_listener.support(methods::DEL, std::bind(&handler::handle_delete, this, std::placeholders::_1));

}
handler::~handler()
{
    //dtor
}

void handler::handle_error(pplx::task<void>& t)
{
    try
    {
        t.get();
    }
    catch(...)
    {
        // Ignore the error, Log it if a logger is available
    }
}


//
// A GET of the dealer resource produces a list of existing tables.
//
void handler::handle_get(http_request message)
{
    ucout <<  message.to_string() << endl;

    auto paths = http::uri::split_path(http::uri::decode(message.relative_uri().path()));

    message.relative_uri().path();

      concurrency::streams::fstream::open_istream(U("static/index.html"), std::ios::in).then([=](concurrency::streams::istream is)
    {
        message.reply(status_codes::OK, is,  U("text/html"));
    });

    return;

};

//
// A POST of the dealer resource creates a new table and returns a resource for
// that table.
//
void handler::handle_post(http_request message)
{
    ucout <<  message.to_string() << endl;


     message.reply(status_codes::OK,message.to_string());
    return ;
};

//
// A DELETE of the player resource leaves the table.
//
void handler::handle_delete(http_request message)
{
     ucout <<  message.to_string() << endl;

        string rep = U("WRITE YOUR OWN DELETE OPERATION");
      message.reply(status_codes::OK,rep);
    return;
};


//
// A PUT to a table resource makes a card request (hit / stay).
//
void handler::handle_put(http_request message)
{
    ucout <<  message.to_string() << endl;
     string rep = U("WRITE YOUR OWN PUT OPERATION");
     message.reply(status_codes::OK,rep);
    return;
};
