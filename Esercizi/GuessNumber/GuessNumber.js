var randomNum = Math.floor(Math.random() * 100) + 1;
var tentativi = 0;

function showResult() {
    var guess = parseInt(document.getElementById('guessInput').value);
    var result = document.getElementById('result');
    var counter = document.getElementById('counter');
    
    if (isNaN(guess) || guess < 1 || guess > 100) {
        result.innerHTML = "Per favore, inserisci un numero tra 1 e 100!";
        return;
    }

    tentativi++;
    counter.innerHTML = "Tentativi: " + tentativi;

    if (guess == randomNum) {
        result.innerHTML = "🎉 Hai indovinato in " + tentativi + " tentativi!";
        result.className = "vittoria";
        document.getElementById('guessButton').disabled = true;
    } else if (guess < randomNum) {
        result.innerHTML = "↗️ Il numero è più alto";
    } else {
        result.innerHTML = "↙️ Il numero è più basso";
    }
}

document.getElementById('guessInput').addEventListener('keyup', function(event) {
    if (event.key === 'Enter') {
        showResult();
    }
});
