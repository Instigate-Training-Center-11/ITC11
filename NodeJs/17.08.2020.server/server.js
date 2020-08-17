var http = require('http');
var url = require('url');
var users = require('./users/users.json');
var investments = require('./investments/investmentsData.json');


/*
var server = http.createServer(function(req,res){
    res.writeHead(200,{'Content-Type':'application/json; charset=utf-8'});
    res.end('hello');
});
*/

var server = new http.Server();
server.listen(3000,'127.0.0.1');
console.log("server listen port 3000");

server.on('request',function(req,res){
    var reqUrl = url.parse(req.url,true);
    const {name,age} = reqUrl.query;
    console.log(reqUrl);

    res.end(JSON.stringify(users));

    console.log(reqUrl);
    console.log(name);
})

