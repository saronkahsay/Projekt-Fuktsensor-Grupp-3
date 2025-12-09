

# Projekt: Fuktsensor
Vi är en grupp studenter på MDU som utvecklar en fuktsensor för hemmabruk. Projektet sker som gruppuppgift i kursen ITE130.

## Syfte
Syftet med projketet är att utveckla ett vertyg som gör det lättare att ta hand om växter. Genom att mäta fuktighetsnivån i jorden och omvandla det till tydliga procentvärden får användaren snabbt en uppfattning om växtens behov av vatten. Datan ska sedan visualiseras grafiskt för användaren. Kombinationen av sensor, microcontroller och grafik presentation gör systemet både lärorikt och praktiskt. 
<img width="579" height="399" alt="image" src="https://github.com/user-attachments/assets/97640f8c-04c0-489a-99fd-a6a387164928" />



## Användare och kontext
Den primära målgruppen är privatpersoner som vill ha bättre koll över sina växter. Fuktsensorn underlättar och gör det möjligt att undvika både övervattning och undervattning genom att ge konkret information istället för gissningar. 

## Beskrivning av system
Vi kommer att använda en fuktighetssensor som man sätter i blomjorden i sin kruka. Sensorn skickar data till microcontrollern **ESP8266**, som vi har programmerat till att översätta datan som kommer in till procent. Via WiFi så skickar sedan microcontrollern de procentuella värdena till en hemsida, där vi kommer att visualisera dem i ett diagram. 

## Sensor
Sensorn vi använder är en **Capacitive Soil Moisture Sensor v1.2**. 

<img width="1476" height="942" alt="Screenshot 2025-12-04 at 17 51 23" src="https://github.com/user-attachments/assets/a3919fab-474d-4209-ae1a-6e616f2e1772" />

Sensorn fungerar genom en analog spänning som är proportionell till jordens vattenhalt, vilket innebär att spänningen förändras beroende på hur torr eller fuktig jorden är. Sensorn kopplas till microcontrollern med hjälp av tre kopplingssladdar. 

1. Sensorns VCC-pinne kopplas till 3.3V-pinnen på microcontrollern (den röda sladden).
2. Sensorns GND-pinne kopplas till en GND-pinne på microcontrollern (den svarta sladden).
3. AO-pinnen kopplas till AEUOT (A0) på microcontrollern för att få ett analogt värde som kan konverteras till fuktighetsnivå (den gula sladden).
<img width="3072" height="4096" alt="image" src="https://github.com/user-attachments/assets/ffdff362-0a41-4601-8d27-eb251ed55253" /> 

<img width="3024" height="4032" alt="image" src="https://github.com/user-attachments/assets/ac4e7bb9-3b63-4384-a1e1-edc68d19af7b" /> 


Sedan programmerade vi vår microcontroller med sensorn i **Arduino IDE** med följande kod: 

```c++
void setup()
{ 
  Serial.begin(9600);
}

void loop()
{
  Serial.println(analogRead(A0));
  delay(100);
}

const int dry = 595; // value for dry sensor
const int wet = 239; // value for wet sensor

void setup()
{ 
  Serial.begin(9600);
}

void loop()
{
  int sensorVal = analogRead(A0);

  // Sensor has a range of 239 to 595
  // We want to translate this to a scale or 0% to 100%
  int percentageHumididy = map(sensorVal, wet, dry, 100, 0); 

  Serial.print(percentageHumididy);
  Serial.println("%");
  
  delay(100);
}
```
I koden kan vi se att ett högre sensorvärde betyder att det är torrt, och det lägre värdet är för en högre fuktighet. Dessa värden översätts sedan till procent. 
```cpp
const int dry = 595; // value for dry sensor
const int wet = 239; // value for wet sensor
```
Här berättar vi för programmet vilka världen som betyder torr jord och blöt jord. 
I koden kan vi se att ett högre sensorvärde betyder att det är torrt, och det lägre värdet är för en högre fuktighet. Dessa värden översätts sedan till procent. 
```cpp
void setup()
{ 
  Serial.begin(9600);
}
```
```cpp
setup ()
```
Körs en gång när programmet startar 
```cpp
 Serial.begin(9600);
```
Gär så att vi kan se värden från sensorn på datorn
```cpp
analogRead(A0);
```
Läser värden från sensorn
```cpp
 int percentageHumididy = map(sensorVal, wet, dry, 100, 0);
```
Gör om sensorvärdet till procent 0% till 100%
  - 100% = blöt jord
  - 0% = torr jord
```cpp
Serial.print(percentageHumididy);
  Serial.println("%");
```
Skriver ut resultaten i serial monitor 
```cpp
delay(100);
```
Pausar i 0.1 sekund mellan varje gång sensorn läser av
## Visualisering
Vi har tänkt visualisera datan från vår sensor med hjälp av ett linjediagram, som kommer att visa fuktighetsnivån i procent (där 100% är maximal fuktighet och 0% är helt torrt). Den andra axeln visar tid, så att man kan se hur fuktighetsnivåerna i jorden förändras över tid, mellan vattningar. 

<img width="874" height="504" alt="Screenshot 2025-12-04 at 17 54 50" src="https://github.com/user-attachments/assets/6ba67433-e68f-4dd1-9643-779cc82abdc0" />


## Förväntat resultat och nytta
Syftet med vår tjänst är att användaren ska kunna få ökad kunskap och förståelse för sina krukväxter, för hur ofta eller sällan de behöver vattnas och vad som är optimal fuktighetsnivå för just din växt. För en person som vill skaffa nya krukväxter, men är osäker på hur mycket vatten de behöver och hur ofta de ska vattnas, så kan man få en tydlig visualisering av data och en bättre förståelse för vad ens växt behöver.

<img width="1319" height="1181" alt="Screenshot 2025-12-04 at 18 05 04" src="https://github.com/user-attachments/assets/7d39e5b4-846e-497e-9670-6fa06caf6a90" />

## Tidsplan 

Torsdag 4/12 - Vi började med att undersöka olika sätt att visualisera data som passar för vårt projekt från Chart.js. 

Månadg 8/12 - Skapar första verisonen av visualiseringen i HTML sida.

Tisdag 9/12 - Testar diagrammet med datan från sensorn via NodeMCU.

Fredag 12/12 - Inför presentationen, ska vi ha sammanställt koden, sensors koppling, testvärderna och ha ett diagram.Fördela arbetet jämt och förbereda för presentationen.

Tisdag 16/12 - Sammanställ projketet.

## Loggbok
Idag den 2/12 har vi monterat ihop fuktsensorn och fick den att funka i Arduino. Sen skrev vi koden och matade in värdena i "Dry" och "Wet". Vi genomförde både torra och våta tester för att kalibera sensorn, värdet för dry hämtades från helt torr jord, medans wet definerades av sensorns utslag i blöt jord. Dessa kaliberingspunkter kommer senare att användas för att beräkna procentuell fuktighet.


<img width="675" height="351" alt="Skärmavbild 2025-12-09 kl  15 51 36" src="https://github.com/user-attachments/assets/70227f5e-ebcd-43c7-b8f7-6feb08a0266b" />

<img width="725" height="724" alt="Skärmavbild 2025-12-09 kl  15 46 52" src="https://github.com/user-attachments/assets/a57dea2a-7bc7-4303-8d4b-880d46bb2697" />



