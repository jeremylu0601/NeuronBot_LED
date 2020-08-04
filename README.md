# NeuronBot_LED (Arduino Nano for example)

### Arduino IDE Setup and Sketch Upload (This step can be done on a laptop)

Click **Manage Libraries**  
<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/arduino_manage_library.png" width="800" height="400">


Install **Adafruit NeoPixel** for the Arduino Board.

<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/download_adafruit.png" width="600" height="200">


Set the **Board**, **Processor** and **Port** correctly.

<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/boardset.png" width="400" height="400"> 
<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/processorset.png" width="400" height="400"> 
<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/portset.png" width="400" height="400">

Open **Arduino_Nano.ino** in Arduino IDE and click **Verify** and **Upload** buttons to write the sketch into UNO.

<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/verify.png" width="300" height="200"> <img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/upload.png" width="300" height="200">

### Hardware Setup (connect the Arduino board and NeuronBot)

Put the USB cable into the USB hub on NeuronBot.

Please find out to which port the Arduino board is connected, e.g., **/dev/ttyUSB0**.  


### Check the function

1. Install the dependence
    ```
    pip install pyserial
    ```
2. Execute the script
    ```
    python LED_Fun.py
    ```
    <img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/terminal_nano.png" width="300" height="200">
    <img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/demo_nano.gif" width="300" height="200">

### LED Define

The number of LED unit starts from 0 which is the unit closest to the wire.

<img src="https://github.com/jeremylu0601/NeuronBot_LED/blob/master/images/nano_led.png">

### Build your own function
2. In terminal 2
    ```
    rosrun rosserial_arduino serial_node.py _port:=/dev/ttyACM0 _baud:=57600
    # _port : please check where the Arduino board is 
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







