var users = require('./user.json');
var investment = require('./investment.json');

var http = require('http');
var url = require('url');
var server = new http.Server();

server.listen(3005, '192.168.5.2');

server.on('request', function (req, res) {
    var reqUrl = url.parse(req.url, true);
    if (reqUrl.pathname == "/user") {
        const { name = 0, age = 0 } = reqUrl.query;
        const resData = users.data.filter(element => {
            if (name == 0) { return element }
            return element.name == name}).filter(ele => {
                if (age == 0) {
                    return ele;
                } else {
                    return age == ele.age;
                }
            })
        if (resData) {
            res.end(JSON.stringify(resData));
        } else {
            res.statusCode = 404;
            res.end("not found2");
        }
    } else if (reqUrl.pathname == "/investment") {
        res.end(JSON.stringify(investment.investmentsData))
    } else {
        res.statusCode = 404;
        res.end("not found1");
    }


})