#include <httpserver.hpp>
#include <thread>
#include <vector>
 
int main() {
    // 创建HTTP服务器对象
    httpserver::http_server server;
 
    // 设置请求回调函数
    server.set_callback([](const httpserver::http_request& req, httpserver::http_response& res) {
        // 简单的响应
        res.set_status_and_content(200, "Hello, World!");
    });
 
    // 启动服务器
    server.start("0.0.0.0", 8080); // 监听在所有网络接口的8080端口
 
    // 创建线程池
    std::vector<std::thread> threads;
    for (int i = 0; i < std::thread::hardware_concurrency(); ++i) {
        threads.emplace_back([&server]() {
            server.run(true); // 以守护线程方式运行
        });
    }
 
    // 等待用户输入来停止服务器
    std::cin.get();
 
    // 停止服务器
    server.stop();
 
    // 等待所有线程完成
    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
 
    return 0;
}