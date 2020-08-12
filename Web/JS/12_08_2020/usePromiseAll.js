      let pA = fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Meruzhan_Unanyan/Web/JS/12_08_2020/investments.json')
          .then((response) => response.text());
      let pB = fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Meruzhan_Unanyan/Web/JS/12_08_2020/peoples.json')
          .then((response) => response.text());
      promises = Promise.all(([pA, pB]));
      promises.then((p) => p.toString()).then(p => console.log(p));
