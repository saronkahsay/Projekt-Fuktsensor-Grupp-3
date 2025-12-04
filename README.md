# Grupplogg & Tidsplan 

Tisdag 2/12 - Plan för sensor och microcontroller samt montage klart. Bibliotek för sensor hittat och tester med sensor inledd. 

Torsdag 4/12 - Färdigställt vilken visualisering som passar för vårt projekt från Chart.js. 

Månadg 8/12 - Skapar första verisonen av visualiseringen i HTML sida.

Tisdag 9/12 - Testar diagrammet med datan från sensorn via NodeMCU.

Fredag 12/12 - Inför presentationen, ska vi ha sammanställt koden, sensors koppling, testvärderna och ha ett diagram.Fördela arbetet jämt och förbereda för presentationen.

Tisdag 16/12 - Sammanställ projketet.


## Loggbok
Tisdagen den 2/12 har vi monterat ihop fuktsensorn och fick den att funka i Arduino. Sen skrev vi koden och matade in värdena i "Dry" och "Wet"

## Projekt: Fuktsensor
Vi är en grupp studenter på MDU som utvecklar en fuktsensor för hemmabruk. Projektet sker som gruppuppgift i kursen ITE130.

## Syfte
Vår intention är att skapa en fuktsensor för användning i jorden som läser av hur våt eller torr den är. Datan ska sedan visualiseras grafiskt för användaren.

## Användare och kontext
Målgruppen är dem som äger växter och vill veta när de behöver vattnas. Sensorn underlättar ansvaret för användaren genom att hålla koll på fukten i jorden genom att känna av hur våt eller torr den är.

## Beskrivning av system
Vi kommer att använda en fuktighetssensor som man sätter i blomjorden i sin kruka. Sensorn skickar data till microcontrollern **ESP8266**, som vi har programmerat till att översätta datan som kommer in till procent. Via WiFi så skickar sedan microcontrollern de procentuella värdena till en hemsida, där vi kommer att visualisera dem i ett diagram. 

## Sensor
Sensorn vi använder är en **Capacitive Soil Moisture Sensor v1.2**. 

<img width="1476" height="942" alt="Screenshot 2025-12-04 at 17 51 23" src="https://github.com/user-attachments/assets/a3919fab-474d-4209-ae1a-6e616f2e1772" />

Sensorn fungerar genom en analog spänning som är proportionell till jordens vattenhalt, vilket innebär att spänningen förändras beroende på hur torr eller fuktig jorden är. Sensorn kopplas till microcontrollern med hjälp av tre kopplingssladdar. 

1. Sensorns VCC-pinne kopplas till 3.3V-pinnen på microcontrollern (den röda sladden).
2. Sensorns GND-pinne kopplas till en GND-pinne på microcontrollern (den svarta sladden).
3. AO-pinnen kopplas till AEUOT (A0) på microcontrollern för att få ett analogt värde som kan konverteras till fuktighetsnivå (den gula sladden).

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

## Visualisering
Vi har tänkt visualisera datan från vår sensor med hjälp av ett linjediagram, som kommer att visa fuktighetsnivån i procent (där 100% är maximal fuktighet och 0% är helt torrt). Den andra axeln visar tid, så att man kan se hur fuktighetsnivåerna i jorden förändras över tid, mellan vattningar. 

<img width="874" height="504" alt="Screenshot 2025-12-04 at 17 54 50" src="https://github.com/user-attachments/assets/6ba67433-e68f-4dd1-9643-779cc82abdc0" />


## Förväntat resultat och nytta
Syftet med vår tjänst är att användaren ska kunna få ökad kunskap och förståelse för sina krukväxter, för hur ofta eller sällan de behöver vattnas och vad som är optimal fuktighetsnivå för just din växt. För en person som vill skaffa nya krukväxter, men är osäker på hur mycket vatten de behöver och hur ofta de ska vattnas, så kan man få en tydlig visualisering av data och en bättre förståelse för vad ens växt behöver.

<img width="1319" height="1181" alt="Screenshot 2025-12-04 at 18 05 04" src="https://github.com/user-attachments/assets/7d39e5b4-846e-497e-9670-6fa06caf6a90" />

