function setCookie(cname, cvalue, exhours = 365 * 24) {
  let d = new Date();
  d.setTime(d.getTime() + exhours * 60 * 60 * 1000);
  const expires = "expires=" + d.toUTCString();
  document.cookie = cname + "=" + cvalue + ";" + expires + ";path=/";
}

const login = async () => {
  const email = document.getElementById("email").value;
  const password = document.getElementById("password").value;
  try {
    let data = await fetch("http://localhost:3002/signin", {
      method: "POST",
      headers: {
        Accept: "application/json",
        "Content-Type": "application/json",
      },
      body: JSON.stringify({ password, email }),
    });
    if (data.ok) {
      const response = await data.json();
      localStorage.setItem("token", response.accessToken);
      console.log(response);
    }
  } catch (error) {
    console.log(error);
  }
};
