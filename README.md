
# Motivation

![](./images/Async-Web-API.png)

## Build Echo Server Per Thread Iteration1
```sh
rm -rf build && mkdir -p build && \
(cd build && cmake .. && make clean all VERBOSE=1) && \
./build/echo-server-perthread
```

```sh
nc localhost 
```
```sh
hello
```

# Links

* https://gist.github.com/wahabshah/a775cb69e9e1242c43356370b6678eac
* http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2021/p2444r0.pdf
* https://procodeguide.com/programming/async-web-api-with-aspnet-core/
