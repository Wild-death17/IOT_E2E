//------------------------------------------------
const express = require('express');
const router = express.Router();
const Tree = require('../models/treeModel');
const db = require('../db/database');
//------------------------------------------------
const tree = new Tree(db)
//------------------------------------------------
router.post('/add', (req, res) => {
    try {
        const { name } = req.body
        tree.createTree(name)
        res.status(201).json({ massage: "successfully created tree" })
    } catch (error) {
        console.log(error);
        res.status(500).json({ massage: error })
    }
})
//------------------------------------------------
module.exports = router;
//------------------------------------------------