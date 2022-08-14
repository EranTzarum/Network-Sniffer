
## my_ping.c:

We have created an object with the help of which we will want to send the ping to the IP address: 8.8.8.8 and open the socket.
If the socket returns minus 1, then the socket in question has not been established.
The time calculation for RTT measurement is carried out from the moment the message was sent until the moment we received an ack.
With the help of recvform we are waiting for a response from the destination.
Receiving the message reads when we received an amount greater than 0. And then we will close the RTT.

Terminal run:

![ping](https://user-images.githubusercontent.com/106338500/184533784-c28b020f-8436-459c-bb04-00ac55a34e7c.png)


wireshark:

![ping_W](https://user-images.githubusercontent.com/106338500/184533792-c769bf83-587f-463f-9f37-3075178abd51.png)


## sniffer.c:

Packet sniffers are programs that intercept the network traffic flowing in and out of a system through network interfaces.

So if you are browsing the internet then traffic is flowing and a packet sniffer would be able to catch it in the form of packets and display them for whatever reasons required.


Terminal run:

![sniff](https://user-images.githubusercontent.com/106338500/184533804-25ecf58a-fa77-409d-8bee-04d6864fb760.png)

