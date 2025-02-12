//------------------------------------------------
const express = require('express');
const fs = require('fs');
const router = express.Router();
//------------------------------------------------
router.get('/', (req, res) => {
    let { temp, moisture } = req.query;
})
router.get('/state', (req, res) => {
    let data = JSON.parse(fs.readFileSync("state.json", "utf8"))
    res.send(data.state);
})
router.get('/dataMode', (req, res) => {
    let { state } = req.query;
    let data = JSON.parse(fs.readFileSync("state.json", "utf8"))
    res.json(data[state])
})
//------------------------------------------------
module.exports = router;
//------------------------------------------------