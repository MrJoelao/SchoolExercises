// Variabili per memorizzare i valori e l'operatore
let displayValue = '';
let firstNumber = '';
let operator = '';
let newNumber = false;

// Funzione per aggiungere numeri al display
function appendValue(value) {
    // Se stiamo iniziando un nuovo numero, pulisce il display
    if (newNumber) {
        displayValue = '';
        newNumber = false;
    }
    
    // Controlla che non ci siano più punti decimali
    if (value === '.' && displayValue.includes('.')) {
        return;
    }
    
    displayValue += value;
    document.getElementById('display').value = displayValue;
}

// Funzione per gestire gli operatori
function appendOperator(op) {
    // Gestisce il pulsante clear
    if (op === 'clear') {
        displayValue = '';
        firstNumber = '';
        operator = '';
        document.getElementById('display').value = '';
        return;
    }
    
    // Salva il primo numero e l'operatore
    firstNumber = displayValue;
    operator = op;
    newNumber = true;
}

// Funzione per calcolare il risultato
function calculateResult() {
    if (firstNumber === '' || displayValue === '') {
        return;
    }
    
    let result = 0;
    let num1 = parseFloat(firstNumber);
    let num2 = parseFloat(displayValue);
    
    // Esegue l'operazione in base all'operatore
    switch(operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 === 0) {
                result = 'Error';
            } else {
                result = num1 / num2;
            }
            break;
    }
    
    // Mostra il risultato e resetta le variabili
    displayValue = result.toString();
    document.getElementById('display').value = displayValue;
    firstNumber = '';
    operator = '';
}
