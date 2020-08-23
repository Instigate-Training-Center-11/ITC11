var http = require("http");
var url = require("url");

var data = require("./users.json");
var investment = require("./investments.json");

var server = http.createServer();

server.listen("3002", "localhost");

server.on("request", function (req, res) {
  var reqUrl = url.parse(req.url, true);
  res.setHeader("Access-Control-Allow-Origin", "*");
  res.setHeader("Access-Control-Allow-Headers", "origin, content-type, accept");
  res.setHeader("Content-Type", "application/json");

  if (reqUrl.pathname === "/users") {
    const { name, age } = reqUrl.query;
    let response = data.peoplesData.map((el) => {
      const investmentItem = investment.investmentsData.find(
        (e) => e.id === el.id
      );
      return { ...investmentItem, ...el };
    });

    if (name && age) {
      if (age <= 0) {
        res.statusCode = 400;
        res.end("Invalid age");
      }
      response = response.filter(
        (el) =>
          el.name.toUpperCase().indexOf(name.toUpperCase()) > -1 &&
          el.age === +age
      );
    }

    res.end(JSON.stringify({ data: response }, null, 2));
  } else if (reqUrl.pathname === "/investments") {
    res.end(JSON.stringify({ data: investment }, null, 2));
  }
  res.statusCode = 404;
  res.end("Not found");
});
