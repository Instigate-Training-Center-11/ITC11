var http = require('http');
var url = require('url');
var users = require('./users/users.json');
var investments = require('./investments/investmentsData.json');
var bindAllData = require('./functions');

var server = new http.Server();
console.log("server listen port 3000");

server.on('request',function(req,res){
    res.writeHead(200,{'Content-Type':'application/json; charset=utf-8'})
    var reqUrl = url.parse(req.url,true);
    const {name,age} = reqUrl.query;
    console.log(reqUrl.pathname);

    let arrayPeoplesData = users.peoplesData;
    let arrayInvestmentsData = investments.investmentsData;
    if (reqUrl.pathname === '/') {
        res.end(JSON.stringify(bindAllData(arrayInvestmentsData,arrayPeoplesData)));
    } else if(reqUrl.pathname === '/users'){
        if (name) {
            let result = bindAllData(arrayInvestmentsData,arrayPeoplesData).filter(elem => elem.name === name);
            res.end(JSON.stringify(result));
        } else if(age){
            let result = bindAllData(arrayInvestmentsData,arrayPeoplesData).filter(elem => elem.age == age);
            res.end(JSON.stringify(result));
        } else {
            res.end(JSON.stringify(bindAllData(arrayInvestmentsData,arrayPeoplesData)));
        }
        res.end(JSON.stringify(users));
    } else if(reqUrl.pathname === '/investments') {
        res.end(JSON.stringify(investments));
    } else{
        res.statusCode = 404;
        res.end('Page note found 404');
    }

});

server.listen(3000,'127.0.0.1');
