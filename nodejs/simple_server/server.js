let http = require('http');
let peoplesJson = require('./peoples.json');
let investmentsJson = require('./investments.json')

let url = require('url');

let server = new http.Server();
server.listen(3013, '192.168.1.9');

server.on('request', function (req, res) {
    let parseUrl = url.parse(req.url, true);
    const {name, age} = parseUrl.query;
    const {investments} = parseUrl.query;

    const resPeoples = peoplesJson.peoplesData.find(i => i.name === name && i.age.toString() === age);
    const resInvestments = investmentsJson.investmentsData.find(i => i.investments.toString() === investments);

    if (resPeoples && parseUrl.path === `/peoples/?name=${name}&&age=${age}`) {
        res.end(JSON.stringify(resPeoples));
    } else if (resInvestments && parseUrl.path === `/investments/?investments=${investments}`) {
        res.end(JSON.stringify(resInvestments));
    } else if (parseUrl.path === `/peoples/`) {
        res.end(JSON.stringify(peoplesJson.peoplesData));
    } else if (parseUrl.path === `/investments/`) {
        res.end(JSON.stringify(investmentsJson.investmentsData));
    } else {
        res.statusCode = 404;
        res.end('Not found');
    }
})