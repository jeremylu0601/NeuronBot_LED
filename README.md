# NeuronBot_LED

### Hardware Setup (Arduino UNO for example)

![](https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/hardware.png)

The orange wire connects the GND on GPIO and the GND on Arduino UNO.

The yellow wire is the signal wire from the LED strip. 

Connect the UNO and the mother board with USB port


### Arduino IDE Setup and Sketch Upload

Click **Manage Libraries**  <img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/arduino_manage_library.png" width="800" height="400">


Install **Rosserial Arduino Library** and **Adafruit NeoPixel**

<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/download_rosserial.png" width="600" height="200">
<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/download_adafruit.png" width="600" height="200">


Set the **Board** and **Port** correctly

<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/UNO_BoardType.jpg" width="600" height="200">
<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/UNO_Port.jpg" width="600" height="200">


Verify and upload **arduino_uno.ino** to UNO

<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/verify.png" width="300" height="200"> <img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/upload.png" width="300" height="200">


### Check the function

1. In terminal 1
    ```
    roscore
    ```
    
2. In terminal 2
    ```
    rosrun rosserial_arduino serial_node.py _port:=/dev/ttyACM0 _baud:=57600
    ``` 
3. 



