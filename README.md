
# Motivation

<a href="https://gitpod.io/#https://github.com/wahabshah/boost-asio-servers" rel="nofollow noopener noreferrer" target="_blank" class="after:hidden"><img src="https://gitpod.io/button/open-in-gitpod.svg" alt="Open in Gitpod"></a>

* This repository contains the two types of echo servers :-
  * Sync using Per thread creation :- [echo-server-perthread.cpp](./echo-server-perthread.cpp)
  * Async using c++20 coroutines (stackless) creation :- [echo-server-coroutine.cpp](./echo-server-coroutine.cpp) 
* These two servers are defined in the paper [p2444r0.pdf](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2021/p2444r0.pdf) on page 16 :-

  ![image](https://user-images.githubusercontent.com/8818025/162878885-f778b8dc-d6c9-425d-b3eb-a9f60796410f.png)
* The overall concept :-

  ![](./images/Async-Web-API.png)




## Build Echo Server Per Thread Iteration1
```sh
rm -rf build && mkdir -p build && \
(cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make clean all VERBOSE=1) && \
./build/echo-server-perthread
```

```sh
nc localhost 1083
```
```sh
hello
```


## Build Echo Server Coroutine Iteration1
```sh
rm -rf build && mkdir -p build && \
(cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make clean all VERBOSE=1) && \
./build/echo-server-coroutine
```

```sh
nc localhost 1084
```
```sh
hello
```
# Links

* http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2021/p2444r0.pdf
* https://procodeguide.com/programming/async-web-api-with-aspnet-core/
* https://gist.github.com/wahabshah/a775cb69e9e1242c43356370b6678eac
