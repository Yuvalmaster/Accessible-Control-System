//-----------------------------------------  ######### -----------------------------------------// 
//-----------------------------------------    SETUP   -----------------------------------------// 
//-----------------------------------------  ######### -----------------------------------------// 
int LDR_pins[] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9}; // Sensors pinout
int LED_pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};         // LED pinout

int Song_No = 1;  // Initialze a song number indicatior
int thresh = 800; // Determine the treshold of the LEDs

/////// ------------------- MP3 System Pinout --------------------- ///////
int RESET = 32;   // Rest to first song
int NEXT = 34;    // Next button
int PREV = 36;    // Previous button
int PLAY = 38;    // Play/Stop button
int BUSY = 40;    // If song is playing


/////// -------------------- Initialize setup -------------------- ///////
void setup() 
{
  Serial.begin(12800);
  
  LEDSetup();
  // Set MP3 module pins
  MP3ModulepinSetup();
  //resetModule();
}

void loop() 
{
  readLDRValues();

  for (int i = 0; i < 10; i++) {
    if (LDR_values[i] > thresh) 
    
    {
      digitalWrite(LED_pins[i], HIGH); // Turns LED i ON
      findVoice(LED_pins[i], i + 1);   // Choose the correct voice (Selected Program)
    } 
    
    else 
    {
      digitalWrite(LED_pins[i], LOW); // Turns LED i OFF
    }
  }
}

//-----------------------------------------  ######### -----------------------------------------// 
//-----------------------------------------  FUNCTIONS -----------------------------------------// 
//-----------------------------------------  ######### -----------------------------------------// 

//////// Setup LEDs  ////////
void LEDSetup() 
{
  for (int i = 0; i < 10; i++) 
  {
    pinMode(LED_pins[i], OUTPUT);
  }
}

//////// Setup the MP3 Module ////////
void MP3ModulepinSetup() 
{
  pinMode(NEXT, OUTPUT);
  pinMode(PREV, OUTPUT);
  pinMode(PLAY, OUTPUT);
  pinMode(BUSY, INPUT_PULLUP);
}

////////  Reset the MP3 Module ////////
void resetModule()
{
  digitalWrite(RESET, LOW);
  delay(100);              // Keep pin high 100ms
  digitalWrite(RESET, HIGH);
  delay(500);              // Wait 500ms for the system to initialize
}

////////  Play/Stop ////////
void togglePlay () 
{
  digitalWrite(PLAY,LOW);
  delay(10);              // Keep pin high 10ms
  digitalWrite(PLAY,HIGH);
}

////////  Next ////////
void toggleNext ()
{
  digitalWrite(NEXT,LOW);
  delay(10);              // Keep pin high 10ms
  digitalWrite(NEXT,HIGH);
  Song_No = Song_No++;
  
}

////////  PREVIOUS ////////
void togglePrev ()
{
  digitalWrite(PREV,LOW);
  delay(10);              // Keep pin high 10ms
  digitalWrite(PREV,HIGH);
  Song_No = Song_No--; 
  

////////  Find The relevant voice (Program name) ////////
void findVoice(int Led_target, int Song_target) 
{
  /* The MP3 module has limited functionality as it can only skip forward and backward through tunes, lacking the ability to select a specific track directly. 
Consequently, each time the module is turned off or the resetModule() function is activated, it reverts to the first track. To address this limitation and 
maintain track order, I've implemented a solution using a pointer called 'Song_No.' This pointer indicates the last track played. When a specific track is 
requested, the function checks if the requested track matches the 'Song_No.'. If not, it iterates through the tracks until it reaches the correct one. 
Subsequently, the 'Song_No' pointer is updated and will be modified each time a different LED is turned on. This modification ensures that the MP3 module can 
effectively keep track of the last played track and allow for better control and navigation between tracks. */


  if (Song_No < Song_target) 
  {
    toggleNext();
  } 
  
  else if (Song_No > Song_target) {
    togglePrev();
  }
}

////////  Read the LDR values ////////
void readLDRValues() 
{
   /* This section read the analog inputs corresponding to the 
  relevant LDR sensor. if the value is greater than set threshold, 
  the device will detect and will alarm */

  for (int i = 0; i < 10; i++) 
  {
    LDR_values[i] = analogRead(LDR_pins[i]); // Reads the Value of LDR(light
    Serial.print("LDR");
    Serial.print(i + 1);
    Serial.print(" value is: ");
    Serial.println(LDR_values[i]);          // Prints the value of LDR to Serial Monitor.
  }
}
