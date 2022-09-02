#include "threadpool/threadpool.hpp"
#include "httprequest/httprequest.hpp"
#include <iostream>
#include <vector>
#include <chrono>


int main(){

    ThreadPool pool(8);
    std::vector<bool> results;
    for(int i = 0; i < 100000; ++i)
    {
        
        pool.enqueue([i]{
            // you can pass http::InternetProtocol::V6 to Request to make an IPv6 request
            http::Request request{"http://ehall.njit.edu.cn/new/index.html"};

            // send a get request
            request.send("GET");

            const auto response = request.send("GET");
            std::cout << i << " ";
        });

    }

    

    return 0;
}