
## Linjediagrammet vi har använt i projektet


<img width="1507" height="768" alt="Screenshot 2025-12-10 at 12 47 08" src="https://github.com/user-attachments/assets/8f313e3c-1766-48cb-a5ff-38601354aa4a" />

## HTML och JavaScript

```HTML
<div>
  <canvas id="myChart"></canvas>
</div>

<script src="https://cdn.jsdelivr.net/npm/chart.js"></script>

<script>
  const ctx = document.getElementById('myChart');

  new Chart(ctx, {
    type: 'line',
    data: {
      labels: ['Måndag 5/1', 'Tisdag 6/1', 'Onsdag 7/1', 'Torsdag 8/1', 'Fredag 9/1', 'Lördag 10/1', 'Söndag 11/1'],
      datasets: [{
        label: 'Soil Moisture (%)',
        data: [12, 100, 3, 5, 2, 3, 0],
        borderWidth: 1
      }]
    },
    options: {
      scales: {
        y: {
          beginAtZero: true
        }
      }
    }
  });
</script>

```

## Förklaring av koden

```js
  <div> 

  <canvas id="myChart"></canvas> 

</div> 

```
Vi skapar ett Canvas med id:et “myChart”. 

```js

 <script src="https://cdn.jsdelivr.net/npm/chart.js"></script> 

 <script>

```

Länkar till JavaScript-biblioteket för vår chart.

```js

  const ctx = document.getElementById('myChart');

```
Hämtar canvas rutan “ myChart”. 

```js

 new Chart(ctx, {

```
Initierar ett nytt diagram i ett canvas-element. Variabeln ctx är normalt en referens till en HTML-canvas (t.ex. document.getElementById('myChart')). 

```js

  type: 'line', 

```
Vi ändrade vårt diagram till ett linjediagram med “line”.

```js

data: {

   labels: ['Måndag 5/1', 'Tisdag 6/1', 'Onsdag 7/1', 'Torsdag 8/1', 'Fredag 9/1', 'Lördag 10/1', 'Söndag 11/1'],

```
Definierar de kategorier som visas längs x-axeln. I detta fall är det veckodagarna med datum: Måndag 5/1 → Söndag 11/1.

```js

    datasets: [{

```
Här börjar vi skriva vad digramet ska rita siffror. 

```js

label: 'Soil Moisture (%)',

```
Namnet på linjediagrammet.

```js

data: [12, 100, 3, 5, 2, 3, 0],

```
Detta är själva siffrona som ska ritas. Siffrona ritas i samma ordning som labels. 

```js

 borderWidth: 1

```
En egenskap i dataset som säger hur tjockleken på linjen, som i det här fallet är 1 pixel (högre tal = tjockare linje). 

```js

options: 

```
Är objekt som styr hur programmet ser ut.  

```js

{scales: {

```
Här bestämmer vi hur X och Y-axlarna ska fungera.
