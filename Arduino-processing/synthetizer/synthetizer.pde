import processing.serial.*; //import the Serial library
import ddf.minim.*;
import ddf.minim.ugens.*;

//comunicacion serie
int end = 10;   
String serial;  
Serial port;  

//audio
Minim       minim;
AudioOutput out;
Oscil       wave;

//variables obtenidas de arduino
float frecuencia = 0.0;
float amplitud = 0.0; 

void setup() {
  size(512, 200, P3D);

  printArray(Serial.list());

  //conectamos el puerto serie
  port = new Serial(this, Serial.list()[32], 9600); 
  port.clear(); 
  serial = port.readStringUntil(end);  
  serial = null; // 

  //configuramos el audio 
  minim = new Minim(this);
  out = minim.getLineOut();
  wave = new Oscil( 440, 0.5f, Waves.SINE );
  wave.patch( out );
}


void draw() {
  background(0);

  while (port.available () > 0) {  
    serial = port.readStringUntil(end);
  }
  
  //si nos llegan datos los procesamos
  if (serial != null) {  
    String[] a = split(serial, ',');   
    println(a.length);
    //+++++++++++++++++++++++  Data usage:
    

    amplitud = map( parseFloat(a[0]), 0, 1023, 1, 0 );
    wave.setAmplitude( amplitud );

    frecuencia = map( parseFloat(a[1]), 0, 1023, 110, 880 );
    wave.setFrequency( frecuencia );
  }
  
  
  fill(frecuencia);
  ellipse(width / 2, height / 2, frecuencia, frecuencia);

}


void keyPressed()
{ 
  switch( key )
  {
  case '1': 
    wave.setWaveform( Waves.SINE );
    break;

  case '2':
    wave.setWaveform( Waves.TRIANGLE );
    break;

  case '3':
    wave.setWaveform( Waves.SAW );
    break;

  case '4':
    wave.setWaveform( Waves.SQUARE );
    break;

  case '5':
    wave.setWaveform( Waves.QUARTERPULSE );
    break;

  default: 
    break;
  }
}

