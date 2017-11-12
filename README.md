# Marvin + KPN LoRa
Using the marvin board to send data through the kpn lora network to a node.js server.

## Note
For you to send data from the KPN developer portal to your node.js server you will need the 2 following things.

1. The ability to run node online
2. HTTPS

If you have both of these you're good to go.

### Your Marvin board

#### Uploading files

To upload to the Marvin board you will need to set the board option in the [Arduino IDE] to `Arduino Leonardo` like so.

[Setting the board to Leonardo]
Image from the [Marvin repo]

### KPN LoRa

### Node.js

Start by going into the node-server directory and run the following command

```
npm install
```

Once this is done you can start the server with the following command

```
node app.js
```

This will start the server at [localhost:8000]

[localhost:8000]: http://localhost:8000
[Arduino IDE]: https://www.arduino.cc/en/main/software
[Marvin repo]: https://github.com/iotacademy/marvin/tree/master/Software

[Setting the board to Leonardo]: images/uploading.jpg "Setting the board to Leonardo"
