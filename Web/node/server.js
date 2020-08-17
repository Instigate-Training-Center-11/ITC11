var data = require('./firstfile.json');
var http = require('http');
var url = require('url');
var server = new http.Server();
server.listen(8080, '93.185.45.82');
server.on('request', function (req, res) {
    console.log(req.headers);
    var reqUrl = url.parse(req.url, true);
    console.log(reqUrl.query);
    const { name, age } = reqURL.query;
    const resData = data.peoplesData.find(item => item.name === name && item.age === parseInt(age));
    if (resData) {
        res.end(JSON.stringify(resData))
    } else {
        res.statusCode = 404;
        res.end('not found');
    }
})

