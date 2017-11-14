# Marvin + KPN LoRa
Using the marvin board to send data through the kpn lora network to a node.js server.

## prerequirements
For you to send data from the KPN developer portal to your `node.js` server you will need the 2 following things.

1. The ability to run node online
2. HTTPS
3. Have a Marvin board (duh)

If you have both of these you're good to go.

If you don't have a live `node.js` server you can still do all the steps untill the part for `node.js`. Alternatively you can use [Hookbin] to see te receiving data. (Past the Hookbin link as your destination.)

### Your Marvin board

#### Uploading files

To upload to the Marvin board you will need to set the board option in the [Arduino IDE] to `Arduino Leonardo` like so.

![alt text][Setting the board to Leonardo]
Image from the [Marvin repo]

And then you can click the Upload button.

![alt text][Upload a sketch]
Image from the [Marvin repo]

#### The button
In the example the button is connected to the D4 pin. In your code this will be shown as de 4 pin. Make sure the button is wired up like the image.

![alt text][Marvin + button]

### KPN LoRa

If you don't have one already, make an account on the [KPN LoRa developer portal]. This will give you free access for 10 weeks to use 10 different devices.

Once logged in you van add a Device with the Add Device button.

![alt text][Add device]

This will show a prompt for you to fill in. 
**NOTE**: You can always change the options at a later point.

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

The data you will see here is going to be something different then what you would have send but don't panic this is normal. The `int` `1000` we send has been converted to hexadecimal for the transfer. We will reverse this on the server side.

**NOTE**: you can only send data to your server (uplink) 6 times per hour and 2 messages from your server to the Marvin board (downlink) per hour.

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

Have the node.js application run live on your server to send and receive data. The application has two paths. The first is the `/` where an array will be filled with the messages you send to it. The second one is `/entries`. This will be where you will send the data to.

So in the KPN LoRa developer portal you can set the `Destination URL` to your site.

[localhost:8000]: http://localhost:8000
[Arduino IDE]: https://www.arduino.cc/en/main/software
[Marvin repo]: https://github.com/iotacademy/marvin/tree/master/Software
[KPN LoRa developer portal]: https://loradeveloper.mendixcloud.com/index.html
[Hookbin]: https://hookbin.com/

[Setting the board to Leonardo]: https://github.com/servinlp/marvin-KPN-LoRa/raw/master/images/uploading.jpg "Setting the board to Leonardo"
[Upload a sketch]: https://github.com/servinlp/marvin-KPN-LoRa/raw/master/images/upload.jpg "Upload a sketch"

[Add device]: https://github.com/servinlp/marvin-KPN-LoRa/raw/master/images/add-device.PNG "Add device"
[Device prompt]: https://github.com/servinlp/marvin-KPN-LoRa/raw/master/images/add-device-prompt.PNG "Device prompt"
[Device overview]: https://github.com/servinlp/marvin-KPN-LoRa/raw/master/images/device-overview.PNG "Device overview"
[Device values]: https://github.com/servinlp/marvin-KPN-LoRa/raw/master/images/device-values.PNG "Device values"
[Debugger]: https://github.com/servinlp/marvin-KPN-LoRa/raw/master/images/debugger.PNG "Debugger"

[Marvin + button]: https://github.com/servinlp/marvin-KPN-LoRa/raw/master/images/marvin-plus-board.jpg "Mavin + button"
