const express = require('express');

const router = express.Router();

router.get('/', (req, res) => {
    let { temp, light, moisture } = req.query;
})
module.exports = router;