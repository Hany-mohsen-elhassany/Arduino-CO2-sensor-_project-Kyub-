### setting up your Adriano (step by step)  


\- use the arduino IDE available at https://www.arduino.cc/en/software
\- get the arduino IDE to work with the esp8266 board using [this guide](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/)



<img width=500 src="https://kyub.com/api/v1/file/download/7dZ11kAFnn38qtK/original/eee.JPG"><br>






### testing the [chip (esp8266)](https://www.amazon.de/AZDelivery-ESP8266-ESP-8266EX-development-including/dp/B08BTXCZC1/ref=sr_1_1_sspa?dchild=1&keywords=wemos+d1+mini+pro+mikrocontroller+basierend+auf+esp2866&qid=1609762206&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzVTkxM1RPSkVJQjBKJmVuY3J5cHRlZElkPUEwMTcwNjczMk5ZTkgyOE5ETUNaMCZlbmNyeXB0ZWRBZElkPUEwNjc3MTAyMURHREJPU1Q2N0xUOSZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=)<br>


- before trying to run any actual script it is recommended to upload a simple internal led blinking script - just to check that both your board and your software setup are working: ( here is the code)


void setup() {
pinMode(LED_BUILTIN, OUTPUT); // Initialize the LED_BUILTIN pin as an output


}

void loop() {<br>
digitalWrite(LED_BUILTIN, LOW); // Turn the LED on by making the voltage LOW<br>
delay(1000); // Wait for a second<br>
digitalWrite(LED_BUILTIN, HIGH); // Turn the LED off by making the voltage HIGH<br>
delay(2000); // Wait for two seconds<br>

}



<img width=500 src="https://kyub.com/api/v1/file/download/BO8XtT5JRd6ALBE/original/Capture1.JPG"><br>




### package installation


\- use this guide https://learn.sparkfun.com/tutorials/installing-an-arduino-library that will explain all steps in detail

\- when using a library, always check the included examples first, before trying to write up something by yourself, because it might be unintuitive how to use it. you can access them directly from your arduino IDE




### Check the [LED light](https://shop.watterott.com/WS2812-RGB-Ring-24-weiss)



- attach the 5v led with the 3v3 port and " GND" of the LED to the " GND " of the board <br>


<img width= 800 src="https://kyub.com/api/v1/file/download/6nbaiNsYcsK306A/original/part%202.jpg"><br>



- install ** Adafruit_NeoPixel ** library

run the simple test



<img width=500 src="https://kyub.com/api/v1/file/download/on4O6dRBl0mVTdM/original/LED%20CHECKING.png">




<source src="https://kyub.com/api/v1/file/download/MtQMWYjNXn7zWkq/original/MOV_0537.mp4" type="video/mp4"></source></video>




**note :**sometimes the port name can be different from the one printed on the board for example if you connect it to "D5" port you may need to write "14" in the code ( here is the images that shows different ports naming)



<img width= 800 src="https://kyub.com/api/v1/file/download/BtbHlgu60qGCZgn/original/000.JPG">






### Check the [CO2 sensor](https://shop.watterott.com/Sensirion-SCD30-CO2-carbon-dioxide-sensor)

- wire up the cables as shown<br> 


<img width= 800 src="https://kyub.com/api/v1/file/download/NspDPT20hYce3td/original/part%201.jpg"><br> 

\- install ** SparkFun_SCD30_Arduino_Library ** ( if you dont have SCD30 sensor , please install its corresponding library) <br> 
\- run the simple test

<img width=500 src="https://kyub.com/api/v1/file/download/JKFQY7B9e7qyuSv/original/co2.jpg">



\- open the serial monitor from **tools menu ** and make sure speed settings are the same






<img width=500 src="https://kyub.com/api/v1/file/download/thHDki9ylxtmY4G/original/iii.JPG"><br>




- now it is working! and you can start coding your mirocontroller <br>

