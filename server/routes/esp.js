const express = require('express');
const fs = require('fs');
const router = express.Router();

router.get('/', (req, res) => {
    let { temp, light, moisture } = req.query;
})
router.get('/state', (req, res) => {
    let data = JSON.parse(fs.readFileSync("state.json", "utf8"))
    res.send(data.state);
})
router.get('/dataMode', (req, res) => {
})
module.exports = router;