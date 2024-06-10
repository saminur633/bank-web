let balance = 0.00;

function deposit() {
  balance += 100.00;
  document.getElementById('balance').textContent = `$${balance.toFixed(2)}`;
}
