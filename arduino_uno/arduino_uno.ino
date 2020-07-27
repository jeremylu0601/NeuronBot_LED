#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Char.h>
#include <Adafruit_NeoPixel.h>  


#define PIN_ 6  // pin define, signal output

int num=8; // number of led units, the no.0 unit is the one closest to the wires


Adafruit_NeoPixel strip = Adafruit_NeoPixel(num, PIN_, NEO_GRB + NEO_KHZ800);
//declare the variable, strip 


ros::NodeHandle  nh;
std_msgs::String str_msg;
ros::Publisher chatter("color4led", &str_msg); 



void messageCb( const std_msgs::String& toggle_msg){

 String state;
 state=toggle_msg.data;

if (state== "demo")
  {
    breathe(1,0); //orange breath light 
    
    breathe(1,1); //green breath light 
     
    backward(0,5); //blue marquee, from no.7 unit to no.0 unit

    forward(0,5); //blue marquee, from no.0 unit to no.7 unit

    blink_light(0);  //yellow blink

    blink_light(1);   //red blink

    blink_light(2);  //purple blink
    }
 
 
  if (state== "o")
  {
    breathe(1,0); //orange breath light 
    }

  if (state== "g")
  {
    breathe(1,1); //green breath light
    }
  
  if (state== "f")
  {
    forward(0,5); //blue light moves from no.0 unit to no.7 unit
    }
  
  if (state== "b")
  {
    backward(0,5); //blue light moves from no.7 unit to no.0 unit
    }


  if (state== "y")  
  {  
    blink_light(0);  //yellow blink
    }
  
  if (state== "r")
  {  
    blink_light(1);  //red blink
    }
  
  if (state== "p")
  {  
    blink_light(2);  //purple blink
    }


}

ros::Subscriber<std_msgs::String> sub("state", messageCb );




void setup()
{
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
}

void loop()
{
  nh.spinOnce();
  delay(500);
}



void breathe(int pace, int color) {
  // pace : 0,1,2 - higher value means higher frequency
  // color : 0 (orange) and 1 (green)
  int wait;
  int ma=180;
  int radius=90;
  int t;
  int v;
  int slope;
  int slope2;
  int temp;
  float w;
  t=0;
  v=0;

  if(pace==0)
  {
    w=0.03;
    slope=3;
    slope2=-3;
    wait=100;
  }

  if(pace==1)
  {
    w=0.02;
    slope=2;
    slope2=-2;
    wait=200;
  }

  if(pace==2)
  {
    w=0.01;
    slope=1;
    slope2=-1;
    wait=300;
  }



 
  for(;v<ma;)
  {
    v=t*slope;
    for (int i=0; i<num;i++)
    {

      if(color==0)
      {
        int g=v*0.2;
        int r=v;
        if(g==0){r=0;}
        strip.setPixelColor(i,r,g,0 );
      }
  
      if(color==1)
      {
        strip.setPixelColor(i,0,v,0 );
      }
    }

    strip.show();
    t++;
    delay(10);
  }
  
  
  t=0;
  temp=v;
  for(;v>(temp-radius);)
  {
    v=temp-radius*sin(w*t);
    for (int i=0; i<num;i++)
    { 
      if(color==0)
      {
        int g=v*0.2;
        int r=v;
        if(g==0){r=0;}
        strip.setPixelColor(i,r,g,0 );
  
      }
      if(color==1)
      {
        strip.setPixelColor(i,0,v,0 );
      }
    }
    strip.show();
    t++;
    delay(10);
  }

  t=0;
  temp=v;
  for(;v>0;)
  {
    v=temp+slope2*t;
    for (int i=0; i<num;i++)
    { 
      if(color==0)
      {
        int g=v*0.2;
        int r=v;
        if(g==0){r=0;}
        strip.setPixelColor(i,r,g,0 );
      }
      if(color==1)
      {
        strip.setPixelColor(i,0,v,0 );
      }
    }
    strip.show();
    t++;
    delay(10);
  }
  delay(wait);
}


void forward(int pace, int number) {
  // pace : 0,1,2 - higher value means higher frequency
  // number : the number of lighting led units
  int ma=180;
  int wait;
  int gap=ma/number;
  int mid=(number/2)+1;
  
  for(int i=0;i<num;i++)
  {
    strip.setPixelColor(i, 0,0,0 );
  }

  strip.show();
  
  if (pace==0) {wait=50;}
  if (pace==1) {wait=100;}
  if (pace==2) {wait=200;}


  for(int t=(1-mid);t<(num+mid);t++)
  {
    for(int i=0;i<(1+(number/2));i++)
    {
      strip.setPixelColor((t+i), 0,0,(ma-i*gap) );
      strip.setPixelColor((t-i), 0,0,(ma-i*gap ));
    }
    
    strip.setPixelColor(t-(1+(number/2)), 0,0,0);
    strip.show();
    delay(wait);  
  }
}


void blink_light(int color) {
  // color: 0 (yellow), 1 (red), 2 (purple)
  int wait;
  if(color==0)
  {wait=300;}
  else
  {wait=100;}

  int v=180;
  for(int r=0;r<5;r++)
  {
  
    for(int i=0;i<num;i++)
    {

      if(color==0)
      {
        strip.setPixelColor(i,v,v,0 );
      }

      if(color==1)
      {
        strip.setPixelColor(i,v,0,0 );
      }

      if(color==2)
      {
        strip.setPixelColor(i,v,0,v );
      }
    
    }
    
    strip.show();
    delay(wait);
  
    for(int i=0;i<num;i++)
    {
      strip.setPixelColor(i,0,0,0 );
    }
    strip.show();
    delay(wait);
  }
}



void backward(int pace, int number) {
  // pace : 0,1,2 - higher value means higher frequency
  // number : the number of lighting led units
  int ma=180;
  int wait;
  int gap=ma/number;
  int mid=(number/2)+1;
  
  for(int i=0;i<num;i++)
  {
    strip.setPixelColor(i, 0,0,0 );
  }
  strip.show();
  
  if (pace==0) {wait=50;}
  if (pace==1) {wait=100;}
  if (pace==2) {wait=200;}

  for( int t=(num+mid-1);t>(0-mid);t--)
  {
    for(int i=0;i<(1+(number/2));i++)
    {
      strip.setPixelColor((t+i), 0,0,(ma-i*gap) );
      strip.setPixelColor((t-i), 0,0,(ma-i*gap ));
    }
    strip.setPixelColor(t+(1+(number/2)), 0,0,0);
    strip.show();
    delay(wait);
  }
  strip.setPixelColor(0, 0,0,0);
  strip.show();
  delay(wait);
}
