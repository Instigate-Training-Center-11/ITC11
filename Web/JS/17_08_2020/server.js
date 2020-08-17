const http = require("http");
const server = http.createServer((req, res) => {
    let name = require("url").parse(req.url, true).query.name;
    let age = require("url").parse(req.url, true).query.age;
    let users = require("./peoples.json");
    let investments = require("./investments.json");
    let path = JSON.stringify(require("url").parse(req.url, true).pathname);
    if(path === "\"/users\"") {
        if (name === undefined && age !== undefined) {
            res.end(JSON.stringify(users.peoplesData.find(item => item.age == age)));
        } else  if (age === undefined && name !== undefined) {
            res.end(JSON.stringify(users.peoplesData.find(item => item.name === name)));
        } else if(age !== undefined && name !== undefined) {
            res.end(JSON.stringify(users.peoplesData.find(item => item.name === name && item.age == age)));
        }else {
            res.end(JSON.stringify(users.peoplesData));
        }
    }
    if(path === "\"/investments\"") {
        res.end(JSON.stringify(investments.investmentsData));
    }
    }
).listen(8082);
