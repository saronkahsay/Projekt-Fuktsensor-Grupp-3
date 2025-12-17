const express = require('express');
const { Pool } = require('pg');
const cors = require('cors');

const app = express();
app.use(cors());

const pool = new Pool({
  host: '77.42.37.48',
  port: 5432,
  user: 'postgres',
  password: 'PostPost123',
  database: 'postgres'
});

app.get('/api/moisture', async (req, res) => {
  try {
    const result = await pool.query(`
      SELECT value, recorded_at
      FROM humidity
      ORDER BY recorded_at DESC
      
    `);

    res.json(result.rows);
  } catch (err) {
    console.error(err);
    res.status(500).send('Database error');
  }
});

app.listen(3000, () => {
  console.log('API running on http://localhost:3000');
});
