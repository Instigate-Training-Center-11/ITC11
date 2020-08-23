const getInvestitions = (data, investments) => {
  return data.filter((el) => el.investments >= investments);
};

const combinePeopleAndInvestments = (peoples, investments) => {
  return investments.map((el) => {
    const man = peoples.find((e) => e.id === el.id);
    return { ...man, ...el };
  });
};

const topThreeInvestors = (data) => {
  return data
    .sort((a, b) => b.investments - a.investments)
    .slice(0, 3)
    .map((el) => el.name);
};

const toEntries = (data) => {
  return data.map((el) => Object.entries(el));
};

const toWeakMap = (data) => {
  const weakMap = new WeakMap();
  return data.map((el, ind) => weakMap.set(el, ind));
};

async function getData() {
  const urls = [
    "https://raw.githubusercontent.com/ani98-k/test/master/test.json",
    "https://raw.githubusercontent.com/ani98-k/test/master/test1.json",
  ];
  try {
    const requests = urls.map((url) => fetch(url));
    let [res1, res2] = await Promise.all([requests[0], requests[1]]);
    const { investmentsData } = await res1.json();
    const { peoplesData } = await res2.json();
    const combineData = combinePeopleAndInvestments(
      peoplesData,
      investmentsData
    );
    const investments_less_than_80 = getInvestitions(investmentsData, 80);
    const top_3_investors = topThreeInvestors(combineData);
    const entries = toEntries(combineData);
    const weakMap = toWeakMap(combineData);
  } catch (error) {
    console.log(error);
  }
}

getData();
