#include "threadpool/threadpool.hpp"
#include "httprequest/httprequest.hpp"
#include <iostream>
#include <vector>
#include <chrono>


void visit(){
    try
    {
        // you can pass http::InternetProtocol::V6 to Request to make an IPv6 request
        http::Request request{"http://ehall.njit.edu.cn/new/index.html"};

        // send a get request
        const auto response = request.send("GET");
        std::cout << std::string{response.body.begin(), response.body.end()} << '\n'; // print the result
    }
    catch (const std::exception& e)
    {
        std::cerr << "Request failed, error: " << e.what() << '\n';
    }
}

int main(){
    visit();

    return 0;
}