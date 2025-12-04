# Grupplogg & Tidsplan 
Fredag 5/12 - Plan för sensor och microcontroller samt montage klart. Bibliotek för sensor hittat och tester med sensor inledd. Presentation klar

Onsdag 10/12 - Skiss på möjlig visualisering klart enligt tidigare given lista på visualiseringar från Chart.JS https://www.chartjs.org

Fredag 12/12 - Presentation av läget just nu

## Loggbok
Tisdagen den 2/12 har vi monterat ihop fuktsensorn och fick den att funka i Arduino. Sen skrev vi koden och matade in värdena i "Dry" och "Wet"

## Projekt: Fuktsensor
Vi är en grupp studenter på MDU som utvecklar en fuktsensor för hemmabruk. Projektet sker som gruppuppgift i kursen ITE130.

## Syfte
Vår intention är att skapa en fuktsensor för användning i jorden som läser av hur våt eller torr den är. Datan ska sedan visualiseras grafiskt för användaren.

## Användare och kontext
Målgruppen är dem som äger växter och vill veta när de behöver vattnas. Sensorn underlättar ansvaret för användaren genom att hålla koll på fukten i jorden genom att känna av hur våt eller torr den är.

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Demo 02 - onclick </title>
    <script>
        function makeRed() {
            document.body.style.backgroundColor = 'red';
            return undefined; //this can be left out
        }
    </script>
</head>

<body>
    <a href="index.html">
        <<< Back</a>
            <hr>
            <h1>Rubrik</h1>
            <button ondblclick="makeRed()">Make Red</button>
            <p id="p1"></p>
</body>

</html>
