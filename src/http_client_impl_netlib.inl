//  Copyright (c) 2014 Andrey Upadyshev <oliora@gmail.com>
//
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "ppconsul/http_status.h"
#include <boost/network/protocol/http/client.hpp>


namespace ppconsul { namespace impl {

    class HttpClient
    {
    public:
        std::string get(http::Status& status, const std::string& url)
        {
            boost::network::http::client::request request(url);
            auto response = m_client.get(request);
            status = http::Status(response.status(), response.status_message());
            return response.body();
        }

        std::string put(http::Status& status, const std::string& url, const std::string& body)
        {
            boost::network::http::client::request request(url);
            auto response = m_client.put(request, body);
            status = http::Status(response.status(), response.status_message());
            return response.body();
        }

        std::string del(http::Status& status, const std::string& url)
        {
            boost::network::http::client::request request(url);
            auto response = m_client.delete_(request);
            status = http::Status(response.status(), response.status_message());
            return response.body();
        }

    private:
        boost::network::http::client m_client;
    };

}}