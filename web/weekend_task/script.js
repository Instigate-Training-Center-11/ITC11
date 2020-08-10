function convUsa() {
    var val = document.getElementById('dram').value;
    var res = val / 450;
    document.getElementById('usa').innerHTML = res;
}
function convEuro() {
    var val = document.getElementById('dram').value;
    var res = val / 550;
    document.getElementById('euro').innerHTML = res;
}
function convPound() {
    var val = document.getElementById('dram').value;
    var res = val / 600;
    document.getElementById('pound').innerHTML = res;
}