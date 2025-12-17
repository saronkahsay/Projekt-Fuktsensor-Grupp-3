# *Vecstis* 
Vi har byggt en fuktsensor som ska mäta jordfuktigheten. 

# Projektbeskrivning

Många växtägare upplever att det är svårt att veta när och hur mycket de ska vattna sina växter. Det finns osäkerhet kring växtens faktiska behov, och detta leder ofta till övervattning eller undervattning. Konsekvenserna kan vara gula blad, skadade rötter eller i värsta fall att växten dör, vilket skapar oro och ibland frustation.

Vi ville därför utveckla ett verktyg som på ett enkelt sätt mäter jordens fuktighet och visualiserar resultat. Genom att ge användarna realtidsdata om jordens tillstånd kan de fatta mer informerande beslut om vattning. Målet är att göra växtskötsel mer trygg, lättillgängligt och lärorikt, samtidigt som växterna får bättre förutsättningar att må bra och växa. 

# För att utföra projeket har vi använt: 

- **Plusivo Wireless Super Starter Kit**

- **Soil Humidity Capacitive Sensor** 

- **Visual Studio Code**

- **Arduino IDE**

- **MQTT-server** 

# Hur systemet funkar 
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


# Sensor & Kod 
Vi använder en ***Capacitive Soil Humidity Sensor*** för att mäta jordens fuktighet.
Sensorn ger ett **analogt värde** som ändras beroende på hur torr eller fuktig jorden är.

Mikrokontrollern som används är **ESP8266**.
Den ansvarar för att:
- läsa av sensorvärdet
- bearbeta datan
- skicka värdena vidare via WiFi

ESP8266 programmeras i **Arduino IDE**.
Koden:
-	läser sensorvärdet
-	använder anpassade värden för torr och blöt jord
-	omvandlar värdet till procent

### Var finns koden?
All kod finns i projektets **GitHub-repository**. Där hittar man:
- Arduino-kod
- Kod för linjediagrammet
- HTML, CSS och JavaScript för webbsidan


# Visualisering 
*Linjediagrammet gör det enkelt att*:
- se förändringar i fuktighet över tid
- se skillnad före och efter vattning
- förstå hur växtens fuktighet beter sig

**Live-data och färger**

Diagrammet uppdateras löpande, vilket gör att användaren kan se aktuell fuktighet i **realtid**.
Tydliga färger används för att göra diagrammet lättläst, vi använder oss av intuitiva färger så som röd, gul & grön för att tala om för användaren om jordens fuktighet. 


# Hur utför man detta projekt

## ESP8266 och Soil Humidity Sensor

Sensorn soil humidity sensor mäter jordens fuktighet. Sensorn skickar analogt värde som motsvarar fuktighet till mikrokontrollern. 
ESP8266 är mikrokontrollern som styr sensorn, den skickar data via WiFi. 
Sensorn är kopplat till en ESP8266, den läser av värdet från sensorn och skickar data via WiFi. Det är grunden för hela systemet eftersom det är här mätningen sker. 

## Programmerade microcontrollern i Arduino IDE

Arduino IDE används för att programmera mikrokontrollern. Koden bearbeta de analoga sensorvärdena och omvandlar dem till procentuella fuktvärden. Koden hanterar WiFi-kommunikationen vilket möjliggör att mätdata skickas vidare till webbgränssnittet för visualisering. 

## Linjediagram med hjälp av chart.js 

För att visualisera fuktvärdena används ett linjediagram skapat med **Chart.js**, ett JavaScript-bibliotek för diagram i webbläsare.

Diagrammet visas på en HTML-sida och uppdateras med data som skickas från mikrokontrollern via servern.
Varje mätning av jordfuktighet visas som en punkt i diagrammet.
- **Y-axeln** visar fuktighet i procent (0–100 %)
- **X-axeln** visar tid


## Designade prototyp av appen i VS Code
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

## MQTT-server och databas

### Sätta upp servrar för humidity sensor


<a id="orgd879e01"></a>

### Sätta upp en server

Först behövde vi en server/dator att installera MQTT och databasen på.
Vi valde att skapa ett konto på [Hetzner](https://www.hetzner.com/), som verkade vara en av de populäraste
leverantörna av VPS-tjänster (Virtual Private Server).

Vi skapade ett konto och beställde den billigaste servern de hade (CX23).
Det var lätt att få upp servern, då det bara var att klicka i ett grafiskt gränssnitt.
Till slut hade vi en Linux-server med en IP-address så att den går att nå från internet.


<a id="orgf8262bf"></a>

### Sätta upp MQTT-server

Härnäst behövde vi en MQTT-server.
Vi hade hört att en av de populäraste MQTT-servrarna [Eclipse Mosuitto](https://mosquitto.org/) så vi valde att använda det.
För att installera mosquitto hörde vi att ett lätt sätt att göra det på var genom att använda
"[Docker-containrar](https://www.docker.com/resources/what-container/)" och att [podman](https://podman.io/) var ett enkelt verktyg för att göra detta.

Vi installerade podman på vår server:

    sudo zypper install podman

Sen hittade vi en "container" på [Docker hub](https://hub.docker.com/) för mosquitto: <https://hub.docker.com/_/eclipse-mosquitto>

Enligt instruktionerna startade vi en mosquitto-container med följande kommando:

    podman run -d -p 1883:1883 eclipse-mosquitto

Däremot så verkade inte den fungera på första försöket.
Vi frågade då ChatGPT vad som var fel, och fick som svar att mosquitto behöver en konfigurationsfil
för att fungera som vi ville.
Nämligen behövde vi göra så att vi kunde ansluta till mosquitto som "anonym användare", samt att
om vi ville läsa MQTT data från JavaScript på vår hemsida behvöde mosquitto lyssna på en "[WebSocket](https://en.wikipedia.org/wiki/WebSocket)"-port.

Detta fick vi att fungera med följande konfigurationsfil:

    # ================================
    #  Mosquitto MQTT Configuration
    # ================================
    
    # Allow anonymous clients
    allow_anonymous true
    
    # ----------------
    # MQTT (TCP) Listener
    # ----------------
    listener 1883
    protocol mqtt
    
    # ----------------
    # WebSocket Listener
    # ----------------
    listener 9001
    protocol websockets

Sedan behövde vi starta mosquitto med ett nytt kommando:

    podman run -d -v /opt/mosquitto/:/mosquitto/config -p 1883:1883 -p 9001:9001 eclipse-mosquitto

Efter det kunde vår ESP8622 ansluta till IP-addressen på vår server på port 1883 och skicka data till mosquitto.


<a id="orgbd14719"></a>

## Sätta upp databas

För att spara data under längre tid behövde vi också en databas. Detta eftersom MQTT inte självt sparar någon data.

Enligt internet var en populär och relativt lätt databas [PostgreSQL](https://www.postgresql.org/) så vi valde att köra den.
Den var tydligen också lätt att köra med podman, vilket gjorde det lättare för oss.

Vi startade PostgreSQL med följande kommando:

    podman run --name postgres -p 5432:5432 -e POSTGRES_PASSWORD=<lösenord> -d postgres

Vi frågade sen ChatGPT igen ifall vi behövde göra något mer och vi fick ett enkelt "SQL"-kommando att köra för att
skapa upp en tabell i vår databas.

Först loggade vi in i databasen:

    podman exec -it postgres psql -U postgres

Sedan körde vi SQL-kommandot vi fick av ChatGPT:

    CREATE TABLE humidity (
      id BIGSERIAL PRIMARY KEY,
      value INTEGER NOT NULL,
      recorded_at TIMESTAMPTZ NOT NULL DEFAULT now()
    );

För att testa ifall det fungerade körde vi följande SQL-kommando:

    SELECT * FROM humidity;


Nu såg det ut som att vi hade en fungerande databas med en tabell som vi vill ha den.


<a id="orga26d238"></a>

### Spara data från MQTT till databas

Det sista steget var att få all data från MQTT till PostgreSQL-databasen.
För att göra det använde vi följade program: [mqtt-to-pg](https://git.sr.ht/~gunnargrop/mqtt-to-pg).

Vi startade den med podman på vår server:

    podman run -d \
           -e PG_HOST="host.containers.internal" \
           -e PG_PORT="5432" \
           -e PG_USERNAME="postgres" \
           -e PG_PASSWORD="<lösenord>" \
           -e PG_DATABASE="postgres" \
           -e MQTT_HOST="host.containers.internal" \
           -e MQTT_PORT="1883" \
           -e MQTT_TOPIC="grupp3/soil/humidity" \
           gunnargrop/mqtt-to-pg



# Vad har vi lärt oss?
-	hur en sensor kan användas för att samla in data 
- hur en mikrokontroll (ESP8266) kan läsa, bearbeta och skicka data vidare via WiFi
 - hur man programmerar en mikrokontroll i Arduino IDE med C++
-	hur rådata kan omvandlas till procent för att bli lättare att förstå
Vi har även lärt oss att:
-	använda Visual Studio Code för att utveckla webbdelen av projektet
-	bygga en webbsida med HTML, CSS och JavaScript
-	använda Chart.js för att visualisera data i ett linjediagram

Projektet har gett oss förståelse för hur olika tekniker och programmeringsspråk kan samverka i ett system, från sensor och mikrokontroller till server och webbaserad visualisering.

