## Koden för linjediagrammet vi har använt i projektet

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
