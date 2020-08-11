const company = {
    departament1: {
      room1: [
        {name: 'employer1', salary: 10},
        {name: 'employer2', salary: 10},
        {name: 'employer3', salary: 10},
      ],
      room2: [
        {name: 'employer1', salary: 10},
        {name: 'employer2', salary: 10},
        {name: 'employer3', salary: 10},
      ],
    },
    departament2: {
      room1: [
        {name: 'employer1', salary: 10},
        {name: 'employer2', salary: 10},
        {name: 'employer3', salary: 10},
      ],
      room2: [
        {name: 'employer1', salary: 10},
        {name: 'employer2', salary: 10},
        {name: 'employer3', salary:  {salary: 555}},
      ],
    },
  };

function sumSalaries(department) {
  if (Array.isArray(department)) { // случай (1)
    return department.reduce((prev, current) => prev + current.salary, 0); // сумма элементов массива
  } else { // случай (2)
    let sum = 0;
    for (let subdep of Object.values(department)) {
      sum += sumSalaries(subdep); // рекурсивно вызывается для подотделов, суммируя результаты
    }
    return sum;
  }
}

console.log(sumSalaries(company));

