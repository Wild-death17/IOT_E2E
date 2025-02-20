//------------------------------------------------
const express = require('express');
const fs = require('fs');
const router = express.Router();
//------------------------------------------------
router.get('/', (req, res) => {
    const { temp, moisture } = req.query;
})
router.get('/state', (req, res) => {
    const data = JSON.parse(fs.readFileSync("state.json", "utf8"))
    res.send(data.state);
})
router.get('/dataMode', (req, res) => {
    const { state } = req.query;
    const data = JSON.parse(fs.readFileSync("state.json", "utf8"))
    res.json(data[state])
})
router.get('/currentTime', (req, res) => {
    const now = new Date();
    const formattedTime = now.toISOString().slice(0, 19).replace("T", " ");
    res.send(formattedTime.slice(11));
})
//------------------------------------------------
module.exports = router;
//------------------------------------------------