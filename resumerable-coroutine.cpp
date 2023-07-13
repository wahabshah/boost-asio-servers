// https://www.boost.org/doc/libs/1_82_0/doc/html/boost_asio/overview/composition/coro.html#boost_asio.overview.composition.coro.integrating_with_awaitable

#include <iostream>
#define ASIO_HAS_CO_AWAIT
#define ASIO_HAS_STD_COROUTINE
#include <asio.hpp>
#include <asio/experimental/coro.hpp>

using asio::awaitable;
using asio::buffer;
using asio::detached;
using asio::use_awaitable;
using asio::ip::tcp;
using asio::io_context;

asio::experimental::coro<std::string> reader(tcp::socket& sock)
{
  std::string buf;
  while (sock.is_open())
  {
    std::size_t n = co_await asio::async_read_until(
        sock, asio::dynamic_buffer(buf), '\n',
        asio::deferred);
    co_yield buf.substr(0, n);
    buf.erase(0, n);
  }
}

asio::awaitable<void> consumer(tcp::socket sock)
{
  auto r = reader(sock);
  auto msg1 = co_await r.async_resume(asio::use_awaitable);
  std::cout << "Message 1: " << msg1.value_or("\n");
  auto msg2 = co_await r.async_resume(asio::use_awaitable);
  std::cout << "Message 2: " << msg2.value_or("\n");
}

asio::awaitable<void> listen(tcp::acceptor& acceptor)
{
  for (;;)
  {
    co_spawn(
        acceptor.get_executor(),
        consumer(co_await acceptor.async_accept(asio::use_awaitable)),
        asio::detached);
  }
}

int main()
{
  asio::io_context ctx;
  tcp::acceptor acceptor(ctx, {tcp::v4(), 54321});
  co_spawn(ctx, listen(acceptor), asio::detached);
  ctx.run();
}