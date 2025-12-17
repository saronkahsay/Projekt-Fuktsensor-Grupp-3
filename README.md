# *Vecstis* 
Vi har byggt en fuktsensor som ska mäta jordfuktigheten. 

## Projektbeskrivningens  
varför gjorde vi projektet?:
Många växtägare tycker det är svårt att veta när växten ska vattnas. Vi ville skapa ett verktyg som hjälper att mäta fuktvärdet. vad är kunskapen?

vilka problem löser de?:
enklare att förstå växtens behov

## För att utföra projeket har vi använt: 

**Plusivo Wireless Super Starter Kit**

**Soil Humidity Capacitive Sensor** 

**Visual Studio Code**

**Arduino IDE**

**MQTT-server** 

## Hur systemet funkar 
Vår capacitive soil humidity sensor mäter fuktigheten i jorden på en krukväxt och presenterar värdena i procent på vår webbsida. Nedan beskrivs processen steg för steg. 
1.  **Sensorn mäter fukt** 
Vi placerar fruktsensorn i krukväxtens jord. Sensorn mäter fuktigheten i jorden och sänder ut ett analogt värde som varierar beroende på hur torr eller blöt jorden är. 

2.  **Mikrokontrollern läser värdet**
Sensorn är kopplad till ESP8266.
Mikrokontrollern läser av det analoga sensorvärdet via en analog ingång.
Sensorn är kopplad till mikrokontrollern: ESP8266. Den läser av det analoga sensorvärdet.

3. **Bearbetning av data**
De råa sensorvärdena är svåra att tolka för en användare.
Därför bearbetas värdet i koden och omvandlas till procent (0–100 %), där:
•	0 % = torr jord
•	100 % = blöt jord

4. **Data skickas via WiFi**
ESP8266 är uppkopplad till WiFi.
Fuktvärdet skickas vidare till en server med hjälp av MQTT.

5. **Data visas för användaren**
Datan hämtas från servern och visas på en HTML-sida.
Användaren kan se jordfuktigheten i procent via ett diagram.


## Sensor & Kod 
vilken sensor vi använder, vad den mäter, vad koden gör och vart vi fick koden. Vart kan de hitta våra koder. koden läser sensorvärdet och gör om det till procent. 

## Visualisering 
linjediagram över tid, live humidity %. färger?... 

## Hur utför man detta projekt
med sensor, ESP8266, kod, plusivokit, arduino IDE, vs code, server?

**ESP8266 och Soil Humidity Sensor** 

Sensorn soil humidity sensor mäter jordens fuktighet. Sensorn skickar analogt värde som motsvarar fuktighet till mikrokontrollern. 
ESP8266 är mikrokontrollern som styr sensorn, den skickar data via WiFi. 
Sensorn är kopplat till en ESP8266, den läser av värdet från sensorn och skickar data via WiFi. Det är grunden för hela systemet eftersom det är här mätningen sker. 

**Programmerade microcontrollern i Arduino IDE** 

Arduino IDE används för att programmera mikrokontrollern. Koden bearbeta de analoga sensorvärdena och omvandlar dem till procentuella fuktvärden. Koden hanterar WiFi-kommunikationen vilket möjliggör att mätdata skickas vidare till webbgränssnittet för visualisering. 

**Linjediagram med hjälp av chart.js** 

### Designade prototyp av appen i VS Code
Vi valde att designa en prototyp av en app för det här projektet. Vi har jobbat i **Visual Studio Code** och använt oss av **HTML**, **CSS** och **JavaScript**. Prototypen för appen hittar du i dokumenten: 

- index.html (det här är startsidan/första sidan) 
- dinaväxter.html (sida två) 
- cordyline.html (sida tre) 
- style.css (stylesheet) 

<img width="1920" height="1080" alt="vecstis-mockup-alla-tre" src="https://github.com/user-attachments/assets/020a0c0b-9e68-4e91-bc49-2d6abbaeed26" />

Mockups av hur appen ser ut. Från vänster till höger: index.html, dinaväxter.html, cordyline.html. 

**index.html** innehåller bland annat länkar till stylesheets och JavaScript-bibliotek i head-delen. I body-delen hittar man en bakgrundsbild, en “app-container” (det vill säga en container som vi har lagt allt innehåll i), en h1, h2 och fortsätt-knapp som tar en till nästa sida (dinaväxter.html). 

**dinaväxter.html** innehåller samma länkar i head. I övrigt innehåller body-delen bland annat cards och card groups från Bootstrap, med bilder och text. Den översta bilden, Cordyline, tar en vidare till nästa sida (cordyline.html). 

**cordyline.html** innehåller, utöver text och bild, även JavaScripten för vår fuktighetsmätare och vårt linjediagram. Vi har valt att lägga vår JavaScript i HTML-dokumentet och inte i ett separat dokument. 

**style.css** är vårt stylesheet, som bland annat definierar storleken på app-containern, bakgrundsfärg, typografi, stil och olika tillstånd på fuktighetsmätaren, stil på knappar, cards, card groups och listor. 

### MQTT-server

### Databas

## Vad har vi lärt oss?
-	hur en sensor kan användas för att samla in data 
- hur en mikrokontroll (ESP8266) kan läsa, bearbeta och skicka data vidare via WiFi
 - hur man programmerar en mikrokontroll i Arduino IDE med C++
-	hur rådata kan omvandlas till procent för att bli lättare att förstå
Vi har även lärt oss att:
-	använda Visual Studio Code för att utveckla webbdelen av projektet
-	bygga en webbsida med HTML, CSS och JavaScript
-	använda Chart.js för att visualisera data i ett linjediagram

Projektet har gett oss förståelse för hur olika tekniker och programmeringsspråk kan samverka i ett system, från sensor och mikrokontroller till server och webbaserad visualisering.

