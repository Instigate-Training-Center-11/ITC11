let http = require('http');
let url = require('url');
let people = require('./people.json');
let investments = require('./investments.json');

let server = new http.Server();
server.listen(3001, '192.168.1.5');

server.on('request', function(req, res) {
    let reqUrl = url.parse(req.url, true);
    const {name, age} = reqUrl.query;
    const {inv} = reqUrl.query;

    const resPeople = people.peoplesData.find(item => item.name === name && item.age === Number(age));
    const resInvestments = investments.investmentsData.find(item => item.investments === Number(inv));

    if (resPeople && reqUrl.path === `/people/?name=${name}&&age=${age}`) {
        res.end(JSON.stringify(resPeople));
    } else if (reqUrl.path === `/people/`) {
        res.end(JSON.stringify(people.peoplesData));
    } else if (resInvestments && reqUrl.path === `/investments/?inv=${inv}`) {
        res.end(JSON.stringify(resInvestments));
    } else if (reqUrl.path === `/investments/`) {
        res.end(JSON.stringify(investments.investmentsData));
    } else {
        res.statusCode = 404;
        res.end('Not Found');
    }
})