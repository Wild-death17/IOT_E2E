const mysql = require('mysql2');

const HOST = process.env.HOST;
const USER = process.env.USER;
const PASSWORD = process.env.PASSWORD;
const Database = process.env.DATABASE;

const pool = mysql.createPool({
    host: HOST,
    user: USER,
    password: PASSWORD,
    database: Database
});

module.exports = {
    pool: pool
};