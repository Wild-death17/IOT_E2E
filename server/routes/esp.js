const express = require('express');
const router = express.Router();
const fs = require('fs');

router.get('/', (req, res) => {

})
router.get('/state', (req, res) => {
    let data = JSON.parse(fs.readFileSync("state.json", "utf8"))
    res.send(data.state);
})
router.get('/dataMode', (req, res) => {
})
module.exports = router;
