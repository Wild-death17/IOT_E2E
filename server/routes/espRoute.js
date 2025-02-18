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
//------------------------------------------------
module.exports = router;
//------------------------------------------------