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

![alt text][Setting the board to Leonardo]
Image from the [Marvin repo]

And then you can click the Upload button.

![alt text][Upload a sketch]
Image from the [Marvin repo]

### KPN LoRa

If you don't have one already, make an account on the [KPN LoRa developer portal]

Once logged in you van add a Device with the Add Device button.
![alt text][Add device]

This will show a prompt for you to fill in. NOTE: You can always change the options at a later point.
![alt text][Device prompt]

Once added it will look something like this.
![alt text][Device overview]

Here you can click on the edit button. This will bring up a prompt which will show you the keys you need to put into your arduino code.
![alt text][Device values]

#### Your own keys

In the `marvin.ino` file you will only need to change these three values.

```c++
...
String set_devaddr = "XXXXXXXX"; // Device address
String set_nwkskey = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"; // NwkSKey
String set_appskey = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"; // AppsKey
...
```

Once this is uploaded you can press the button on the Marvin to send your first message. You can find your message under the Debugger tab. Be sure to set the device to your current board.
![alt text][Debugger]

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
[KPN LoRa developer portal]: https://loradeveloper.mendixcloud.com/index.html

[Setting the board to Leonardo]: https://github.com/servinlp/marvin-KPN-LoRa/raw/master/images/uploading.jpg "Setting the board to Leonardo"
[Upload a sketch]: https://github.com/servinlp/marvin-KPN-LoRa/raw/master/images/uploading.jpg "Upload a sketch"

[Add device]: https://github.com/servinlp/marvin-KPN-LoRa/raw/master/images/add-device.PNG "Add device"
[Device prompt]: https://github.com/servinlp/marvin-KPN-LoRa/raw/master/images/add-device-prompt.PNG "Device prompt"
[Device overview]: https://github.com/servinlp/marvin-KPN-LoRa/raw/master/images/device-overview.PNG "Device overview"
[Device values]: https://github.com/servinlp/marvin-KPN-LoRa/raw/master/images/device-values.PNG "Device values"
[Debugger]: https://github.com/servinlp/marvin-KPN-LoRa/raw/master/images/debugger.PNG "Debugger"
