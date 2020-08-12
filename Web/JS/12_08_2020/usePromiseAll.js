     let pA = fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Meruzhan_Unanyan/Web/JS/12_08_2020/investments.json')
          .then((response) => {
              return response.text();
          }).then((data) => {
          console.log(data);
      });
      let pB = fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Meruzhan_Unanyan/Web/JS/12_08_2020/peoples.json')
          .then((response) => {
              return response.text();
          }).then((data) => {
              console.log(data);
       });
      promises = Promise.all([pA, pB]);
      console.log(promises);
