#include <boost/asio.hpp>
#include <array>
#include <iostream>

void echo(boost::asio::ip::tcp::socket socket){

    std::cout << "echo function : "  << std::this_thread::get_id() << std::endl;
    char data[128];
    std::size_t bytesReceived = socket.read_some(boost::asio::buffer(data)); // read blocks
    std::cout << "received " << bytesReceived << " " << data << std::endl;
     
    auto bytesSent =   socket.write_some(boost::asio::buffer(data,bytesReceived)); //write blocks
    std::cout << "sent " << bytesSent << " " << data << std::endl;

}

class A {

};

void listen(boost::asio::ip::tcp::acceptor acceptor){
    std::cout << "listen 1: " << std::this_thread::get_id()  << std::endl;
    std::thread (echo, acceptor.accept()).join();  //accept blocks => Then when we connect via nc localhost 1082 => Then we create a thread and run the echo function
    std::cout << "listen 2: " << std::this_thread::get_id()  << std::endl;
}

int main(){
    std::cout<< "Echo Server - Perthread @1082 : " << std::this_thread::get_id() << std::endl;
    boost::asio::io_context io;
    listen( boost::asio::ip::tcp::acceptor( io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 1082) )  );
    std::cout << "Server about to end: " << std::this_thread::get_id()  << std::endl;
}