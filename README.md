# NeuronBot_LED

### Hardware Setup (Arduino UNO for example)

![](https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/hardware.png)

The orange wire connects the GND on GPIO and the GND on Arduino UNO.

The yellow wire is the signal wire from the LED strip. 

Connect the UNO and the mother board with USB port


### Arduino IDE Setup and Sketch Upload

Click **Manage Libraries**  <img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/arduino_manage_library.png" width="800" height="400">


Install **Rosserial Arduino Library** and **Adafruit NeoPixel**.

<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/download_rosserial.png" width="600" height="200">
<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/download_adafruit.png" width="600" height="200">


Set the **Board** and **Port** correctly.

<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/UNO_BoardType.jpg" width="600" height="200">
<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/UNO_Port.jpg" width="600" height="200">


Open **arduino_uno.ino** in Arduino IDE and click **Verify** and **Upload** buttons to write the sketch into UNO.

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
    <img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/terminal_rosserial.png" width="600" height="200">
    
3. In terminal 3
    ```
    rostopic pub /state std_msgs/String "data: 'demo'" 
    # demo : display all modes
    # g : green breath lamp
    # o : orange breath lamp
    # f : blue light moves from No.0 to No.7
    # b : blue light moves from No.7 to No.0
    # y : yellow blink
    # r : red blink
    # p : purple blink
    ``` 
    <img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/demo.gif" width="300" height="300">




### LED Define

The number of LED unit starts from 0 which is the unit closest to the wire.

<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/inside_detail.png"> <img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/outside_detail.png">


The light moves from No.0 to No.7 look like below.


<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/no.0_to_no.7.gif">



