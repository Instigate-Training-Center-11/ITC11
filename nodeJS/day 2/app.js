const { connection } = require('./models/mysql');
const express = require("express");
const router = require('./routers/router');
var cors = require('cors');
const app = express();

app.use(cors());
app.use('/', router);
app.use((req, res) => {
    res.set({
        "Access-Control-Allow-Origin": "*"
    })
})

app.listen(3000);