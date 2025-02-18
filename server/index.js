// npm install express mysql2 dotenv morgan cors

const express = require('express');
const dotenv = require('dotenv');
const morgan = require('morgan');
const cors = require('cors');

//------------------------------------------------

const app = express();
const port = 3214;

app.use(express.json());
app.use(cors());
app.use(morgan('dev'));
dotenv.config();

//------------------------------------------------

const esp = require('./routes/espRoute')
app.use('/esp', esp);

//------------------------------------------------

app.listen(port, () => {
    console.log(`Now listening on port ${port}`);
    console.log(`http://localhost:${port}`);
    console.log(__dirname);
});
