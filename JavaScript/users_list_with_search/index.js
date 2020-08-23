const combinePeopleAndInvestments = (peoples, investments) => {
  return investments.map((el) => {
    const man = peoples.find((e) => e.id === el.id);
    return { ...man, ...el };
  });
};

let combineData;

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
    combineData = combinePeopleAndInvestments(peoplesData, investmentsData);
    table(combineData);
  } catch (error) {
    console.log(error);
  }
}

const deleteUserFromTable = (id) => {
  combineData = combineData.filter((el) => el.id !== id);
  document.getElementById(id).remove();
};

const table = (data) => {
  const root = document.getElementById("users");
  data.map((item, ind) => {
    const card = cardComponent(item, ind + 1);
    root.append(card);
  });
};

const cardComponent = (user, id) => {
  const card = createEl("li", "card", id);
  const cardItem = createEl("div", "card-item");
  const deleteIcon = createDeleteIcon(id);
  const avatar = createAvatar(user.imageUrl);
  const info = infoBlock(user);

  cardItem.append(avatar);
  cardItem.append(info);

  card.append(cardItem);
  card.append(deleteIcon);
  return card;
};

const createAvatar = (imgUrl) => {
  const box = createEl("div", "image-box");
  const img = createEl("img");
  img.src = imgUrl;
  img.alt = "avatar";
  box.append(img);
  return box;
};

const infoBlock = (info) => {
  const container = createEl("div", "container");

  const nameTtile = createEl("h4");
  const name = createEl("b");
  name.textContent = `${info.name} ${info.lastname}`;
  nameTtile.textContent = "Name Surname: ";
  nameTtile.append(name);

  const age = createEl("span");
  age.textContent = `Age: ${info.age}`;

  const job = createEl("p");
  job.textContent = `Job: ${info.job}`;

  const investments = createEl("p");
  investments.textContent = `Investments: ${info.investments}$`;

  container.append(nameTtile);
  container.append(age);
  container.append(job);
  container.append(investments);

  return container;
};

const createDeleteIcon = (id) => {
  const deleteIcon = createEl("img", "delete");
  deleteIcon.src = "delete.png";
  deleteIcon.addEventListener("click", () => deleteUserFromTable(id));
  return deleteIcon;
};

const createEl = (el, className, id) => {
  let element = document.createElement(el);
  if (className) {
    element.className = className;
  }
  if (id) {
    element.id = id;
  }
  return element;
};

const submit = () => {
  //input value
  const searchValue = document.getElementById("search").value.toUpperCase();

  const ul = document.getElementById("users");
  const li = ul.getElementsByTagName("li");

  for (let i = 0; i < li.length; i++) {
    const div = li[i].getElementsByTagName("b")[0];
    const txtValue = div.textContent || div.innerText;
    const [name, surname] = txtValue.toUpperCase().split(" ");
    if (name.indexOf(searchValue) > -1 || surname.indexOf(searchValue) > -1) {
      li[i].style.display = "";
    } else {
      li[i].style.display = "none";
    }
  }
};

getData();
