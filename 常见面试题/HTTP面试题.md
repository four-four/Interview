##### HTTP协议简介
超文本传输协议，位于应用层，默认80端口的TCP连接。

##### HTTP 1.0/1.1/2.0的区别
[如何优雅的谈论HTTP1.0/1.1/2.0](https://www.jianshu.com/p/52d86558ca57)
- HTTP1.0规定浏览器与服务器只保存短暂的连接，每次请求都需要建立TCP连接，完成后立即断开。
- HTTP1.1支持持久连接（默认使用持久连接），一个TCP连接上可以传送多个HTTP请求和响应，减少了建立和关闭连接的消耗和延迟。
- HTTP2.0提升了性能

##### HTTP的报文结构
- 请求报文
  - 请求行、请求头部、空行、请求数据
- 响应报文
  - 状态行、消息报头、空行、响应正文

##### HTTP中Get与Post的区别
- Get提交的数据会放在URL之后，所以它的大小会根据浏览器对于URL的长度限制而限制，会有安全问题（明文显示在URL上），使用Query方法获取。
- Post放在HTTP包的body中，没有长度限制，安全一些，用Form方法获取。

##### HTTPs如何实现安全连接
公钥 A.pub B.pub
私钥 A.pri B.pri
A与B交换公钥，A与B通信时，用B的公钥加密，B收到后用自己的私钥解密。
公钥和私钥都是由CA等指定机构生成的。



