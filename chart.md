
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
</script> ```

## Förklaring av koden


