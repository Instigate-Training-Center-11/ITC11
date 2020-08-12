var urls = [
    'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Anna_Harutyunyan/web/styles/Promise/investments.json',
    'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Anna_Harutyunyan/web/styles/Promise/users.json'
];

var p1 = fetch(urls[0])
    .then((response) => {
        return response.json();
    })

var p2 = fetch(urls[1])
    .then((response) => {
        return response.json();
    })

Promise.all([p1, p2])
    .then(res => {
        console.log('Two response', res);
        return res;
    })
    .then(res => {
        var arr = [];
        for (var i in res[0].investmentsData) {
            if (res[0].investmentsData[i].investments > 500) {
                if (res[0].investmentsData[i].id == res[1].peoplesData[i].id) {
                    res[0].investmentsData[i].name = res[1].peoplesData[i].name;
                    res[0].investmentsData[i].age = res[1].peoplesData[i].age;
                    res[0].investmentsData[i].job = res[1].peoplesData[i].job;
                }
                arr.push(res[0].investmentsData[i]);
            }
        }
        console.log('Merge two data', arr);
        return arr;
    })
    .then((arr) => {
        var investments = [];

        for (var i in arr) {
            investments.push(arr[i].investments)
        };

        var sortedInvestments = investments.sort(function(a, b) {
            if(a > b) return -1;
            if(a < b) return 1;
            return 0;
        });

        while (sortedInvestments.length > 3) {
            sortedInvestments.pop();
        }

        var maxThree = arr.filter((inv) => {
            if (inv.investments >= sortedInvestments[sortedInvestments.length - 1]) {
                return inv.investments;
            }
        })
        console.log('Three max investments', maxThree); 
    })
    .catch(e => console.log(e))


Promise.all([p1, p2])
    .then(res => {
        var entries = [];
        for(var i in res[0].investmentsData) {
            res[0].investmentsData[i].name = res[1].peoplesData[i].name;
            res[0].investmentsData[i].age = res[1].peoplesData[i].age;
            res[0].investmentsData[i].job = res[1].peoplesData[i].job;
        }

        res[0].investmentsData.forEach(data => {
            var entry = [data, [data.name, data.investments]];
            entries.push(entry);
        });
        var weakMap = new WeakMap(entries);
        console.log('Create weakMap', weakMap);
    })
    .catch(e => console.log(e))